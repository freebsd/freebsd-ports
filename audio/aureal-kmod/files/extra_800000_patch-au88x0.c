--- ./au88x0.c.orig	2010-07-11 01:34:42.000000000 +0600
+++ ./au88x0.c	2010-07-11 01:34:51.000000000 +0600
@@ -24,6 +24,10 @@
  * SUCH DAMAGE.
  */
 
+#ifdef HAVE_KERNEL_OPTION_HEADERS
+#include "opt_snd.h"
+#endif
+
 /*
  * Part of this code was inspired by Aureal's linux driver
  */
@@ -198,28 +202,28 @@
 static struct au_info	*find_device_core(void *core_obj);
 
 static u_int32_t au_playfmt[] = {
-	AFMT_MU_LAW,
-	AFMT_STEREO | AFMT_MU_LAW,
-	AFMT_A_LAW,
-	AFMT_STEREO | AFMT_A_LAW,
-	AFMT_U8,
-	AFMT_STEREO | AFMT_U8,
-	AFMT_S16_LE,
-	AFMT_STEREO | AFMT_S16_LE,
+	SND_FORMAT(AFMT_MU_LAW, 1, 0),
+	SND_FORMAT(AFMT_MU_LAW, 2, 0),
+	SND_FORMAT(AFMT_A_LAW, 1, 0),
+	SND_FORMAT(AFMT_A_LAW, 2, 0),
+	SND_FORMAT(AFMT_U8, 1, 0),
+	SND_FORMAT(AFMT_U8, 2, 0),
+	SND_FORMAT(AFMT_S16_LE, 1, 0),
+	SND_FORMAT(AFMT_S16_LE, 2, 0),
 	0
 };
 
 static struct pcmchan_caps au_playcaps = {4000, 48000, au_playfmt, 0};
 
 static u_int32_t au_recfmt[] = {
-	AFMT_MU_LAW,
-	AFMT_STEREO | AFMT_MU_LAW,
-	AFMT_A_LAW,
-	AFMT_STEREO | AFMT_A_LAW,
-	AFMT_U8,
-	AFMT_STEREO | AFMT_U8,
-	AFMT_S16_LE,
-	AFMT_STEREO | AFMT_S16_LE,
+	SND_FORMAT(AFMT_MU_LAW, 1, 0),
+	SND_FORMAT(AFMT_MU_LAW, 2, 0),
+	SND_FORMAT(AFMT_A_LAW, 1, 0),
+	SND_FORMAT(AFMT_A_LAW, 2, 0),
+	SND_FORMAT(AFMT_U8, 1, 0),
+	SND_FORMAT(AFMT_U8, 2, 0),
+	SND_FORMAT(AFMT_S16_LE, 1, 0),
+	SND_FORMAT(AFMT_S16_LE, 2, 0),
 	0
 };
 
@@ -491,7 +495,7 @@
 	return left | (right << 8);
 }
 
-static int
+static u_int32_t
 aumix_setrecsrc(struct snd_mixer *m, u_int32_t src)
 {
 	struct au_info *au;
@@ -533,7 +537,7 @@
 	KOBJMETHOD(mixer_init,		aumix_init),
 	KOBJMETHOD(mixer_set,		aumix_set),
 	KOBJMETHOD(mixer_setrecsrc,	aumix_setrecsrc),
-	{ 0, 0 }
+	KOBJMETHOD_END
 };
 MIXER_DECLARE(aumixer);
 
@@ -603,15 +607,12 @@
 	  else if (format & AFMT_MU_LAW)
 		fmt->eEncoding = ASPFMTULAW;
 
-	if (format & AFMT_STEREO)
-		fmt->wChannels = 2;
-	else
-		fmt->wChannels = 1;
+	fmt->wChannels = (AFMT_CHANNEL(format) > 1) ? 2 : 1;
 	SetWaveFormat(ch->wave, &ch->fmt);
 	return 0;
 }
 
-static int
+static u_int32_t
 auchan_setspeed(kobj_t obj, void *data, u_int32_t speed)
 {
 	struct	au_chinfo *ch = data;
@@ -621,7 +622,7 @@
 	return speed;
 }
 
-static int
+static u_int32_t
 auchan_setblocksize(kobj_t obj, void *data, u_int32_t blocksize)
 {
 	return blocksize;
@@ -661,7 +662,7 @@
 	return 0;
 }
 
-static int
+static u_int32_t
 auchan_getptr(kobj_t obj, void *data)
 {
 	struct	au_chinfo *ch = data;
@@ -693,7 +694,7 @@
 	KOBJMETHOD(channel_trigger,		auchan_trigger),
 	KOBJMETHOD(channel_getptr,		auchan_getptr),
 	KOBJMETHOD(channel_getcaps,		auchan_getcaps),
-	{ 0, 0 }
+	KOBJMETHOD_END
 };
 CHANNEL_DECLARE(auchan);

