--- code/bspc/linux-i386.mak.orig	2013-10-18 02:04:04.000000000 +0300
+++ code/bspc/linux-i386.mak	2013-10-18 02:04:18.000000000 +0300
@@ -8,7 +8,7 @@
 BASE_CFLAGS=-Dstricmp=strcasecmp
 
 #use these cflags to optimize it
-CFLAGS=$(BASE_CFLAGS) -m486 -O6 -ffast-math -funroll-loops \
+CFLAGS=$(BASE_CFLAGS) -m486 -O2 -ffast-math -funroll-loops \
 	-fomit-frame-pointer -fexpensive-optimizations -malign-loops=2 \
 	-malign-jumps=2 -malign-functions=2 -DLINUX -DBSPC
 #use these when debugging 
