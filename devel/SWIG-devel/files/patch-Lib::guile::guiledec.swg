Index: SWIG/Lib/guile/guiledec.swg
diff -u SWIG/Lib/guile/guiledec.swg:1.13 SWIG/Lib/guile/guiledec.swg:1.13.2.4
--- Lib/guile/guiledec.swg:1.13	Thu Sep 21 16:06:17 2000
+++ Lib/guile/guiledec.swg	Fri Mar  2 07:53:02 2001
@@ -27,17 +27,29 @@
 #define GH_NOT_PASSED    SCM_UNDEFINED
 #define GH_UNSPECIFIED   SCM_UNSPECIFIED
 
-#define GUILE_APPEND_RESULT(object)                                      \
-    if (gswig_result == GH_UNSPECIFIED)                                  \
-        gswig_result = object;                                           \
-    else {                                                               \
-        if (!gh_pair_p(gswig_result))                                    \
-	    gswig_result = gh_list(gswig_result, object, GH_NOT_PASSED); \
-        else                                                             \
-            gswig_result = gh_append2(gswig_result,                      \
-                                      gh_list(object, GH_NOT_PASSED));   \
+#define GUILE_APPEND_RESULT(object)						\
+    if (gswig_result == GH_UNSPECIFIED)						\
+        gswig_result = object;							\
+    else {									\
+        if (!gswig_list_p) {							\
+	    gswig_list_p = 1;							\
+	    gswig_result = gh_list(gswig_result, object, GH_NOT_PASSED);	\
+        }									\
+        else									\
+            gswig_result = gh_append2(gswig_result,				\
+                                      gh_list(object, GH_NOT_PASSED));		\
     }
 
+/* scm_values was implemented on C level in 1.4.1, and the prototype
+   is not included in libguile.h, so play safe and lookup `values'... */
+#define GUILE_MAYBE_VALUES						\
+    if (gswig_list_p)							\
+        gswig_result = gh_apply(gh_lookup("values"), gswig_result);
+    
+#define GUILE_MAYBE_VECTOR				\
+    if (gswig_list_p)					\
+        gswig_result = gh_list_to_vector(gswig_result);
+
 static char *
 GSWIG_scm2str (SCM s)
 {
@@ -78,10 +90,9 @@
   size_t tag;
 } swig_type_info;
 
-#define swig_types_initial swig_types
-
 SWIGSTATIC void
-SWIG_Guile_RegisterTypes (swig_type_info **table);
+SWIG_Guile_RegisterTypes (swig_type_info **table,
+			  swig_type_info **init);
 
 /* Register a new type-mapping with the type-checker.  origtype is the
    original datatype and newtype is an equivalent type.  cast is optional
