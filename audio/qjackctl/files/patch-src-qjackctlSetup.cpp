--- src/qjackctlSetup.cpp.orig	2007-07-18 12:05:32.000000000 +0200
+++ src/qjackctlSetup.cpp	2007-09-26 22:24:19.000000000 +0200
@@ -290,7 +290,7 @@
 	preset.iWordLength  = m_settings.value("/WordLength", 16).toInt();
 	preset.iWait        = m_settings.value("/Wait", 21333).toInt();
 	preset.iChan        = m_settings.value("/Chan", 0).toInt();
-	preset.sDriver      = m_settings.value("/Driver", "alsa").toString();
+	preset.sDriver      = m_settings.value("/Driver", "oss").toString();
 	preset.sInterface   = m_settings.value("/Interface").toString();
 	preset.iAudio       = m_settings.value("/Audio", 0).toInt();
 	preset.iDither      = m_settings.value("/Dither", 0).toInt();
