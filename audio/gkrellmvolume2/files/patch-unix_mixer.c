Index: unix_mixer.c
diff -u unix_mixer.c.orig unix_mixer.c
--- unix_mixer.c.orig	Fri Aug 30 03:01:56 2002
+++ unix_mixer.c	Fri Aug 30 21:56:54 2002
@@ -27,7 +27,8 @@
 #include <string.h>
 #include <glob.h>
 
-#ifdef __FreeBSD__
+#include <sys/param.h>
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
 #include <machine/soundcard.h>
 #else
 #include <sys/soundcard.h>
@@ -41,19 +42,30 @@
 mixer_t *mixer_open(char *id) {
   mixer_t *result;
   int fd,devices,nr,i;
+#ifdef SOUND_MIXER_INFO
   mixer_info minfo;
+#endif
   char *sound_labels[] = SOUND_DEVICE_LABELS;
 
   if ((fd = open(id,O_RDWR)) == -1) return NULL;
-  if ( (ioctl(fd,SOUND_MIXER_READ_DEVMASK,&devices) < 0) ||
-       (ioctl(fd,SOUND_MIXER_INFO,&minfo) < 0))  {
+  if (ioctl(fd,SOUND_MIXER_READ_DEVMASK,&devices) < 0)  {
+    close(fd);
+    return NULL;
+  }
+#ifdef SOUND_MIXER_INFO
+  if (ioctl(fd,SOUND_MIXER_INFO,&minfo) < 0)  {
     close(fd);
     return NULL;
   }
+#endif
 
   result = malloc(sizeof(mixer_t));
   result->fd = fd;
+#ifdef SOUND_MIXER_INFO
   result->name = strdup(minfo.name);
+#else
+  result->name = strdup("mixer");
+#endif
 
   /* get the nr of devices */
   nr = 0;
