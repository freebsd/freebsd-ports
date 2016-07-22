--- src/VBox/Devices/build/VBoxDD.cpp.orig	2016-07-18 11:55:27 UTC
+++ src/VBox/Devices/build/VBoxDD.cpp
@@ -286,7 +286,7 @@ extern "C" DECLEXPORT(int) VBoxDriversRe
     if (RT_FAILURE(rc))
         return rc;
 #endif
-#if defined(RT_OS_LINUX)
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
 # ifdef VBOX_WITH_PULSE
     rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvHostPulseAudio);
     if (RT_FAILURE(rc))
@@ -302,12 +302,7 @@ extern "C" DECLEXPORT(int) VBoxDriversRe
     if (RT_FAILURE(rc))
         return rc;
 # endif
-#endif /* RT_OS_LINUX */
-#if defined(RT_OS_FREEBSD)
-    rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvHostOSSAudio);
-    if (RT_FAILURE(rc))
-        return rc;
-#endif
+#endif /* RT_OS_LINUX || RT_OS_FREEBSD */
 #if defined(RT_OS_DARWIN)
     rc = pCallbacks->pfnRegister(pCallbacks, &g_DrvHostCoreAudio);
     if (RT_FAILURE(rc))
