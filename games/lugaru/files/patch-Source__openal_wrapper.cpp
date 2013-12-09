--- ./Source/openal_wrapper.cpp.orig	2010-05-16 06:42:54.000000000 +0200
+++ ./Source/openal_wrapper.cpp	2013-12-07 18:33:55.000000000 +0100
@@ -374,7 +374,7 @@
     char *fname = (char *) alloca(strlen(_fname) + 16);
     strcpy(fname, _fname);
     char *ptr = strchr(fname, '.');
-    if (ptr) *ptr = NULL;
+    if (ptr) ptr = NULL;
     strcat(fname, ".ogg");
 
     // just in case...
