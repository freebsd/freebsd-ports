--- src/Core/NSFileManagerOOExtensions.h.orig	2012-04-18 09:43:45.361891055 +0300
+++ src/Core/NSFileManagerOOExtensions.h	2012-04-18 09:44:08.916890086 +0300
@@ -28,7 +28,7 @@ MA 02110-1301, USA.
 
 #import <Foundation/Foundation.h>
 
-#define SAVEDIR "oolite-saves"
+#define SAVEDIR ".oolite-saves"
 
 #if OOLITE_SDL
 #define SNAPSHOTDIR "snapshots"
