--- src/chart1.cpp.orig	2020-07-15 18:02:29 UTC
+++ src/chart1.cpp
@@ -8244,7 +8244,7 @@ void MyFrame::MouseEvent( wxMouseEvent& event )
 #endif
 
 #ifdef __WXGTK__
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #if defined(__linux__)
@@ -10382,10 +10382,14 @@
 #if defined(__UNIX__) && !defined(__OCPN__ANDROID__) && !defined(__WXOSX__)
 extern "C" int wait(int *);                     // POSIX wait() for process
 
+#include <sys/param.h>
 #include <termios.h>
+#include <fcntl.h>
 #include <sys/ioctl.h>
 #ifdef __linux__
 #include <linux/serial.h>
+#else
+#include <termios.h>
 #endif
 
 #endif
@@ -10452,7 +10456,8 @@
 
 int isTTYreal(const char *dev)
 {
-#ifdef __NetBSD__
+#ifdef __FreeBSD__
+ 	            wxLogMessage( _T("FreeBSD") );
     if (strncmp("/dev/tty0", dev, 9) == 0)
 	return 1;
     if (strncmp("/dev/ttyU", dev, 9) == 0)
@@ -10460,24 +10465,32 @@
     if (strcmp("/dev/gps", dev) == 0)
 	return 1;
     return 0;
-#else /* !NetBSD */
+#else
+#ifdef __FreeBSD__
+    struct termios termAttr;
+#else
     struct serial_struct serinfo;
+#endif    
     int ret = 0;
 
     int fd = open(dev, O_RDWR | O_NONBLOCK | O_NOCTTY);
 
     // device name is pointing to a real device
     if(fd >= 0) {
+#ifdef __FreeBSD__
+        if (tcgetattr(fd, &termAttr) == 0) {
+#else
         if (ioctl(fd, TIOCGSERIAL, &serinfo)==0) {
             // If device type is no PORT_UNKNOWN we accept the port
             if (serinfo.type != PORT_UNKNOWN)
+#endif
                 ret = 1;
         }
         close (fd);
     }
 
     return ret;
-#endif /* !NetBSD */
+#endif
 }
 
 
@@ -10521,10 +10534,17 @@
 
     //Initialize the pattern table
     if( devPatern[0] == NULL ) {
+#ifdef __FreeBSD__
+        paternAdd ( "ttyU" );
+        paternAdd ( "ttyu" );
+        paternAdd ( "ttyd" );
+        paternAdd ( "gps" );
+#else
         paternAdd ( "ttyUSB" );
         paternAdd ( "ttyACM" );
         paternAdd ( "ttyGPS" );
         paternAdd ( "refcom" );
+#endif
     }
 
  //  Looking for user privilege openable devices in /dev
@@ -11019,6 +11039,12 @@
     if(!result1.size())
         wxExecute(_T("stat -c %G /dev/ttyACM0"), result1);
 
+    if(!result1.size())
+        wxExecute(_T("stat -f %g /dev/ttyu0"), result1);
+
+    if(!result1.size())
+        wxExecute(_T("stat -f %g /dev/ttyU0"), result1);
+
     wxString msg1 = _("OpenCPN requires access to serial ports to use serial NMEA data.\n");
     if(!result1.size()) {
         wxString msg = msg1 + _("No Serial Ports can be found on this system.\n\
@@ -11032,7 +11058,7 @@
     wxString user = wxGetUserId(), group = result1[0];
 
     wxArrayString result2;
-    wxExecute(_T("groups ") + user, result2);
+    wxExecute(_T("id -G ") + user, result2);
 
     if(result2.size()) {
         wxString user_groups = result2[0];
