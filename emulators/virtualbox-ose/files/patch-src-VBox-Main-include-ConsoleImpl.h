--- src/VBox/Main/include/ConsoleImpl.h.orig	2010-02-12 19:49:27.000000000 +0000
+++ src/VBox/Main/include/ConsoleImpl.h	2010-02-13 14:26:54.000000000 +0000
@@ -410,7 +410,7 @@
 
     HRESULT callTapSetupApplication(bool isStatic, RTFILE tapFD, Bstr &tapDevice,
                                     Bstr &tapSetupApplication);
-#if (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) && !defined(VBOX_WITH_NETFLT)
+#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD))
     HRESULT attachToTapInterface(INetworkAdapter *networkAdapter);
     HRESULT detachFromTapInterface(INetworkAdapter *networkAdapter);
 #endif
@@ -592,7 +592,7 @@
     PPDMLED      mapNetworkLeds[SchemaDefs::NetworkAdapterCount];
     PPDMLED      mapSharedFolderLed;
     PPDMLED      mapUSBLed[2];
-#if !defined(VBOX_WITH_NETFLT) && (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD))
+#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD))
     Utf8Str      maTAPDeviceName[8];
     RTFILE       maTapFD[8];
 #endif
