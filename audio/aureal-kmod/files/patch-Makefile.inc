
$FreeBSD$

--- Makefile.inc.orig	Tue Jan 16 20:33:37 2001
+++ Makefile.inc	Tue Jan 16 20:35:06 2001
@@ -0,0 +1,11 @@
+.PATH:	 /sys/dev/sound/pci ${WRKSRC}
+
+KMODDIR	 = ${PREFIX}/lib/au88x0
+KMOD	 = snd_au88${MODEL}
+SRCS	+= au88x0.c
+SRCS	+= device_if.h bus_if.h isa_if.h pci_if.h
+.if ${OSVERSION} > 500000 || defined(HAVE_KOBJ_PCM)
+SRCS	+= ac97_if.h channel_if.h feeder_if.h mixer_if.h
+.endif
+OBJS	 = ${WRKSRC}/asp${MODEL}.o
+CFLAGS	+= -I${WRKSRC}
