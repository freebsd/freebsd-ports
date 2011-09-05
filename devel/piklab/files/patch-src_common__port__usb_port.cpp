--- src/common/port/usb_port.cpp.orig	2010-07-06 01:16:50.000000000 +0900
+++ src/common/port/usb_port.cpp	2011-09-01 20:09:27.000000000 +0900
@@ -37,10 +37,12 @@
   _initialized = true;
 #ifdef HAVE_USB
   usb_init();
+#if 0
   VersionData vd = VersionData::fromString(LIBUSB_VERSION);
   QString s = QString("libusb %1").arg(vd.pretty());
   if ( vd<VersionData(0, 1, 8) ) qWarning("%s: may be too old (you need at least version 0.1.8)", s.latin1());
 #endif
+#endif
 }
 
 bool Port::USB::isAvailable()
