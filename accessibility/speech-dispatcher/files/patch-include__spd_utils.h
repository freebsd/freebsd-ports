--- ./include/spd_utils.h.orig	2012-07-11 11:05:05.000000000 +0200
+++ ./include/spd_utils.h	2013-11-15 08:46:53.865350816 +0100
@@ -27,4 +27,8 @@
 #include <sys/types.h>
 
 ssize_t spd_getline(char **lineptr, size_t * n, FILE * f);
+
+ssize_t safe_read(int fd, void *buf, size_t count);
+ssize_t safe_write(int fd, const void *buf, size_t count);
+
 #endif /* SPD_UTILS_H */
