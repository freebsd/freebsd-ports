--- smf/SMFHead.cxx.orig	2013-09-24 09:16:20.000000000 +0200
+++ smf/SMFHead.cxx	2013-09-24 09:16:53.000000000 +0200
@@ -160,8 +160,8 @@
 	return (1);
 }
 
-ostream &
-operator<<(ostream &os, const SMFHead &h)
+std::ostream &
+operator<<(std::ostream &os, const SMFHead &h)
 {
 
 	os << "Format: " << h.format << " Num. Tracks: " << h.num_tracks
