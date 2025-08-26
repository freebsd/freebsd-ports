--- common/spacenav/libspnav_driver.h.orig	2025-08-13 09:54:46 UTC
+++ common/spacenav/libspnav_driver.h
@@ -24,7 +24,7 @@
 #ifndef KICAD_LIBSPNAV_DRIVER_H
 #define KICAD_LIBSPNAV_DRIVER_H
 
-#ifdef __linux__
+#if defined (__linux__) || defined (__FreeBSD__)
 #include <spnav.h>
 #endif
 
@@ -52,4 +52,4 @@ class KICOMMON_API LIBSPNAV_DRIVER : public SPACENAV_D
     bool m_client_connected = false;
 };
 
-#endif // KICAD_LIBSPNAV_DRIVER_H
\ No newline at end of file
+#endif // KICAD_LIBSPNAV_DRIVER_H
