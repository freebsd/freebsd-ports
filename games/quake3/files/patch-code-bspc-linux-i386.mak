diff -ruN ./code/bspc/linux-i386.mak ../quake3-1.32b-BUILT/./code/bspc/linux-i386.mak
--- ./code/bspc/linux-i386.mak	Wed May 23 15:07:59 2001
+++ ../quake3-1.32b-BUILT/./code/bspc/linux-i386.mak	Mon Aug 22 20:54:48 2005
@@ -14,7 +14,7 @@
 #use these when debugging 
 #CFLAGS=$(BASE_CFLAGS) -g
 
-LDFLAGS=-ldl -lm -lpthread
+LDFLAGS=-lm -lpthread
 
 DO_CC=$(CC) $(CFLAGS) -o $@ -c $<
 
