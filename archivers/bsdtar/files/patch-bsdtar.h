--- bsdtar.h.orig	Sun Jul 18 11:08:41 2004
+++ bsdtar.h	Sun Jul 18 11:09:20 2004
@@ -107,3 +107,7 @@
 void	usage(struct bsdtar *);
 int	yes(const char *fmt, ...);
 
+#ifndef id_t
+typedef       __int64_t       __id_t;         /* can hold a gid_t, pid_t, or uid_t */
+typedef        __id_t          id_t;           /* can hold a uid_t or pid_t */
+#endif
