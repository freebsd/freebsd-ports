libcdio-paranoia header location changed after moving to separate project circa 2012
Fix warning: logical not is only applied to the left hand side of comparison

--- mythmusic/mythmusic/cdrip.cpp.orig	2018-02-01 11:15:37 UTC
+++ mythmusic/mythmusic/cdrip.cpp
@@ -8,8 +8,8 @@
 
 #include "config.h"
 #ifdef HAVE_CDIO
-# include <cdio/cdda.h>
-# include <cdio/paranoia.h>
+# include <cdio/paranoia/cdda.h>
+# include <cdio/paranoia/paranoia.h>
 #endif //def HAVE_CDIO
 
 // C++ includes
@@ -219,7 +219,7 @@ void CDRipperThread::run(void)
 {
     RunProlog();
 
-    if (!m_tracks->size() > 0)
+    if (!(m_tracks->size() > 0))
     {
         RunEpilog();
         return;
