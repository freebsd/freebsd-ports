--- drivers/oss/oss_driver.c.orig	2017-01-10 10:20:51 UTC
+++ drivers/oss/oss_driver.c
@@ -23,6 +23,7 @@
 
 #include <config.h>
 
+#define __BSD_VISIBLE	1
 #ifdef USE_BARRIER
 /*
  * POSIX conformance level should be globally defined somewhere, possibly
@@ -172,7 +173,9 @@ static void set_period_size (oss_driver_
 		((double)driver->period_size /
 		 (double)driver->sample_rate) * 1e6;
 	driver->last_wait_ust = 0;
-	driver->last_periodtime = driver->engine->get_microseconds ();
+	driver->last_periodtime = driver->engine ?
+		driver->engine->get_microseconds() :
+		jack_get_microseconds();
 	driver->next_periodtime = 0;
 	driver->iodelay = 0.0F;
 }
@@ -180,7 +183,9 @@ static void set_period_size (oss_driver_
 
 static inline void update_times (oss_driver_t *driver)
 {
-	driver->last_periodtime = driver->engine->get_microseconds ();
+	driver->last_periodtime = driver->engine ?
+		driver->engine->get_microseconds() :
+		jack_get_microseconds();
 	if (driver->next_periodtime > 0) {
 		driver->iodelay = (float)
 				  ((long double)driver->last_periodtime -
@@ -211,6 +216,7 @@ static void copy_and_convert_in (jack_sa
 	int dstidx;
 	signed short *s16src = (signed short*)src;
 	signed int *s32src = (signed int*)src;
+	unsigned char *s24src = (unsigned char *) src;
 	double *f64src = (double*)src;
 	jack_sample_t scale;
 
@@ -225,10 +231,13 @@ static void copy_and_convert_in (jack_sa
 		}
 		break;
 	case 24:
-		scale = 1.0f / 0x7fffff;
+		scale = 1.0f / 0x7fffffff;
 		for (dstidx = 0; dstidx < nframes; dstidx++) {
 			dst[dstidx] = (jack_sample_t)
-				      s32src[srcidx] * scale;
+				((signed int)(
+					(s24src[3 * srcidx + 2] << 24) |
+					(s24src[3 * srcidx + 1] << 16) |
+					(s24src[3 * srcidx + 0] << 8))) * scale;
 			srcidx += chcount;
 		}
 		break;
@@ -256,6 +265,7 @@ static void copy_and_convert_out (void *
 	int srcidx;
 	int dstidx;
 	signed short *s16dst = (signed short*)dst;
+	unsigned char *s24dst = (unsigned char *) dst;
 	signed int *s32dst = (signed int*)dst;
 	double *f64dst = (double*)dst;
 	jack_sample_t scale;
@@ -273,12 +283,15 @@ static void copy_and_convert_out (void *
 		}
 		break;
 	case 24:
-		scale = 0x7fffff;
+		scale = 0x7fffffff;
 		for (srcidx = 0; srcidx < nframes; srcidx++) {
-			s32dst[dstidx] = (signed int)
-					 (src[srcidx] >= 0.0f) ?
-					 (src[srcidx] * scale + 0.5f) :
-					 (src[srcidx] * scale - 0.5f);
+			signed int sample =
+				(src[srcidx] >= 0.0f) ?
+				(src[srcidx] * scale + 0.5f) :
+				(src[srcidx] * scale - 0.5f) ;
+			s24dst[3*dstidx + 2] = sample >> 24;
+			s24dst[3*dstidx + 1] = sample >> 16;
+			s24dst[3*dstidx + 0] = sample >> 8;
 			dstidx += chcount;
 		}
 		break;
@@ -429,7 +442,11 @@ static int oss_driver_detach (oss_driver
 
 static int oss_driver_start (oss_driver_t *driver)
 {
-	int flags = 0;
+#if defined(OPTION_COOKEDMODE)
+	int cookedmode = 1;
+#else
+	int cookedmode = 0;
+#endif
 	int format;
 	int channels;
 	int samplerate;
@@ -441,19 +458,7 @@ static int oss_driver_start (oss_driver_
 	const char *indev = driver->indev;
 	const char *outdev = driver->outdev;
 
-	switch (driver->bits) {
-	case 24:
-	case 32:
-		samplesize = sizeof(int);
-		break;
-	case 64:
-		samplesize = sizeof(double);
-		break;
-	case 16:
-	default:
-		samplesize = sizeof(short);
-		break;
-	}
+	samplesize = driver->bits / 8;
 	driver->trigger = 0;
 	if (strcmp (indev, outdev) != 0) {
 		if (driver->capture_channels > 0) {
@@ -464,7 +469,7 @@ static int oss_driver_start (oss_driver_
 					indev, __FILE__, __LINE__, errno);
 			}
 #ifndef OSS_NO_COOKED_MODE
-			ioctl (infd, SNDCTL_DSP_COOKEDMODE, &flags);
+			ioctl (infd, SNDCTL_DSP_COOKEDMODE, &cookedmode);
 #endif
 			fragsize = driver->period_size *
 				   driver->capture_channels * samplesize;
@@ -479,7 +484,7 @@ static int oss_driver_start (oss_driver_
 					outdev, __FILE__, __LINE__, errno);
 			}
 #ifndef OSS_NO_COOKED_MODE
-			ioctl (outfd, SNDCTL_DSP_COOKEDMODE, &flags);
+			ioctl (outfd, SNDCTL_DSP_COOKEDMODE, &cookedmode);
 #endif
 			fragsize = driver->period_size *
 				   driver->playback_channels * samplesize;
@@ -497,7 +502,7 @@ static int oss_driver_start (oss_driver_
 				return -1;
 			}
 #ifndef OSS_NO_COOKED_MODE
-			ioctl (infd, SNDCTL_DSP_COOKEDMODE, &flags);
+			ioctl (infd, SNDCTL_DSP_COOKEDMODE, &cookedmode);
 #endif
 		} else if (driver->capture_channels == 0 &&
 			   driver->playback_channels != 0) {
@@ -510,7 +515,7 @@ static int oss_driver_start (oss_driver_
 				return -1;
 			}
 #ifndef OSS_NO_COOKED_MODE
-			ioctl (outfd, SNDCTL_DSP_COOKEDMODE, &flags);
+			ioctl (outfd, SNDCTL_DSP_COOKEDMODE, &cookedmode);
 #endif
 		} else {
 			infd = outfd = open (indev, O_RDWR | O_EXCL);
@@ -521,7 +526,7 @@ static int oss_driver_start (oss_driver_
 				return -1;
 			}
 #ifndef OSS_NO_COOKED_MODE
-			ioctl (infd, SNDCTL_DSP_COOKEDMODE, &flags);
+			ioctl (infd, SNDCTL_DSP_COOKEDMODE, &cookedmode);
 #endif
 		}
 		if (infd >= 0 && outfd >= 0) {
@@ -705,7 +710,9 @@ static int oss_driver_start (oss_driver_
 		sem_post (&driver->sem_start);
 	}
 
-	driver->last_periodtime = driver->engine->get_microseconds ();
+	driver->last_periodtime = driver->engine ?
+		driver->engine->get_microseconds() :
+		jack_get_microseconds();
 	driver->next_periodtime = 0;
 	driver->iodelay = 0.0F;
 
@@ -1143,6 +1150,23 @@ jack_driver_t * driver_initialize (jack_
 		pnode = jack_slist_next (pnode);
 	}
 
+	switch (bits)
+	{
+	case 16:        /* native-endian 16-bit integer */
+		driver->format = AFMT_S16_NE;
+		break;
+	case 24:        /* little-endian 24-bit integer */
+		driver->format = AFMT_S24_LE;
+		break;
+	case 32:        /* native-endian 32-bit integer */
+		driver->format = AFMT_S32_NE;
+		break;
+	default:
+		free(driver);
+		jack_error("OSS: invalid number of bits: %d",
+			   __FILE__, __LINE__, bits);
+		return NULL;
+	}
 	driver->sample_rate = sample_rate;
 	driver->period_size = period_size;
 	driver->nperiods = nperiods;
@@ -1163,58 +1187,6 @@ jack_driver_t * driver_initialize (jack_
 	}
 	driver->infd = -1;
 	driver->outfd = -1;
-	switch (driver->bits) {
-#               ifndef OSS_ENDIAN
-#               ifdef __GNUC__
-#               if (defined(__i386__) || defined(__alpha__) || defined(__arm__) || defined(__x86_64__) || (defined(__sh__) && !defined(__LITTLE_ENDIAN__)))
-#               define OSS_LITTLE_ENDIAN 1234
-#               define OSS_ENDIAN OSS_LITTLE_ENDIAN
-#               else
-#               define OSS_BIG_ENDIAN 4321
-#               define OSS_ENDIAN OSS_BIG_ENDIAN
-#               endif
-#               else /* __GNUC__ */
-#               if (defined(_AIX) || defined(AIX) || defined(sparc) || defined(__hppa) || defined(PPC) || defined(__powerpc__) && !defined(i386) && !defined(__i386) && !defined(__i386__))
-#               define OSS_BIG_ENDIAN 4321
-#               define OSS_ENDIAN OSS_BIG_ENDIAN
-#               else
-#               define OSS_LITTLE_ENDIAN 1234
-#               define OSS_ENDIAN OSS_LITTLE_ENDIAN
-#               endif
-#               endif   /* __GNUC__ */
-#               endif   /* OSS_ENDIAN */
-#               if (OSS_ENDIAN == 1234)
-	/* little-endian architectures */
-	case 24:                /* little-endian LSB aligned 24-bits in 32-bits  integer */
-		driver->format = 0x00008000;
-		break;
-	case 32:                /* little-endian 32-bit integer */
-		driver->format = 0x00001000;
-		break;
-	case 64:                /* native-endian 64-bit float */
-		driver->format = 0x00004000;
-		break;
-	case 16:                /* little-endian 16-bit integer */
-	default:
-		driver->format = 0x00000010;
-		break;
-		/* big-endian architectures */
-#               else
-	case 24:                /* big-endian LSB aligned 24-bits in 32-bits integer */
-		break;
-		driver->format = 0x00010000;
-	case 32:                /* big-endian 32-bit integer */
-		driver->format = 0x00002000;
-		break;
-	case 64:                /* native-endian 64-bit float */
-		driver->format = 0x00004000;
-		break;
-	case 16:                /* big-endian 16-bit integer */
-	default:
-		driver->format = 0x00000020;
-#               endif
-	}
-
 	driver->indevbuf = driver->outdevbuf = NULL;
 
 	driver->capture_ports = NULL;
