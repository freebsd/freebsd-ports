--- qsstv/sound/soundcontrol.h.orig	2014-04-09 10:27:16.000000000 -0700
+++ qsstv/sound/soundcontrol.h	2014-04-09 10:27:28.000000000 -0700
@@ -22,8 +22,8 @@
 
 private:
   Ui::soundControl *ui;
-  int inputAudioDeviceIndex;
-  int outputAudioDeviceIndex;
+  QString inputAudioDevice;
+  QString outputAudioDevice;
   bool changed;
   void getParams();
 };
