--- qtspeech.pro.orig	2019-02-16 08:32:35 UTC
+++ qtspeech.pro
@@ -1,7 +1,11 @@
 load(configure)
-qtCompileTest(flite)
-qtCompileTest(flite_alsa)
-!packagesExist(speech-dispatcher) {
-    qtCompileTest(speechd)
+with_flite {
+	qtCompileTest(flite)
+	qtCompileTest(flite_alsa)
+}
+with_speechd {
+	!packagesExist(speech-dispatcher) {
+	    qtCompileTest(speechd)
+	}
 }
 load(qt_parts)
