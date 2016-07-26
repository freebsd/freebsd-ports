--- smf/SMFHead.cxx.orig	1996-08-05 03:47:35 UTC
+++ smf/SMFHead.cxx
@@ -160,8 +160,8 @@ SMFHead::Write(Tcl_Channel channel) cons
 	return (1);
 }
 
-ostream &
-operator<<(ostream &os, const SMFHead &h)
+std::ostream &
+operator<<(std::ostream &os, const SMFHead &h)
 {
 
 	os << "Format: " << h.format << " Num. Tracks: " << h.num_tracks
