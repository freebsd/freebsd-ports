--- jrd/isc_file.c.orig	Tue Dec 18 01:40:18 2001
+++ jrd/isc_file.c	Sat Jul  6 18:04:55 2002
@@ -106,6 +106,12 @@
 #define MTAB_CLOSE(stream)	ib_fclose (stream)
 #endif
 
+#ifdef FREEBSD
+#define MTAB			"/etc/fstab"
+#define MTAB_OPEN(path,type)	ib_fopen (path, type)
+#define MTAB_CLOSE(stream)	ib_fclose (stream)
+#endif 
+
 #ifdef DARWIN
 #define MTAB			"/etc/fstab.hd" 
 #define MTAB_OPEN(path,type)	ib_fopen (path, type)
