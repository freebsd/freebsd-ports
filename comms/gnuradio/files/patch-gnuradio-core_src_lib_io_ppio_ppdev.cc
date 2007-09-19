--- gnuradio-core/src/lib/io/ppio_ppdev.cc.orig	Wed Sep 13 17:30:04 2006
+++ gnuradio-core/src/lib/io/ppio_ppdev.cc	Mon May  7 11:10:18 2007
@@ -32,11 +32,16 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdexcept>
-#ifdef HAVE_LINUX_PPDEV_H
+#if defined(HAVE_LINUX_PPDEV_H)
 #include <sys/ioctl.h>
 #include <linux/ppdev.h>
 #include <linux/parport.h>
 #include <sstream>
+#elif defined(HAVE_DEV_PPBUS_PPI_H)
+#include <sys/ioctl.h>
+#include <dev/ppbus/ppi.h>
+#include <dev/ppbus/ppbconf.h>
+#include <sstream>
 #else
 // #warn "ppio_ppdev is not functional on this platform"
 #endif
@@ -53,84 +58,138 @@
 
 static int SP_ACTIVE_LOW_BITS	= 0x80;
 
-#ifndef HAVE_LINUX_PPDEV_H		// use stubs
+#if defined(HAVE_LINUX_PPDEV_H)
+
+// The real Linux code...
 
 ppio_ppdev::ppio_ppdev (int which)
 {
-  std::cerr << "ppio_ppdev: Not implemented on this platform\n";
-  throw std::runtime_error ("not implmeneted");
+  std::ostringstream filename;
+  filename << "/dev/parport" << which;
+  const char *c_filename = filename.str().c_str();
+
+  if ((d_fd = open (c_filename, O_RDWR)) < 0){
+    int my_errno = errno;
+    perror (c_filename);
+    if (my_errno == ENOENT){
+      std::cerr << "Does the device file " << c_filename << " exist?\n";
+      std::cerr << "If not, as root execute: \n";
+      std::cerr << "  # mknod " << c_filename << " c 99 0\n";
+      std::cerr << "  # chmod 666 " << c_filename << std::endl;
+    }
+    throw std::runtime_error ("open");
+  }
+
+  int mode = IEEE1284_MODE_COMPAT;
+  if (ioctl (d_fd, PPSETMODE, &mode) != 0){
+    perror ("ppio_ppdev: PPSETMODE");
+    close (d_fd);
+    throw std::runtime_error ("PPSETMODE");
+  }
 }
 
 ppio_ppdev::~ppio_ppdev ()
 {
+  close (d_fd);
 }
 
+
 void 
 ppio_ppdev::write_data (unsigned char v)
 {
+  if (ioctl (d_fd, PPWDATA, &v) != 0){
+    perror ("ppio_ppdev: PPWDATA");
+    throw std::runtime_error ("PPWDATA");
+  }
 }
 
 unsigned char
 ppio_ppdev::read_data ()
 {
-  return 0;
+  unsigned char v;
+
+  if (ioctl (d_fd, PPRDATA, &v) != 0){
+    perror ("ppio_ppdev: PPRDATA");
+    throw std::runtime_error ("PPRDATA");
+  }
+  return v;
 }
 
 void 
 ppio_ppdev::write_control (unsigned char v)
 {
+  unsigned char ctrl = v ^ CP_ACTIVE_LOW_BITS;
+  if (ioctl (d_fd, PPWCONTROL, &ctrl) != 0){
+    perror ("ppio_ppdev: PPWCONTROL");
+    throw std::runtime_error ("PPWCONTROL");
+  }
 }
 
 unsigned char
 ppio_ppdev::read_control ()
 {
-  return 0;
+  unsigned char ctrl;
+  if (ioctl (d_fd, PPRCONTROL, &ctrl) != 0){
+    perror ("ppio_ppdev: PPRCONTROL");
+    throw std::runtime_error ("PPRCONTROL");
+  }
+
+  return ctrl ^ CP_ACTIVE_LOW_BITS;
 }
 
 unsigned char
 ppio_ppdev::read_status ()
 {
-  return 0;
+  unsigned char status;
+  if (ioctl (d_fd, PPRSTATUS, &status) != 0){
+    perror ("ppio_ppdev: PPRSTATUS");
+    throw std::runtime_error ("PPRSTATUS");
+  }
+
+  return status ^ SP_ACTIVE_LOW_BITS;
 }
 
 void
 ppio_ppdev::lock ()
 {
+  if (ioctl (d_fd, PPCLAIM) != 0){
+    perror ("ppio_ppdev: PPCLAIM");
+    throw std::runtime_error ("PPCLAIM");
+  }
 }
 
 void
 ppio_ppdev::unlock ()
 {
+  if (ioctl (d_fd, PPRELEASE) != 0){
+    perror ("ppio_ppdev: PPRELEASE");
+    throw std::runtime_error ("PPRELEASE");
+  }
 }
 
-#else		
+#elif defined(HAVE_DEV_PPBUS_PPI_H)
 
-// The real code...
+// The real FreeBSD code... (Could work on other BSDs as well)
 
 ppio_ppdev::ppio_ppdev (int which)
 {
   std::ostringstream filename;
-  filename << "/dev/parport" << which;
+  filename << "/dev/ppi" << which;
   const char *c_filename = filename.str().c_str();
-
   if ((d_fd = open (c_filename, O_RDWR)) < 0){
     int my_errno = errno;
     perror (c_filename);
-    if (my_errno == ENOENT){
-      std::cerr << "Does the device file " << c_filename << " exist?\n";
-      std::cerr << "If not, as root execute: \n";
-      std::cerr << "  # mknod " << c_filename << " c 99 0\n";
-      std::cerr << "  # chmod 666 " << c_filename << std::endl;
-    }
     throw std::runtime_error ("open");
   }
 
+#if 0
   int mode = IEEE1284_MODE_COMPAT;
   if (ioctl (d_fd, PPSETMODE, &mode) != 0){
     perror ("ppio_ppdev: PPSETMODE");
     close (d_fd);
     throw std::runtime_error ("PPSETMODE");
   }
+#endif
 }
 
 ppio_ppdev::~ppio_ppdev ()
@@ -142,9 +201,9 @@
 void 
 ppio_ppdev::write_data (unsigned char v)
 {
-  if (ioctl (d_fd, PPWDATA, &v) != 0){
-    perror ("ppio_ppdev: PPWDATA");
-    throw std::runtime_error ("PPWDATA");
+  if (ioctl (d_fd, PPISDATA, &v) != 0){
+    perror ("ppio_ppdev: PPISDATA");
+    throw std::runtime_error ("PPISDATA");
   }
 }
 
@@ -153,9 +212,9 @@
 {
   unsigned char v;
 
-  if (ioctl (d_fd, PPRDATA, &v) != 0){
-    perror ("ppio_ppdev: PPRDATA");
-    throw std::runtime_error ("PPRDATA");
+  if (ioctl (d_fd, PPIGDATA, &v) != 0){
+    perror ("ppio_ppdev: PPIGDATA");
+    throw std::runtime_error ("PPIGDATA");
   }
   return v;
 }
@@ -164,9 +223,9 @@
 ppio_ppdev::write_control (unsigned char v)
 {
   unsigned char ctrl = v ^ CP_ACTIVE_LOW_BITS;
-  if (ioctl (d_fd, PPWCONTROL, &ctrl) != 0){
-    perror ("ppio_ppdev: PPWCONTROL");
-    throw std::runtime_error ("PPWCONTROL");
+  if (ioctl (d_fd, PPISCTRL, &ctrl) != 0){
+    perror ("ppio_ppdev: PPISCTRL");
+    throw std::runtime_error ("PPISCTRL");
   }
 }
 
@@ -174,9 +233,9 @@
 ppio_ppdev::read_control ()
 {
   unsigned char ctrl;
-  if (ioctl (d_fd, PPRCONTROL, &ctrl) != 0){
-    perror ("ppio_ppdev: PPRCONTROL");
-    throw std::runtime_error ("PPRCONTROL");
+  if (ioctl (d_fd, PPIGCTRL, &ctrl) != 0){
+    perror ("ppio_ppdev: PPIGCTRL");
+    throw std::runtime_error ("PPIGCTRL");
   }
 
   return ctrl ^ CP_ACTIVE_LOW_BITS;
@@ -186,30 +245,71 @@
 ppio_ppdev::read_status ()
 {
   unsigned char status;
-  if (ioctl (d_fd, PPRSTATUS, &status) != 0){
-    perror ("ppio_ppdev: PPRSTATUS");
-    throw std::runtime_error ("PPRSTATUS");
+  if (ioctl (d_fd, PPIGSTATUS, &status) != 0){
+    perror ("ppio_ppdev: PPIGSTATUS");
+    throw std::runtime_error ("PPIGSTATUS");
   }
-
   return status ^ SP_ACTIVE_LOW_BITS;
 }
 
 void
 ppio_ppdev::lock ()
 {
-  if (ioctl (d_fd, PPCLAIM) != 0){
-    perror ("ppio_ppdev: PPCLAIM");
-    throw std::runtime_error ("PPCLAIM");
-  }
 }
 
 void
 ppio_ppdev::unlock ()
 {
-  if (ioctl (d_fd, PPRELEASE) != 0){
-    perror ("ppio_ppdev: PPRELEASE");
-    throw std::runtime_error ("PPRELEASE");
-  }
+}
+#else
+/* Apparently, non real code */
+
+ppio_ppdev::ppio_ppdev (int which)
+{
+  std::cerr << "ppio_ppdev: Not implemented on this platform\n";
+  throw std::runtime_error ("not implmeneted");
+}
+
+ppio_ppdev::~ppio_ppdev ()
+{
+}
+
+void 
+ppio_ppdev::write_data (unsigned char v)
+{
+}
+
+unsigned char
+ppio_ppdev::read_data ()
+{
+  return 0;
+}
+
+void 
+ppio_ppdev::write_control (unsigned char v)
+{
+}
+
+unsigned char
+ppio_ppdev::read_control ()
+{
+  return 0;
+}
+
+unsigned char
+ppio_ppdev::read_status ()
+{
+  return 0;
+}
+
+void
+ppio_ppdev::lock ()
+{
+}
+
+void
+ppio_ppdev::unlock ()
+{
 }
 
 #endif
