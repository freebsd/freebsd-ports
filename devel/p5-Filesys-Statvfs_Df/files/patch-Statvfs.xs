--- Statvfs.xs.orig	Wed Nov 22 09:57:31 2000
+++ Statvfs.xs	Tue Feb 17 10:13:35 2004
@@ -5,12 +5,21 @@
 #include "perl.h"
 #include "XSUB.h"
 #include "config.h"
-#include<sys/statvfs.h>
+#if defined(__APPLE__ ) || defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
+#include <sys/statvfs.h>
+#endif
 #ifdef __cplusplus
 }
 #endif
 
-typedef struct statvfs Statvfs;
+#if defined(__APPLE__ ) || defined(__FreeBSD__)
+	typedef struct statfs Statvfs;
+#else
+	typedef struct statvfs Statvfs;
+#endif
 
 MODULE = Filesys::Statvfs	PACKAGE = Filesys::Statvfs
 
@@ -20,34 +29,63 @@
 	PREINIT:
 	Statvfs st;
 	Statvfs *st_ptr;
+	long t;
 	PPCODE:
+#if defined(__APPLE__ ) || defined(__FreeBSD__)
+	if(statfs(dir, &st) == 0) {
+#else
 	if(statvfs(dir, &st) == 0) {
+#endif
 		st_ptr=&st;
 		EXTEND(sp, 15);
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_bsize)));
+#if defined(__APPLE__ ) || defined(__FreeBSD__)
+		PUSHs(sv_2mortal(newSViv(0)));
+#else
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_frsize)));
+#endif
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_blocks)));
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_bfree)));
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_bavail)));
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_files)));
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_ffree)));
+#if defined(__APPLE__ ) || defined(__FreeBSD__)
+		PUSHs(sv_2mortal(newSViv(st_ptr->f_ffree)));
+#else
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_favail)));
+#endif
 #if defined(_AIX__) || defined(_LINUX__)
 		PUSHs(sv_2mortal(newSViv(0)));
 #else
+#if defined(__APPLE__ ) || defined(__FreeBSD__)
+		memcpy (&t, &st_ptr->f_fsid, sizeof (long));
+		PUSHs(sv_2mortal(newSViv(t)));
+#else
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_fsid)));
 #endif
+#endif
 #ifdef _LINUX__
 		PUSHs(sv_2mortal(newSVpv(NULL, 1)));
 #else
+#if defined(__APPLE__ ) || defined(__FreeBSD__)
+		PUSHs(sv_2mortal(newSVpv(st_ptr->f_fstypename, 0)));
+#else
 		PUSHs(sv_2mortal(newSVpv(st_ptr->f_basetype, 0)));
 #endif
+#endif
+#if defined(__APPLE__ ) || defined(__FreeBSD__)
+		PUSHs(sv_2mortal(newSViv(st_ptr->f_flags)));
+		PUSHs(sv_2mortal(newSVpv(st_ptr->f_mntonname, MNAMELEN)));
+#else
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_flag)));
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_namemax)));
+#endif
 #if defined(_DEC__) || defined(_LINUX__)
 		PUSHs(sv_2mortal(newSVpv(NULL, 1)));
 #else
+#if ! defined(__APPLE__ ) && ! defined(__FreeBSD__)
 		PUSHs(sv_2mortal(newSVpv(st_ptr->f_fstr, 0)));
+#endif
 #endif
 #ifdef _HPUX__
 		PUSHs(sv_2mortal(newSViv(st_ptr->f_size))); 
