--- src/chart1.cpp.orig	2020-01-13 17:48:06 UTC
+++ src/chart1.cpp
@@ -7917,7 +7917,7 @@ void MyFrame::MouseEvent( wxMouseEvent& event )
 #endif
 
 #ifdef __WXGTK__
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 int g_lastMemTick = -1;
@@ -10282,6 +10282,8 @@ extern "C" int wait(int *);                     // POS
 #include <sys/ioctl.h>
 #ifdef __linux__
 #include <linux/serial.h>
+#else
+#include <termios.h>
 #endif
 
 #endif
@@ -10357,17 +10359,25 @@ int isTTYreal(const char *dev)
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
@@ -10417,10 +10427,17 @@ wxArrayString *EnumerateSerialPorts( void )
 
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
