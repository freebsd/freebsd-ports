--- sound.c.orig	2024-05-20 18:01:18 UTC
+++ sound.c
@@ -604,7 +604,7 @@ void play_sound_interface(struct sound_dev* dev, int n
 			else
 				dev->cr_correction = (0.5 - dev->cr_average_fill) * dev->play_buf_size;
 			if (dev->cr_correction != 0)
-				dev->cr_correct_time = abs(dev->sample_rate * AVG_SEC / dev->cr_correction);
+				dev->cr_correct_time = fabs(dev->sample_rate * AVG_SEC / dev->cr_correction);
 			if (quisk_sound_state.verbose_sound > 1)
 				QuiskPrintf("%s:  Buffer average %5.2lf cr_correction %5d\n",
 					dev->stream_description, dev->cr_average_fill * 100, dev->cr_correction);
