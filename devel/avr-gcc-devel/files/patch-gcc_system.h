--- gcc/system.h.orig	2014-06-11 16:59:01 UTC
+++ gcc/system.h
@@ -209,6 +209,7 @@ extern int errno;
 
 #ifdef __cplusplus
 # include <cstring>
+# include <new>
 #endif
 
 /* Some of glibc's string inlines cause warnings.  Plus we'd rather
