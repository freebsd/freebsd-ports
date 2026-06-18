--- src/slic3r/GUI/BBLTopbar.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/BBLTopbar.cpp
@@ -125,9 +125,12 @@
     int bmpX = 0, bmpY = 0;
     int textX = 0, textY = 0;
 
+    // Fetch the bitmap via the bundle with the real toolbar window. item.GetBitmap()/
+    // GetDisabledBitmap() use the item's own window (NULL for normal buttons), which trips wx's
+    // "window must be valid" assert in wxBitmapBundle::GetPreferredBitmapSizeFor().
     const wxBitmap& bmp = item.GetState() & wxAUI_BUTTON_STATE_DISABLED
-        ? item.GetDisabledBitmap()
-        : item.GetBitmap();
+        ? item.GetDisabledBitmapBundle().GetBitmapFor(wnd)
+        : item.GetBitmapBundle().GetBitmapFor(wnd);
 
     const wxSize bmpSize = bmp.IsOk() ? bmp.GetScaledSize() : wxSize(0, 0);
 
