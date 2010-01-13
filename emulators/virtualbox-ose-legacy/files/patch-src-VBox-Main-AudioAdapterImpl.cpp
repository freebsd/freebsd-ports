--- src/VBox/Main/AudioAdapterImpl.cpp.orig	2009-12-15 14:45:08.000000000 +0900
+++ src/VBox/Main/AudioAdapterImpl.cpp	2009-12-15 14:45:42.000000000 +0900
@@ -261,6 +261,11 @@
 #if defined (RT_OS_LINUX) || defined (RT_OS_FREEBSD) || defined(VBOX_WITH_SOLARIS_OSS)
             case AudioDriverType_OSS:
 #endif
+#ifdef RT_OS_FREEBSD
+# ifdef VBOX_WITH_PULSE
+            case AudioDriverType_Pulse:
+# endif
+#endif
 #ifdef RT_OS_DARWIN
             case AudioDriverType_CoreAudio:
 #endif
