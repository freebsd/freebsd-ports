Index: SWIG/Lib/guile/typemaps.i
diff -u SWIG/Lib/guile/typemaps.i:1.17 SWIG/Lib/guile/typemaps.i:1.17.2.1
--- Lib/guile/typemaps.i:1.17	Thu Sep 21 16:06:17 2000
+++ Lib/guile/typemaps.i	Mon Feb 26 08:51:10 2001
@@ -54,9 +54,20 @@
 
 %typemap (guile, freearg) char *, const char * "if ($target) scm_must_free($target);";
 
+/* But this shall not apply if we try to pass a single char by
+   reference. */
+
+%typemap (guile, freearg) char *OUTPUT, char *BOTH "";
+
 /* Void */
 
 %typemap (guile, out) void "gswig_result = GH_UNSPECIFIED;";
 %typemap (guile, outdoc) void "";
+
+/* SCM is passed through */
+
+typedef unsigned long SCM;
+%typemap (guile, in) SCM "$target=$source;";
+%typemap (guile, out) SCM "$target=$source;";
 
 /* typemaps.i ends here */
