--- smf/SMFTrack.cxx.orig	1996-08-05 05:47:36.000000000 +0200
+++ smf/SMFTrack.cxx	2013-09-24 09:53:53.000000000 +0200
@@ -355,7 +355,8 @@
 ostream &
 operator<<(ostream &os, const SMFTrack &t)
 {
-	long i, prev_flags;
+	std::ios_base::fmtflags prev_flags;
+	long i;
 	int prev_width;
 	unsigned char *ptr;
 
