--- ffmpeg-strip-wma/config.mak.orig	Thu Feb 19 01:08:40 2004
+++ ffmpeg-strip-wma/config.mak	Tue Mar 16 15:30:59 2004
@@ -3,12 +3,12 @@
 bindir=/usr/bin
 mandir=/usr/share/man
 MAKE=make
-CC=gcc
+CC?=gcc
 AR=ar
 RANLIB=ranlib
 STRIP=strip
-OPTFLAGS=-Wall  -g -O3
-SHCFLAGS=-Wall  -g -O3
+OPTFLAGS=-Wall -O3
+SHCFLAGS=-Wall -O3
 LDFLAGS=-Wl,--warn-common -rdynamic
 FFSLDFLAGS=-Wl,-E
 SHFLAGS=-shared
