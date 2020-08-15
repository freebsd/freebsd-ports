--- squeezelite.h.orig	2020-06-07 11:03:51 UTC
+++ squeezelite.h
@@ -191,7 +191,6 @@
 
 #if LINUX
 #define LIBFLAC "libFLAC.so.8"
-#define LIBMAD  "libmad.so.0"
 #define LIBMPG "libmpg123.so.0"
 #define LIBVORBIS "libvorbisfile.so.3"
 #define LIBOPUS "libopusfile.so.0"
@@ -206,7 +205,6 @@
 
 #if OSX
 #define LIBFLAC "libFLAC.8.dylib"
-#define LIBMAD  "libmad.0.dylib"
 #define LIBMPG "libmpg123.0.dylib"
 #define LIBVORBIS "libvorbisfile.3.dylib"
 #define LIBTREMOR "libvorbisidec.1.dylib"
@@ -220,7 +218,6 @@
 
 #if WIN
 #define LIBFLAC "libFLAC.dll"
-#define LIBMAD  "libmad-0.dll"
 #define LIBMPG "libmpg123-0.dll"
 #define LIBVORBIS "libvorbisfile.dll"
 #define LIBOPUS "libopusfile-0.dll"
@@ -234,7 +231,6 @@
 
 #if FREEBSD
 #define LIBFLAC "libFLAC.so.8"
-#define LIBMAD  "libmad.so.0"
 #define LIBMPG "libmpg123.so.0"
 #define LIBVORBIS "libvorbisfile.so.3"
 #define LIBTREMOR "libvorbisidec.so.1"
