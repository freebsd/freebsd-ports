
$FreeBSD$

--- gmix/gmix.h	2001/07/13 09:44:04	1.1
+++ gmix/gmix.h	2001/07/13 09:44:44
@@ -39,6 +39,16 @@
 /* 
  * All, that is known about a mixer-device
  */
+#if !defined(OPEN_SOUND_SYSTEM)
+typedef struct mixer_info
+{
+  char id[16];
+  char name[32];
+  int  modify_counter;
+  int fillers[10];
+} mixer_info;
+#endif
+
 typedef struct device_info {
 #ifdef ALSA
 	snd_mixer_t *handle;
