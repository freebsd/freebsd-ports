--- TclmIntp.cxx.orig	2013-05-14 11:25:42.000000000 +0200
+++ TclmIntp.cxx	2013-05-14 11:25:49.000000000 +0200
@@ -37,8 +37,7 @@
 #endif
 #include "TclmIntp.h"
 
-TclmInterp::TclmInterp() : current_song(0), current_dev(0), current_patch(0),
-    next_event(0)
+TclmInterp::TclmInterp() : current_song(0), current_dev(0), current_patch(0)
 {
 
 	Tcl_InitHashTable(&song_ht, TCL_STRING_KEYS);
