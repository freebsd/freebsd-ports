--- qsstv/sound/soundcontrol.h.orig	2014-12-06 14:41:00 UTC
+++ qsstv/sound/soundcontrol.h
@@ -22,8 +22,8 @@ public:
 
 private:
   Ui::soundControl *ui;
-  int inputAudioDeviceIndex;
-  int outputAudioDeviceIndex;
+  QString inputAudioDevice;
+  QString outputAudioDevice;
   bool changed;
   void getParams();
 };
