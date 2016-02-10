--- modules/json/c/json.y.orig	2016-02-04 05:14:14 UTC
+++ modules/json/c/json.y
@@ -5,11 +5,15 @@
 
 %{
 #include <tcl.h>
+#include <errno.h>
 #include <ctype.h>
 #include <math.h>
 #include <string.h>
 #include <stdlib.h>
 #include <assert.h>
+#if TCL_MAJOR_VERSION > 8 || TCL_MINOR_VERSION > 4
+#define USE_DICT
+#endif
 
 #include <json_y.h>
 
@@ -17,10 +21,12 @@
 #define TOKEN1(tok)  TRACE (("TOKEN  %s (%s)\n", tok, Tcl_GetString(context->obj)))
 #define REDUCE(rule) TRACE (("REDUCE %s\n", rule))
 
-#define TRUE_O  (Tcl_NewStringObj("true", 4))
-#define FALSE_O (Tcl_NewStringObj("false", 5))
-#define NULL_O  (Tcl_NewStringObj("null", 4))
+#define TRUE_O  staticobj(TRUEO)
+#define FALSE_O staticobj(FALSEO)
+#define NULL_O  staticobj(NULLO)
 
+enum constants { FALSEO, TRUEO, NULLO, NUMCONSTANTS };
+static Tcl_Obj * staticobj(enum constants);
 static void jsonerror(struct context *, const char *);
 static int  jsonlexp(struct context *context);
 
@@ -107,14 +113,23 @@ values	: value
 
 members	: member
 	{
+#ifdef USE_DICT
+		$$ = Tcl_NewDictObj();
+		Tcl_DictObjPut(NULL, $$, $1.key, $1.val);
+#else
 	        $$ = Tcl_NewListObj(0, NULL);
 		Tcl_ListObjAppendElement(NULL, $$, $1.key);
 		Tcl_ListObjAppendElement(NULL, $$, $1.val);
+#endif
 	}
 	| members ',' member
 	{
+#ifdef USE_DICT
+		Tcl_DictObjPut(NULL, $1, $3.key, $3.val);
+#else
 		Tcl_ListObjAppendElement(NULL, $1, $3.key);
 		Tcl_ListObjAppendElement(NULL, $1, $3.val);
+#endif
 		$$ = $1;
 	}
 	;
@@ -180,6 +195,65 @@ jsonskip(struct context *context)
   }
 }
 
+/*
+ * JSON has 3 string-literals: "null", "true", and "false". Instead of
+ * creating a NEW Tcl-object EACH TIME such literal is encountered, we
+ * return the reference to the first such object created (and bump its
+ * reference-count to prevent memory errors).
+ */
+Tcl_Obj *
+staticobj(enum constants constant)
+{
+    static Tcl_Obj   *objects[NUMCONSTANTS];
+    Tcl_Obj         **p;
+
+    assert(constant >= 0 && constant < NUMCONSTANTS);
+    p = objects + constant;
+    if (*p == NULL) {
+	/*
+	 * This is the first time we were asked for an object for
+	 * this constant. Create it to the best of our ability.
+	 *
+	 * Using the trick below, rather than the usual
+	 * Tcl_NewStringObj(), avoids creation of a COPY
+	 * of the string "null". Such copying is a waste,
+	 * if the object itself is never to be freed...
+	 */
+	*p = Tcl_NewObj();
+	switch (constant) {
+	case NULLO:
+	    (*p)->bytes = (void *)"null";
+	    (*p)->length = 4;
+	    break;
+	case TRUEO:
+	    /*
+	     * A boolean-object's default string representation is
+	     * "0" or "1", but we'd like the fancier "false" and
+	     * "true" for our objects to better match the
+	     * expectations of JSON-users.
+	     */
+	    Tcl_SetBooleanObj(*p, 1);
+	    (*p)->bytes = (void *)"true";
+	    (*p)->length = 4;
+	    break;
+	case FALSEO:
+	    Tcl_SetBooleanObj(*p, 0);
+	    (*p)->bytes = (void *)"false";
+	    (*p)->length = 5;
+	    break;
+	default:
+	    Tcl_Panic("Internal error in %s:%d unknown constant %d",
+		__FILE__, __LINE__, (int)constant);
+	}
+    }
+    /*
+     * Increase the ref-count so nothing ever attempts to free
+     * neither the static object we are returning, nor its bytes.
+     */
+    Tcl_IncrRefCount(*p);
+    return *p;
+}
+
 static int
 jsonlexp(struct context *context)
 {
@@ -193,6 +267,13 @@ jsonlexp(struct context *context)
     INSTR	= 0x00ff0000
   } lstate;
   double 	 d;
+  int		 i;
+  long	 	 l;
+  long long	 ll;
+  Tcl_WideInt	 wi;
+#ifdef USE_BIG_NUM
+  mp_int	 mpi;
+#endif
   char		*end;
   const char	*p;
   int		 initialized = 0;
@@ -345,28 +426,59 @@ jsonlexp(struct context *context)
       return -1;
     }
 
+    context->obj = NULL;
     /*
      * We already considered the null, true, and false
      * above, so it can only be a number now.
-     *
-     * NOTE: At this point we do not care about double
-     * versus integer, nor about the possible integer
-     * range. We generate a plain string Tcl_Obj and leave
-     * it to the user of the generated structure to
-     * convert to a number when actually needed. This
-     * defered conversion also ensures that the Tcl and
-     * platform we are building against does not matter
-     * regarding integer range, only the abilities of the
-     * Tcl at runtime.
      */
-
+    errno = 0;
     d = strtod(context->text, &end);
-    if (end == context->text)
-      goto bareword; /* Nothing parsed */
-
-    context->obj = Tcl_NewStringObj (context->text,
-				     end - context->text);
-
+    if (end == context->text || isnan(d) || isinf(d))
+	goto bareword; /* Nothing parsed */
+    if (context->text[0] == '0' && context->text[1] != '.') {
+	yyerror("Leading zeros aren't allowed in JSON");
+	TOKEN("Leading zero error");
+	return -1;
+    }
+    if (errno == ERANGE) {
+	/* Too large. Let TCL core deal with it */
+	goto donewithnumber;
+    }
+    /* See, if there was anything other than digit there: */
+    for (p = context->text; p != end; p++) {
+	if ((*p >= '0' && *p <= '9') || *p == '+' || *p == '-')
+	    continue;
+	context->obj = Tcl_NewDoubleObj(d);
+	goto donewithnumber;
+    }
+    /* Didn't find any non-digits, must be an integer: */
+    errno = 0;
+    ll = strtoll(context->text, &end, 10);
+    if (errno == ERANGE) {
+	/* Too large. Let TCL core deal with it */
+	goto donewithnumber;
+    }
+    /* Find the right integer-type for this number */
+    i = ll;	/* int ? */
+    if (i == ll) {
+	context->obj = Tcl_NewIntObj(i);
+	goto donewithnumber;
+    }
+    l = ll;	/* long ? */
+    if (l == ll) {
+	context->obj = Tcl_NewLongObj(l);
+	goto donewithnumber;
+    }
+    wi = ll;	/* Tcl_WideInt */
+    if (wi == ll) {
+	context->obj = Tcl_NewWideIntObj(wi);
+	goto donewithnumber;
+    }
+  donewithnumber:
+    if (context->obj == NULL) {
+	context->obj = Tcl_NewStringObj(context->text,
+					end - context->text);
+    }
     context->remaining -= (end - context->text);
     context->text = end;
     TOKEN1 ("CONSTANT");
