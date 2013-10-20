--- code/botlib/linux-i386.mak.orig	2013-10-18 02:02:20.000000000 +0300
+++ code/botlib/linux-i386.mak	2013-10-18 02:02:35.000000000 +0300
@@ -8,7 +8,7 @@
 BASE_CFLAGS=-Dstricmp=strcasecmp
 
 #use these cflags to optimize it
-CFLAGS=$(BASE_CFLAGS) -m486 -O6 -ffast-math -funroll-loops \
+CFLAGS=$(BASE_CFLAGS) -m486 -O2 -ffast-math -funroll-loops \
 	-fomit-frame-pointer -fexpensive-optimizations -malign-loops=2 \
 	-malign-jumps=2 -malign-functions=2
 #use these when debugging 
