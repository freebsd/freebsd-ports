--- src/ftpd.c-orig	Mon Feb 17 23:52:49 2003
+++ src/ftpd.c	Mon Feb 17 23:56:52 2003
@@ -98,6 +98,8 @@
  * SUCH DAMAGE.
  */
 
+#define SUPPORT_UTMP
+
 #if	HAVE_TNFTPD_H
 
 #define	FTP_NAMES
