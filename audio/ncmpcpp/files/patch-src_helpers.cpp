--- src/helpers.cpp.orig	2016-04-17 05:41:01 UTC
+++ src/helpers.cpp
@@ -26,6 +26,7 @@
 #include "playlist.h"
 #include "statusbar.h"
 #include "utility/functional.h"
+#include "format_impl.h"
 
 const MPD::Song *currentSong(const BaseScreen *screen)
 {
