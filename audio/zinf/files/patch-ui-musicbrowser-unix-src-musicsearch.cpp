--- ui/musicbrowser/unix/src/musicsearch.cpp.orig	Thu Feb  5 07:06:40 2004
+++ ui/musicbrowser/unix/src/musicsearch.cpp	Mon Feb 16 14:08:17 2004
@@ -33,7 +33,9 @@
 #include "eventdata.h"
 #include "fileselector.h"
 #include "musiccatalog.h"
+#ifdef EXPERIMENTAL
 #include "musicdb.h"
+#endif
 #include "musicsearchui.h"
 #include "musicbrowserui.h"
 
