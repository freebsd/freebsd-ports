--- src/lib/oogl/lisp/lisp.c	2000/09/01 22:38:16	1.2
+++ src/lib/oogl/lisp/lisp.c	2006/06/26 15:41:16	1.4
@@ -1205,9 +1205,9 @@
 	} else if (argclass == LARRAY) {
 	  /* special case for this because it takes 3 args: the base type,
 	     the array itself, and a count */
-	    va_arg(a_list, LType *);
-	    va_arg(a_list, void *);
-	    va_arg(a_list, int *);
+	    (void)va_arg(a_list, LType *);
+	    (void)va_arg(a_list, void *);
+	    (void)va_arg(a_list, int *);
 
 	    ++argspecs;
 	    if (LakeMore(lake,c)) {
@@ -1230,11 +1230,11 @@
 	    moreargspecs = 0;
 	}
     } else if(argclass == LLAKE) {
-	va_arg(a_list, Lake **);
+	(void)va_arg(a_list, Lake **);
 	LListAppend(args, LTOOBJ(LLAKE)(&lake));
     } else {
       ++argspecs;
-      va_arg(a_list, void *);
+      (void)va_arg(a_list, void *);
       if (LakeMore(lake,c)) {
 	LObject *arg;
 
@@ -1359,8 +1359,8 @@
 	    args = args->cdr;
 	    hold = 0;
 	  } else {
-	    va_arg(a_list, void *);
-	    va_arg(a_list, void *);
+	    (void)va_arg(a_list, void *);
+	    (void)va_arg(a_list, void *);
 	  }
 	} else if(argtype == LREST) {
 	    LList **restp = va_arg(a_list, LList **);
@@ -1389,7 +1389,7 @@
 	args = args->cdr;
 	hold = 0;
       } else
-	va_arg(a_list, void *);
+	(void)va_arg(a_list, void *);
     }
   }
   if (argsrequired<0) argsrequired = argspecs;
@@ -2110,7 +2110,7 @@
     va_list *a_list;
     unsigned long *x;
 {
-  *x = va_arg(*a_list, ulong);
+  *x = va_arg(*a_list, unsigned long);
 }
 
 LObject *ulongparse(Lake *lake)
