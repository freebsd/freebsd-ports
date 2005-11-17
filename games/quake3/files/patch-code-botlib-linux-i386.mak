diff -ruN ./code/botlib/linux-i386.mak ../quake3-1.32b-BUILT/./code/botlib/linux-i386.mak
--- ./code/botlib/linux-i386.mak	Wed May 23 15:07:59 2001
+++ ../quake3-1.32b-BUILT/./code/botlib/linux-i386.mak	Mon Aug 22 20:55:02 2005
@@ -14,7 +14,7 @@
 #use these when debugging 
 #CFLAGS=$(BASE_CFLAGS) -g
 
-LDFLAGS=-ldl -lm
+LDFLAGS=-lm
 SHLIBEXT=so
 SHLIBCFLAGS=-fPIC
 SHLIBLDFLAGS=-shared
