--- juk/slideraction.cpp.orig	Thu Feb 13 02:51:57 2003
+++ juk/slideraction.cpp	Mon Mar  3 12:24:34 2003
@@ -122,7 +122,7 @@
 
         trackPositionSlider = new TrackPositionSlider(base, "trackPositionSlider");
         trackPositionSlider->setMaxValue(1000);
-        QToolTip::add(trackPositionSlider, i18n("Track Position"));
+        QToolTip::add(trackPositionSlider, i18n("Track position"));
         layout->addWidget(trackPositionSlider);
 
 	volumeSlider = new QSlider(base, "volumeSlider" );
