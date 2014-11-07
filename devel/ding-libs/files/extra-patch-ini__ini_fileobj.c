--- ini/ini_fileobj.c.orig	2014-10-28 15:23:27 UTC
+++ ini/ini_fileobj.c
@@ -32,6 +32,9 @@
 #include "ini_config_priv.h"
 #include "path_utils.h"
 
+extern int      __sflags(const char *, int *);
+FILE    *fmemopen(void * __restrict, size_t, const char * __restrict);
+
 #define ICONV_BUFFER    5000
 
 #define BOM4_SIZE 4
