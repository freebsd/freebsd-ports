--- digikam/utilities/setup/setupdcraw.cpp.orig	2008-03-15 13:24:50.000000000 +0100
+++ digikam/utilities/setup/setupdcraw.cpp	2008-03-15 13:32:56.000000000 +0100
@@ -89,8 +89,8 @@
     KConfig* config = kapp->config();
     config->setGroup("ImageViewer Settings");
     config->writeEntry("SixteenBitsImage", d->dcrawSettings->sixteenBits());
-    config->writeEntry("CameraColorBalance", d->dcrawSettings->useCameraWB());
-    config->writeEntry("AutomaticColorBalance", d->dcrawSettings->useAutoColorBalance());
+    config->writeEntry("CameraColorBalance", d->dcrawSettings->whiteBalance() == KDcrawIface::RawDecodingSettings::CAMERA);
+    config->writeEntry("AutomaticColorBalance", d->dcrawSettings->whiteBalance() == KDcrawIface::RawDecodingSettings::AUTO);
     config->writeEntry("RGBInterpolate4Colors", d->dcrawSettings->useFourColor());
     config->writeEntry("DontStretchPixels", d->dcrawSettings->useDontStretchPixels());
     config->writeEntry("EnableNoiseReduction", d->dcrawSettings->useNoiseReduction());
@@ -116,8 +116,12 @@
     d->dcrawSettings->setcaBlueMultiplier(config->readDoubleNumEntry("caBlueMultiplier", 1.0));
     d->dcrawSettings->setDontStretchPixels(config->readBoolEntry("DontStretchPixels", false));
     d->dcrawSettings->setUnclipColor(config->readNumEntry("UnclipColors", 0));
-    d->dcrawSettings->setCameraWB(config->readBoolEntry("CameraColorBalance", true));
-    d->dcrawSettings->setAutoColorBalance(config->readBoolEntry("AutomaticColorBalance", true));
+    if (config->readBoolEntry("CameraColorBalance", true))
+        d->dcrawSettings->setWhiteBalance(KDcrawIface::RawDecodingSettings::CAMERA);
+    else if (config->readBoolEntry("AutomaticColorBalance", true))
+        d->dcrawSettings->setWhiteBalance(KDcrawIface::RawDecodingSettings::AUTO);
+    else
+        d->dcrawSettings->setWhiteBalance(KDcrawIface::RawDecodingSettings::NONE);
     d->dcrawSettings->setFourColor(config->readBoolEntry("RGBInterpolate4Colors", false));
     d->dcrawSettings->setQuality((KDcrawIface::RawDecodingSettings::DecodingQuality)
                                   config->readNumEntry("RAWQuality",
