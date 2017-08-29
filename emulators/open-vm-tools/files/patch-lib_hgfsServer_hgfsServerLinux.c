--- lib/hgfsServer/hgfsServerLinux.c.orig	2017-07-28 21:59:15 UTC
+++ lib/hgfsServer/hgfsServerLinux.c
@@ -178,6 +178,12 @@ getdents_linux(unsigned int fd,
 #   endif
 }
 #      define getdents getdents_linux
+#elif defined(__FreeBSD__) && defined(__INO64)
+#define getdents(fd, dirp, count)                                             \
+({                                                                            \
+   off_t basep;                                                                \
+   getdirentries(fd, dirp, count, &basep);                                    \
+})
 #elif defined(__FreeBSD__)
 #define getdents(fd, dirp, count)                                             \
 ({                                                                            \
