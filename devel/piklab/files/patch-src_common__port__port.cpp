--- src/common/port/port.cpp.orig	2012-06-04 07:17:40.000000000 +0900
+++ src/common/port/port.cpp	2012-06-06 23:01:04.000000000 +0900
@@ -60,8 +60,12 @@
 const PortType::Data PortType::DATA[Nb_Types] = {
   { I18N_NOOP("Serial Port"),   "serial",   true  },
   { I18N_NOOP("Parallel Port"), "parallel", true  },
+#ifdef __linux
   { I18N_NOOP("USB Port"),      "usb",      false },
   { I18N_NOOP("HID Port"),      "hid",      false }
+#else
+  { I18N_NOOP("USB Port"),      "usb",      false }
+#endif
 };
 
 const char * const Port::IO_DIR_NAMES[3] = { "no_io", "in", "out" };
@@ -73,7 +77,9 @@
     case PortType::Serial:   return Serial::probedDeviceList();
     case PortType::Parallel: return Parallel::probedDeviceList();
     case PortType::USB:      return USB::probedDeviceList();
+#ifdef __linux
     case PortType::HID:      return HID::probedDeviceList();
+#endif
     case PortType::Nb_Types: break;
   }
   return QStringList();
@@ -85,7 +91,9 @@
     case PortType::Serial:   return Serial::isAvailable();
     case PortType::Parallel: return Parallel::isAvailable();
     case PortType::USB:      return USB::isAvailable();
+#ifdef __linux
     case PortType::HID:      return HID::isAvailable();
+#endif
     case PortType::Nb_Types: break;
   }
   return false;
