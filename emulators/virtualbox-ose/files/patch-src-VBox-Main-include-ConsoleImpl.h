--- src/VBox/Main/include/ConsoleImpl.h.orig
+++ src/VBox/Main/include/ConsoleImpl.h
@@ -410,7 +410,7 @@ private:
 
     HRESULT callTapSetupApplication(bool isStatic, RTFILE tapFD, Bstr &tapDevice,
                                     Bstr &tapSetupApplication);
-#if (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) && !defined(VBOX_WITH_NETFLT)
+#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD))
     HRESULT attachToTapInterface(INetworkAdapter *networkAdapter);
     HRESULT detachFromTapInterface(INetworkAdapter *networkAdapter);
 #endif
@@ -582,7 +582,7 @@ private:
     PPDMLED     mapNetworkLeds[SchemaDefs::NetworkAdapterCount];
     PPDMLED     mapSharedFolderLed;
     PPDMLED     mapUSBLed[2];
-#if !defined(VBOX_WITH_NETFLT) && (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD))
+#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD))
     Utf8Str     maTAPDeviceName[8];
     RTFILE      maTapFD[8];
 #endif
