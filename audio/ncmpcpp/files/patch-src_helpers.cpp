--- src/helpers.cpp.orig	2015-11-04 20:01:29 UTC
+++ src/helpers.cpp
@@ -26,6 +26,7 @@
 #include "playlist.h"
 #include "statusbar.h"
 #include "utility/functional.h"
+#include "format_impl.h"
 
 const MPD::Song *currentSong(const BaseScreen *screen)
 {
