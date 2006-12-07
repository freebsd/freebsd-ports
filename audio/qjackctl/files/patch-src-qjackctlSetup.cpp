--- src/qjackctlSetup.cpp.orig	Thu Dec  7 00:05:30 2006
+++ src/qjackctlSetup.cpp	Thu Dec  7 00:06:00 2006
@@ -285,7 +285,7 @@
     preset.iWordLength  = m_settings.readNumEntry("/WordLength", 16);
     preset.iWait        = m_settings.readNumEntry("/Wait", 21333);
     preset.iChan        = m_settings.readNumEntry("/Chan", 0);
-    preset.sDriver      = m_settings.readEntry("/Driver", "alsa");
+    preset.sDriver      = m_settings.readEntry("/Driver", "oss");
     preset.sInterface   = m_settings.readEntry("/Interface", QString::null);
     preset.iAudio       = m_settings.readNumEntry("/Audio", 0);
     preset.iDither      = m_settings.readNumEntry("/Dither", 0);
