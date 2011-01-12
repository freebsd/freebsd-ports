--- fofi/FoFiTrueType.cc.orig	2010-12-29 12:13:14.000000000 -0800
+++ fofi/FoFiTrueType.cc	2010-12-29 12:15:15.000000000 -0800
@@ -906,7 +906,7 @@
   // check for an incorrect cmap table length
   badCmapLen = gFalse;
   cmapLen = 0; // make gcc happy
-  if (!missingCmap) {
+  if (!missingCmap && cmaps != NULL && nCmaps != 0) {
     cmapLen = cmaps[0].offset + cmaps[0].len;
     for (i = 1; i < nCmaps; ++i) {
       if (cmaps[i].offset + cmaps[i].len > cmapLen) {
