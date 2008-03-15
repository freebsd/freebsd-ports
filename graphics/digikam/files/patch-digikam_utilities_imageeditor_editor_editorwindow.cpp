--- digikam/utilities/imageeditor/editor/editorwindow.cpp.orig	2008-03-15 12:21:58.000000000 +0100
+++ digikam/utilities/imageeditor/editor/editorwindow.cpp	2008-03-15 12:36:19.000000000 +0100
@@ -885,8 +885,12 @@
         m_IOFileSettings->rawDecodingSettings.outputColorSpace = KDcrawIface::RawDecodingSettings::SRGB;
 
     m_IOFileSettings->rawDecodingSettings.sixteenBitsImage        = config->readBoolEntry("SixteenBitsImage", false);
-    m_IOFileSettings->rawDecodingSettings.automaticColorBalance   = config->readBoolEntry("AutomaticColorBalance", true);
-    m_IOFileSettings->rawDecodingSettings.cameraColorBalance      = config->readBoolEntry("CameraColorBalance", true);
+    if (config->readBoolEntry("CameraColorBalance", true))
+        m_IOFileSettings->rawDecodingSettings.whiteBalance        = KDcrawIface::RawDecodingSettings::CAMERA;
+    else if (config->readBoolEntry("AutomaticColorBalance", true)) 
+        m_IOFileSettings->rawDecodingSettings.whiteBalance        = KDcrawIface::RawDecodingSettings::AUTO;
+    else
+        m_IOFileSettings->rawDecodingSettings.whiteBalance        = KDcrawIface::RawDecodingSettings::NONE;
     m_IOFileSettings->rawDecodingSettings.RGBInterpolate4Colors   = config->readBoolEntry("RGBInterpolate4Colors", false);
     m_IOFileSettings->rawDecodingSettings.DontStretchPixels = config->readBoolEntry("DontStretchPixels", false);
     m_IOFileSettings->rawDecodingSettings.enableNoiseReduction    = config->readBoolEntry("EnableNoiseReduction", false);
