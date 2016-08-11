--- src/error.h.orig	2002-12-22 15:18:57 UTC
+++ src/error.h
@@ -24,7 +24,7 @@
 #ifndef MY_ERROR_H
 #define MY_ERROR_H
 
-int eioctl(int fd, int request, void *arg);
+int eioctl(int fd, unsigned long request, void *arg);
 void *emalloc(size_t size);
 void *erealloc(void *ptr, size_t size);
 char *estrdup(const char *str);
