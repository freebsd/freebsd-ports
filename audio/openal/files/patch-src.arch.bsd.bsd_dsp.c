--- src/arch/bsd/bsd_dsp.c.orig	Thu Apr 12 15:59:49 2001
+++ src/arch/bsd/bsd_dsp.c	Wed Feb 20 14:27:54 2002
@@ -8,12 +8,16 @@
  *
  */
 #include "al_siteconfig.h"
+#include "al_config.h"
+#include "al_main.h"
+#include "al_debug.h"
+#include "alc/alc_context.h"
+#include "arch/interface/interface_sound.h"
+#include "arch/bsd/bsd_dsp.h"
 
 #include <AL/altypes.h>
-#include <AL/alkludge.h>
-
-#include "al_siteconfig.h"
 
+#include <errno.h>
 #include <fcntl.h>
 #include <machine/soundcard.h>
 #include <stdio.h>
@@ -26,12 +30,6 @@
 #include <sys/types.h>
 #include <unistd.h>
 
-#include "arch/interface/interface_sound.h"
-#include "arch/bsd/bsd_dsp.h"
-
-#include "al_main.h"
-#include "al_debug.h"
-#include "alc/alc_context.h"
 
 static int alcChannel_to_dsp_channel(ALuint alcc);
 
@@ -101,9 +99,9 @@
  *  dma buffer size.
  *
  */
-void *grab_native(void) {
+void *grab_write_native(void) {
 	const char *dsppath = "/dev/dsp";
-	int divisor = _alSpot(_AL_DEF_BUFSIZ) | (2<<16);
+	int divisor = _alSpot(_ALC_DEF_BUFSIZ) | (2<<16);
 
 	dsp_fd = open(dsppath, O_WRONLY | O_NONBLOCK);
 
@@ -219,7 +217,7 @@
 	return;
 }
 
-float get_nativechannel(UNUSED(void *handle), ALuint channel) {
+float get_nativechannel(UNUSED(void *handle), ALCenum channel) {
 	int retval = 0;
 
 	channel = alcChannel_to_dsp_channel(channel);
@@ -242,7 +240,7 @@
  *
  * Kludgey, and obviously not the right way to do this
  */
-int set_nativechannel(UNUSED(void *handle), ALuint channel, float volume) {
+int set_nativechannel(UNUSED(void *handle), ALCenum channel, float volume) {
 	int unnormalizedvolume;
 
 	unnormalizedvolume = volume * 100;
@@ -313,7 +311,7 @@
 		     UNUSED(unsigned int *bufsiz),
 		     ALenum *fmt,
 		     unsigned int *speed) {
-	ALuint channels = _al_ALFORMAT(*fmt);
+	ALuint channels = _al_ALCHANNELS(*fmt);
 
 	if(dsp_fd < 0) {
 		return AL_FALSE;
@@ -365,3 +363,26 @@
 		     UNUSED(unsigned int *speed)) {
 	return AL_FALSE;
 }
+
+
+#define DONTCARE (1<<16)
+
+static ALboolean use_select = AL_TRUE;
+
+void *grab_read_native(void)
+{
+	static int read_fd;
+
+#ifndef CAPTURE_SUPPORT
+	return NULL;
+#endif
+
+	read_fd = aquire_read();
+	if( read_fd < 0) {
+		return NULL;
+	}
+
+	return &read_fd;
+
+}
+
