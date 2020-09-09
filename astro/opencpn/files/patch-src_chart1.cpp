--- src/chart1.cpp.orig	2020-07-15 18:02:29 UTC
+++ src/chart1.cpp
@@ -8226,7 +8226,7 @@ void MyFrame::MouseEvent( wxMouseEvent& event )
 #endif
 
 #ifdef __WXGTK__
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #if defined(__linux__)
@@ -10370,6 +10370,8 @@ extern "C" int wait(int *);                     // POS
 #include <sys/ioctl.h>
 #ifdef __linux__
 #include <linux/serial.h>
+#else
+#include <termios.h>
 #endif
 
 #endif
@@ -10445,17 +10447,25 @@ int isTTYreal(const char *dev)
 	return 1;
     return 0;
 #else /* !NetBSD */
+#ifdef __linux__
     struct serial_struct serinfo;
+#else
+    struct termios termattr;
+#endif
     int ret = 0;
 
     int fd = open(dev, O_RDWR | O_NONBLOCK | O_NOCTTY);
 
     // device name is pointing to a real device
     if(fd >= 0) {
+#ifdef __linux__
         if (ioctl(fd, TIOCGSERIAL, &serinfo)==0) {
             // If device type is no PORT_UNKNOWN we accept the port
             if (serinfo.type != PORT_UNKNOWN)
-                ret = 1;
+#else
+        if (tcgetattr(fd, &termattr) == 0) {
+#endif
+	      ret = 1;
         }
         close (fd);
     }
@@ -10505,10 +10515,17 @@ wxArrayString *EnumerateSerialPorts( void )
 
     //Initialize the pattern table
     if( devPatern[0] == NULL ) {
+#ifdef __linux__
         paternAdd ( "ttyUSB" );
         paternAdd ( "ttyACM" );
         paternAdd ( "ttyGPS" );
         paternAdd ( "refcom" );
+#else
+        paternAdd ( "ttyU" );
+        paternAdd ( "ttyu" );
+        paternAdd ( "ttyd" );
+        paternAdd ( "gps" );
+#endif
     }
 
  //  Looking for user privilege openable devices in /dev
