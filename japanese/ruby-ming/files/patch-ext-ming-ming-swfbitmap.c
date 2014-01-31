--- ext/ming/ming/swfbitmap.c.orig	2003-09-28 11:54:54.000000000 +0900
+++ ext/ming/ming/swfbitmap.c	2014-01-29 17:11:21.000000000 +0900
@@ -39,13 +39,13 @@
 
   rb_scan_args(argc, argv, "11", &f, &a);
 
-  filename = STR2CSTR(f);
+  filename = StringValuePtr(f);
   fp = fopen(filename, "rb");
   if (fp == NULL)
     RAISE_NOF(filename);
 
   if(NIL_P(a)) {
-    len = RSTRING(f)->len;
+    len = RSTRING_LEN(f);
     if(len > 5) {
       ext = &filename[len - 5];
       if(strncmp_ignore_case(ext, ".jpeg", 5) == 0) {
@@ -64,7 +64,7 @@
     }
   } else {
     
-    alpha_filename = STR2CSTR(a);
+    alpha_filename = StringValuePtr(a);
     afp = fopen(alpha_filename, "rb");
     if (afp == NULL) RAISE_NOF(alpha_filename);
     
