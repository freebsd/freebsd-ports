--- Sources/GL/GLX/input_device_linuxjoystick.cpp.orig	Wed Apr 21 01:50:23 2004
+++ Sources/GL/GLX/input_device_linuxjoystick.cpp	Thu Jul  8 21:18:13 2004
@@ -19,6 +19,7 @@
 **  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 */
 
+#if 0
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <unistd.h>
@@ -142,3 +143,4 @@
 // mode: clanlib ***
 // End: ***
 
+#endif
