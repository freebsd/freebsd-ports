
$FreeBSD$

--- ../pr/include/md/_freebsd.h.orig	Sat Feb 16 09:12:55 2002
+++ ../pr/include/md/_freebsd.h	Thu Aug  8 19:31:23 2002
@@ -40,6 +40,7 @@
 #if __FreeBSD__ >= 2
 #include <osreldate.h>  /* for __FreeBSD_version */
 #endif
+#include <sys/param.h>
 #include <sys/syscall.h>
 
 #define PR_LINKER_ARCH	"freebsd"
