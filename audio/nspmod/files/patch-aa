--- dacio-linux.c.orig	Sun Sep 17 05:51:43 1995
+++ dacio-linux.c	Thu Aug 22 20:42:04 2002
@@ -3,7 +3,11 @@
 #include <fcntl.h>	/*O_WRONLY*/
 #include <sys/ioctl.h>	/*(ioctl)*/
 #include <unistd.h>	/*(write)*/
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <sys/soundcard.h> /*SNDCTL_XXX*/
+#else
+#include <machine/soundcard.h>
+#endif
 #include <errno.h>	/*EINTR*/
 #include "defs.h"	/*u8,u16*/
 #include "dacio.h"	/*(dacioXXX)*/
@@ -47,7 +51,7 @@
 static struct {
     union {
 	u8 *p8;
-	u16 *p16;
+	i15 *p16;
     } p;
     u8 *top;
     u8 *bot;
@@ -67,11 +71,39 @@
 	exit(1);
     }
 #endif
-    tmp = AFMT_U8;
+    switch (dcp->bits) {
+    case 0:
+    case 8:
+	dcp->bits = 8;
+	tmp = AFMT_U8; break;
+    case 16:
+	tmp = AFMT_S16_LE; break;
+    default:
+	fprintf(stderr, "Don't know how to handle %d bit output.\n", dcp->bits);
+	exit(1);
+	break;
+    }
+
     if (ioctl(fd, SNDCTL_DSP_SETFMT, &tmp) < 0) {
 	perror("dacioConf");
 	exit(1);
     }
+
+    switch (tmp) {
+    case AFMT_U8:
+	if (dcp->bits != 8) {
+	    fprintf(stderr, "soundcard doesn't support 8bits.\n");
+	    exit(1);
+	}
+	break;
+    case AFMT_S16_LE:
+	if (dcp->bits != 16) {
+	    fprintf(stderr, "soundcard doesn't support 16bits.\n");
+	    exit(1);
+	}
+	break;
+    }
+
     /*fprintf(stderr, "fmt = 0x%x\n", tmp);*/
 
     if (ioctl(fd, SNDCTL_DSP_STEREO, &dcp->stereo) < 0) {
@@ -90,10 +122,15 @@
 	perror("dacioConf");
 	exit(1);
     }
+    /*fprintf(stderr, "sound buffer size = 0x%x\n", buf.size);*/
+    tmp = buf.size;
+    while (tmp <= (0.1 * (dcp->speed * (dcp->stereo+1) * (dcp->bits/8))))
+	tmp += buf.size;
+    buf.size = tmp;
     /*fprintf(stderr, "buffer size = 0x%x\n", buf.size);*/
     dci = *dcp;
     /*if (buf.top != NULL) free(buf.top);*/
-    buf.top = memPerm(buf.size * sizeof(u8));
+    buf.top = memPerm(buf.size);
     buf.p.p8 = buf.top;
     buf.bot = buf.top + buf.size;
 }
@@ -115,7 +152,14 @@
     int s;
 
     if (buf.p.p8 <= buf.top) return;
-    for ( ; buf.p.p8 < buf.bot; buf.p.p8++) *buf.p.p8 = 128;
+    switch (dci.bits) {
+    case 8:
+	for ( ; buf.p.p8 < buf.bot; buf.p.p8++) *buf.p.p8 = 128;
+	break;
+    case 16:
+	for ( ; buf.p.p8 < buf.bot; buf.p.p16++) *buf.p.p16 = 0;
+	break;
+    }
  RETRY:
     s = write(fd, buf.top, buf.size);
     if (s < buf.size) {
@@ -179,6 +223,8 @@
      (tmpvar & ~255)? ~tmpvar >> 16 : tmpvar ) /* 16 will be OK */
 /*                   ~(tmpvar >> 16) makes longer asm */
 #endif
+#define to16bit(x) \
+	(((x) * gv) >> 12)
 
 /* stereo */
 static void
@@ -186,14 +232,26 @@
 {
     const i31 *inbufp = inbuf.p;
     u8 *u8p = buf.p.p8;
+    i15 *s15p = buf.p.p16;
 
-    for (; n > 0; n--) {
-	i31x tmp;
-	*u8p++ = to8bit(*inbufp++, tmp); /* L */
-	*u8p++ = to8bit(*inbufp++, tmp); /* R */
+    switch (dci.bits) {
+    case 8:
+	for (; n > 0; n--) {
+	    i31x tmp;
+	    *u8p++ = to8bit(*inbufp++, tmp); /* L */
+	    *u8p++ = to8bit(*inbufp++, tmp); /* R */
+	}
+	buf.p.p8 = u8p;
+	break;
+    case 16:
+	for (; n > 0; n--) {
+	    *s15p++ = to16bit(*inbufp++); /* L */
+	    *s15p++ = to16bit(*inbufp++); /* R */
+	} 
+	buf.p.p16 = s15p;
+	break;
     }
     inbuf.p = inbufp;
-    buf.p.p8 = u8p;
 }
 
 /* mono */
@@ -202,19 +260,31 @@
 {
     const i31 *inbufp = inbuf.p;
     u8 *u8p = buf.p.p8;
+    i15 *s16p = buf.p.p16;
 
-    for (; n > 0; n--) {
-	i31x tmp;
-	*u8p++ = to8bit(*inbufp, tmp);
-	inbufp += 2;
+    switch (dci.bits) {
+    case 8:
+	for (; n > 0; n--) {
+	    i31x tmp;
+	    *u8p++ = to8bit(*inbufp, tmp);
+	    inbufp += 2;
+	}
+	buf.p.p8 = u8p;
+	break;
+    case 16:
+	for (; n > 0; n--) {
+	    *s16p++ = to16bit(*inbufp);
+	    inbufp += 2;
+	}
+	buf.p.p16 = s16p;
+	break;
     }
     inbuf.p = inbufp;
-    buf.p.p8 = u8p;
 }
 
 #define dacioOutHirev(x) \
     if (dci.stereo) dacioOutHirevS(x); else dacioOutHirevM(x)
-#define bufRest() (dci.stereo? (buf.bot - buf.p.p8)/2 : buf.bot - buf.p.p8)
+#define bufRest() ((dci.stereo? (buf.bot - buf.p.p8)/2 : buf.bot - buf.p.p8)/(dci.bits/8))
 
 void
 dacioOut(void)
