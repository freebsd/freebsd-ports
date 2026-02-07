--- libtme/module.c.orig	2010-06-06 04:04:42.000000000 +0900
+++ libtme/module.c	2011-03-20 06:00:02.000000000 +0900
@@ -62,11 +62,13 @@
 #endif /* !lt_ptr_t */
 #endif /* !lt_ptr */
 
+#if 0
 /* similarly, the installed libltdl may be so recent that its ltdl.h
    renames lt_preloaded_symbols with a macro, to a name different from
    what our libtool script makes.  it's possible that the renaming
    macro is meant to be undefined to handle this problem: */
 #undef lt_preloaded_symbols
+#endif
 
 /* types: */
 struct tme_module {
@@ -113,13 +115,14 @@
   FILE *modules_index;
 
   /* pass over the search path environment variables: */
-  for (pass = 0; ++pass <= 2; ) {
+  for (pass = 0; ++pass <= 3; ) {
 
     /* get the next search path environment variable value: */
     search_path = NULL;
     switch (pass) {
     case 1: search_path = getenv("LTDL_LIBRARY_PATH"); break;
     case 2: search_path = getenv(LTDL_SHLIBPATH_VAR); break;
+    case 3: search_path = "%%PREFIX%%/lib"; break;
     default: assert(FALSE);
     }
     if (search_path == NULL) {
