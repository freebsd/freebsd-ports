--- gcc/dbxout.c.orig	1999/08/26 09:26:57	1.1.1.2
+++ gcc/dbxout.c	1999/08/28 07:19:03	1.3
@@ -2685,7 +2685,12 @@
 {
 #ifdef DBX_FUNCTION_FIRST
   dbxout_really_begin_function (decl);
+#else
+#ifdef DBX_CHECK_FUNCTION_FIRST
+  if (DBX_CHECK_FUNCTION_FIRST)
+    dbxout_really_begin_function (decl);
 #endif
+#endif
 }
 
 /* Output dbx data for a function definition.
@@ -2700,6 +2705,11 @@
 {
 #ifndef DBX_FUNCTION_FIRST
   dbxout_really_begin_function (decl);
+#else
+#ifdef DBX_CHECK_FUNCTION_FIRST
+  if (!(DBX_CHECK_FUNCTION_FIRST))
+    dbxout_really_begin_function (decl);
+#endif
 #endif
   dbxout_block (DECL_INITIAL (decl), 0, DECL_ARGUMENTS (decl));
 #ifdef DBX_OUTPUT_FUNCTION_END
