--- src/VBox/Frontends/VirtualBox/src/settings/vm/VBoxVMSettingsAudio.cpp.orig	2009-12-17 15:28:01.000000000 +0100
+++ src/VBox/Frontends/VirtualBox/src/settings/vm/VBoxVMSettingsAudio.cpp	2009-12-21 14:14:35.000000000 +0100
@@ -89,6 +89,9 @@
 #endif
 #if defined Q_OS_LINUX || defined Q_OS_FREEBSD
     mCbAudioDriver->addItem (vboxGlobal().toString (KAudioDriverType_OSS));
+# ifdef VBOX_WITH_PULSE
+    mCbAudioDriver->addItem (vboxGlobal().toString (KAudioDriverType_Pulse));
+# endif
 #endif
 #if defined Q_OS_LINUX
 # ifdef VBOX_WITH_ALSA
