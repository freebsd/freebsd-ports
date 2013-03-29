--- src/throb/throb.cxx.orig	2013-03-28 13:27:03.683043974 -0400
+++ src/throb/throb.cxx	2013-03-28 13:27:55.988221471 -0400
@@ -37,6 +37,8 @@
 #include "fl_digi.h"
 #include "status.h"
 
+#define MAX_TONES	15	// Highest used I noticed was 11
+
 #undef  CLAMP
 #define CLAMP(x,low,high)       (((x)>(high))?(high):(((x)<(low))?(low):(x)))
 
@@ -410,7 +412,7 @@
 
 void throb::rx(complex in)
 {
-	complex rxword[num_tones];
+	complex rxword[MAX_TONES];
 	int i, tone1, tone2, maxtone;
 
 	symbol[symptr] = in;
