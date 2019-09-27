--- src/lib/ebus/device.cpp.orig	2018-12-26 15:38:15 UTC
+++ src/lib/ebus/device.cpp
@@ -30,6 +30,9 @@
 #ifdef HAVE_LINUX_SERIAL
 #  include <linux/serial.h>
 #endif
+#ifdef HAVE_FREEBSD_UFTDI
+#  include <dev/usb/uftdiio.h>
+#endif
 #include <errno.h>
 #ifdef HAVE_PPOLL
 #  include <poll.h>
@@ -192,7 +195,7 @@ result_t SerialDevice::open() {
   struct termios newSettings;
 
   // open file descriptor
-  m_fd = ::open(m_name, O_RDWR | O_NOCTTY);
+  m_fd = ::open(m_name, O_RDWR | O_NOCTTY | O_NDELAY);
 
   if (m_fd < 0) {
     return RESULT_ERR_NOTFOUND;
@@ -215,13 +218,24 @@ result_t SerialDevice::open() {
   }
 #endif
 
+#ifdef HAVE_FREEBSD_UFTDI
+  int param = 0;
+  // flush tx/rx and set low latency on uftdi device
+  if (ioctl(m_fd, UFTDIIOC_GET_LATENCY, &param) == 0) {
+    ioctl(m_fd, UFTDIIOC_RESET_IO, &param);
+    param = 1;
+    ioctl(m_fd, UFTDIIOC_SET_LATENCY, &param);
+  }
+#endif
+
   // save current settings
   tcgetattr(m_fd, &m_oldSettings);
 
   // create new settings
   memset(&newSettings, 0, sizeof(newSettings));
 
-  newSettings.c_cflag |= (B2400 | CS8 | CLOCAL | CREAD);
+  cfsetspeed(&newSettings, B2400);
+  newSettings.c_cflag |= (CS8 | CLOCAL | CREAD);
   newSettings.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  // non-canonical mode
   newSettings.c_iflag |= IGNPAR;  // ignore parity errors
   newSettings.c_oflag &= ~OPOST;
@@ -234,7 +248,10 @@ result_t SerialDevice::open() {
   tcflush(m_fd, TCIFLUSH);
 
   // activate new settings of serial device
-  tcsetattr(m_fd, TCSAFLUSH, &newSettings);
+  if (tcsetattr(m_fd, TCSAFLUSH, &newSettings)) {
+    close();
+    return RESULT_ERR_DEVICE;
+  }
 
   // set serial device into blocking mode
   fcntl(m_fd, F_SETFL, fcntl(m_fd, F_GETFL) & ~O_NONBLOCK);
