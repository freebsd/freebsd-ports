--- smf/SMFTrack.cxx.orig	1996-08-05 03:47:36 UTC
+++ smf/SMFTrack.cxx
@@ -355,7 +355,8 @@ SMFTrack::IncreaseSize(long len)
 ostream &
 operator<<(ostream &os, const SMFTrack &t)
 {
-	long i, prev_flags;
+	std::ios_base::fmtflags prev_flags;
+	long i;
 	int prev_width;
 	unsigned char *ptr;
 
