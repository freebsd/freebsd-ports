--- tclUnixPort.h.orig	Fri Oct 25 10:45:48 2002
+++ tclUnixPort.h	Fri Oct 25 10:45:15 2002
@@ -146,6 +146,9 @@
  * The type of the status returned by wait varies from UNIX system
  * to UNIX system.  The macro below defines it:
  */
+#ifdef __FreeBSD__
+#   define NO_UNION_WAIT
+#endif
 
 #ifdef _AIX
 #   define WAIT_STATUS_TYPE pid_t
