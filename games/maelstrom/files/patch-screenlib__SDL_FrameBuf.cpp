--- ./screenlib/SDL_FrameBuf.cpp.orig	2001-07-22 23:03:13.000000000 +0200
+++ ./screenlib/SDL_FrameBuf.cpp	2013-12-28 11:39:16.000000000 +0100
@@ -628,7 +628,7 @@
 
 		found = 0;
 		for ( which=0; !found; ++which ) {
-			sprintf(file, "%s%d.bmp", prefix, which);
+			snprintf(file, sizeof(file), "%s%d.bmp", prefix, which);
 			if ( ((fp=fopen(file, "r")) == NULL) &&
 			     ((fp=fopen(file, "w")) != NULL) ) {
 				found = 1;
@@ -847,10 +847,8 @@
 			/* Update the dirty rectangle map with the new list */
 			for ( i=0; i<dirtymaplen; ++i ) {
 				if ( dirtymap[i] != NULL ) {
-					dirtymap[i] = (SDL_Rect *)(
-					((int)dirtymap[i]-(int)updatelist) +
-								(int)newlist
-					);
+					dirtymap[i] = newlist
+						+ (dirtymap[i]-updatelist);
 				}
 			}
 			delete[] updatelist;
