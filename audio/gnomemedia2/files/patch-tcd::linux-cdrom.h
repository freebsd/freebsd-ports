
$FreeBSD$

--- tcd/linux-cdrom.h	2001/07/13 09:27:50	1.1
+++ tcd/linux-cdrom.h	2001/07/13 09:34:48
@@ -27,8 +27,20 @@
 
 #include <sys/types.h>
 #include <glib.h>
-#if !defined(linux) && !defined(sun) && !defined(__sun__)
-# error TCD only builds on linux and Solaris/SunOs
+#if !defined(linux) && !defined(sun) && !defined(__sun__) && !defined(__FreeBSD__)
+# error TCD only builds on linux, Solaris/SunOs and FreeBSD
+#endif
+
+#ifdef __FreeBSD__
+#define TCD_BSD
+#include <sys/cdio.h>
+#define CDROM_AUDIO_INVALID     CD_AS_AUDIO_INVALID
+#define CDROM_AUDIO_PLAY        CD_AS_PLAY_IN_PROGRESS
+#define CDROM_AUDIO_PAUSED      CD_AS_PLAY_PAUSED
+#define CDROM_AUDIO_COMPLETED   CD_AS_PLAY_COMPLETED
+#define CDROM_AUDIO_ERROR       CD_AS_PLAY_ERROR
+#define CDROM_AUDIO_NO_STATUS   CD_AS_NO_STATUS
+#define CDROM
 #endif
 
 #ifdef linux
@@ -126,7 +138,17 @@
 {
 	char name[TRK_NAME_LEN+1];
 	char extd[EXT_DATA_LEN+1];      /* extra information for this track */
+#ifdef TCD_BSD
+	struct cd_toc_entry toc;
+#define TOC_MINUTE(trk)        (trk.toc.addr.msf.minute)
+#define TOC_SECOND(trk)        (trk.toc.addr.msf.second)
+#define TOC_FRAME(trk)         (trk.toc.addr.msf.frame)
+#else
 	struct cdrom_tocentry toc;
+#define TOC_MINUTE(trk)        (trk.toc.cdte_addr.msf.minute)
+#define TOC_SECOND(trk)        (trk.toc.cdte_addr.msf.second)
+#define TOC_FRAME(trk)         (trk.toc.cdte_addr.msf.frame)
+#endif
 	int titled;
 	int start, length;
 	int tot_min, tot_sec;
@@ -152,10 +174,26 @@
 	char album[DISC_INFO_LEN+1], artist[DISC_INFO_LEN+1];
 	char extd[EXT_DATA_LEN+1];      /* extra information for this disc */
 
+#ifdef TCD_BSD
+	/* See /usr/include/sys/cdio.h */
+	struct ioc_play_track ti;
+	struct ioc_toc_header tochdr;
+	struct cd_sub_channel_info sc;
+#define SC_AUDIOSTATUS(sc)     (sc.header.audio_status)
+#define SC_TRACK(sc)           (sc.what.position.track_number)
+#define SC_MINUTE(sc)          (sc.what.position.absaddr.msf.minute)
+#define SC_SECOND(sc)          (sc.what.position.absaddr.msf.second)
+#define SC_FRAME(sc)           (sc.what.position.absaddr.msf.frame)
+#else
 	/* See /usr/src/linux/include/linux/cdrom.h */
 	struct cdrom_ti ti;		/* Track info */
 	struct cdrom_tochdr tochdr; 	/* TOC header */
 	struct cdrom_subchnl sc;	/* Subchannel, for time */
+#define SC_AUDIOSTATUS(sc)     (sc.cdsc_audiostatus)
+#define SC_TRACK(sc)           (sc.cdsc_trk)
+#define SC_SECOND(sc)          (sc.cdsc_absaddr.msf.second)
+#define SC_FRAME(sc)           (sc.cdsc_absaddr.msf.frame)
+#endif
 	int volume;			/* Must range 0-100 */
 
 	int cd_min, cd_sec;		/* Total CD time */
