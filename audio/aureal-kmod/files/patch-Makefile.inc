
$FreeBSD$

--- Makefile.inc.orig	Mon Jan 15 18:44:49 2001
+++ Makefile.inc	Mon Jan 15 18:44:49 2001
@@ -0,0 +1,9 @@
+.PATH:	 /sys/dev/sound/pci ${WRKSRC}
+
+KMODDIR	 = ${PREFIX}/lib/au88x0
+SRCS	 = device_if.h bus_if.h isa_if.h pci_if.h
+SRCS	+= au88x0.c
+.if ${OSVERSION} > 500000
+SRCS	+= ac97_if.h channel_if.h feeder_if.h mixer_if.h
+.endif
+CFLAGS	+= -I${WRKSRC}
