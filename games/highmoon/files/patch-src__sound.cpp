--- ./src/sound.cpp.orig	2006-03-25 22:10:32.000000000 +0100
+++ ./src/sound.cpp	2014-04-15 17:58:18.532919123 +0200
@@ -27,6 +27,10 @@
 
 #include "sound.hpp"
 
+#ifdef __clang__
+#pragma clang diagnostic ignored "-Wtautological-constant-out-of-range-compare"
+#endif
+
 Soundset::Sample Soundset::sounds[ NUMBEROFCHANNELS ];
 bool Soundset::soundOn = true;
 
