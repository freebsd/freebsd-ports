--- Makefile.inc.orig	2016-07-26 13:37:02 UTC
+++ Makefile.inc
@@ -0,0 +1,14 @@
+.PATH: /sys/dev/sound/pci ${WRKSRC}
+
+KMODDIR=	${PREFIX}/lib/au88x0
+KMOD=	snd_au88${MODEL}
+.if ${OSVERSION} < 500000
+KMODDEPS=	snd_pcm
+.endif
+SRCS+=	au88x0.c
+SRCS+=	device_if.h bus_if.h isa_if.h pci_if.h
+.if ${OSVERSION} > 500000 || defined(HAVE_KOBJ_PCM)
+SRCS+=	ac97_if.h channel_if.h feeder_if.h mixer_if.h
+.endif
+OBJS=	${WRKSRC}/asp${MODEL}.o
+CFLAGS+=	-I${WRKSRC}
