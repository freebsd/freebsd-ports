
$FreeBSD$

--- lib/getcwd.c.orig
+++ lib/getcwd.c
@@ -30,6 +30,10 @@
 
 #include <fcntl.h> /* For AT_FDCWD on Solaris 9.  */
 
+#ifdef __FreeBSD__
+# undef AT_FDCWD
+#endif
+
 #ifndef __set_errno
 # define __set_errno(val) (errno = (val))
 #endif
