--- src/plugins/tts/tts.pro.orig	2019-02-16 08:43:06 UTC
+++ src/plugins/tts/tts.pro
@@ -1,10 +1,12 @@
 TEMPLATE = subdirs
 
-unix {
-    CONFIG += link_pkgconfig
-    config_speechd | packagesExist(speech-dispatcher) {
-        SUBDIRS += speechdispatcher
-    }
+with_speechd {
+	unix {
+	    CONFIG += link_pkgconfig
+	    config_speechd | packagesExist(speech-dispatcher) {
+	        SUBDIRS += speechdispatcher
+	    }
+	}
 }
 
 windows:!winrt: SUBDIRS += sapi
@@ -15,6 +17,8 @@ uikit: SUBDIRS += ios
 
 android: SUBDIRS += android
 
-config_flite | config_flite_alsa {
-    SUBDIRS += flite
+with_flite {
+	config_flite | config_flite_alsa {
+	    SUBDIRS += flite
+	}
 }
