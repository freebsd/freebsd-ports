--- TclmIntp.cxx.orig	1996-07-28 19:09:03 UTC
+++ TclmIntp.cxx
@@ -37,8 +37,7 @@
 #endif
 #include "TclmIntp.h"
 
-TclmInterp::TclmInterp() : current_song(0), current_dev(0), current_patch(0),
-    next_event(0)
+TclmInterp::TclmInterp() : current_song(0), current_dev(0), current_patch(0)
 {
 
 	Tcl_InitHashTable(&song_ht, TCL_STRING_KEYS);
