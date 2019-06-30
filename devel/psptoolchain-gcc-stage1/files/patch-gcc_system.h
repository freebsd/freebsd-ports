--- gcc/system.h.orig	2014-01-02 22:23:26 UTC
+++ gcc/system.h
@@ -203,6 +203,7 @@ extern int errno;
 
 #ifdef __cplusplus
 # include <cstring>
+# include <new>
 #endif
 
 /* Some of glibc's string inlines cause warnings.  Plus we'd rather
