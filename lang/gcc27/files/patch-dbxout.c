--- dbxout.c.orig	Thu Jun 15 04:27:10 1995
+++ dbxout.c	Mon Mar 20 13:29:11 2000
@@ -2494,6 +2494,11 @@
 {
 #ifdef DBX_FUNCTION_FIRST
   dbxout_really_begin_function (decl);
+#else
+#ifdef DBX_CHECK_FUNCTION_FIRST
+  if (DBX_CHECK_FUNCTION_FIRST)
+    dbxout_really_begin_function (decl);
+#endif
 #endif
 }
 
@@ -2509,6 +2514,11 @@
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
