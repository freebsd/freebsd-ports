https://github.com/Beep6581/RawTherapee/commit/4221fdf31e43658cef98ad660ad398b8ae81b8d7

fix regression in Canon sRAW/mRAW black level computation, taken from…

… ART, fixes #5638

--- rtengine/dcraw.cc.orig	2020-02-04 06:39:52 UTC
+++ rtengine/dcraw.cc
@@ -9868,6 +9868,7 @@ void CLASS identify()
     filters = 0;
     tiff_samples = colors = 3;
     load_raw = &CLASS canon_sraw_load_raw;
+    FORC4 cblack[c] = 0; // ALB
   } else if (!strcmp(model,"PowerShot 600")) {
     height = 613;
     width  = 854;
