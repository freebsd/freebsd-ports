--- source/streamsources/music_dumb.cpp.orig	2023-04-12 17:17:42 UTC
+++ source/streamsources/music_dumb.cpp
@@ -43,8 +43,8 @@
 
 
 #undef CDECL	// w32api's windef.h defines this
-#include "../dumb/include/dumb.h"
-#include "../dumb/include/internal/it.h"
+#include "dumb.h"
+#include "internal/it.h"
 #include "zmusic/m_swap.h"
 #include "zmusic/mididefs.h"
 #include "zmusic/midiconfig.h"
