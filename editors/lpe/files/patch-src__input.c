--- ./src/input.c.orig	2008-08-08 07:51:24.000000000 +0000
+++ ./src/input.c	2008-08-08 07:51:48.000000000 +0000
@@ -2262,7 +2262,7 @@
     SLang_load_string (cmd);
     /* to avoid slang stack overflows... */
     SLang_restart (1);
-    SLang_Error = 0;
+    SLang_set_error(0);
 
     /* 
      * This is not the nicest thing to do, but certain slang commnds,
