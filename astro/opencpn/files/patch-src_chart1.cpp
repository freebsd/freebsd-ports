--- src/chart1.cpp.orig	2016-06-25 12:26:20 UTC
+++ src/chart1.cpp
@@ -10308,7 +10308,11 @@ extern "C" int wait(int *);             
 
 #include <termios.h>
 #include <sys/ioctl.h>
+#ifdef __linux__
 #include <linux/serial.h>
+#else
+#include <termios.h>
+#endif
 
 #endif
 
@@ -10374,16 +10378,24 @@ int paternFilter (const struct dirent * 
 
 int isTTYreal(const char *dev)
 {
+#ifdef __linux__
     struct serial_struct serinfo;
+#else
+    struct termios termAttr;
+#endif
     int ret = 0;
 
     int fd = open(dev, O_RDWR | O_NONBLOCK | O_NOCTTY);
 
     // device name is pointing to a real device
     if(fd >= 0) {
+#ifdef __linux__
         if (ioctl(fd, TIOCGSERIAL, &serinfo)==0) {
             // If device type is no PORT_UNKNOWN we accept the port
             if (serinfo.type != PORT_UNKNOWN)
+#else
+        if (tcgetattr(fd, &termAttr) == 0) {
+#endif
                 ret = 1;
         }
         close (fd);
@@ -10409,10 +10421,17 @@ wxArrayString *EnumerateSerialPorts( voi
 
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
