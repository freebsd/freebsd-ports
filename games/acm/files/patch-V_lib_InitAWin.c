--- V/lib/InitAWin.c.orig	1998-08-14 21:09:02 UTC
+++ V/lib/InitAWin.c
@@ -69,6 +69,13 @@ InitializeX11AWindow(Display * dpy, int screen, Drawab
 	w->csPool1 = (ColorSegment *) malloc(w->CSSize1 * sizeof(ColorSegment));
 	memset(w->csPool1, 0, w->CSSize1 * sizeof(ColorSegment));
 
+	// Initialize csPool2 so program doesn't crash later,
+	// when trying to free it.
+	{
+		w->CSSize2 = 0;
+		w->csPool2 = (ColorSegment *) NULL;
+	}
+
 	w->scanLine = (ScanLine *) malloc((w->height + 1) * sizeof(ScanLine));
 	w->lastScanLine = (ScanLine *) malloc((w->height + 1) * sizeof(ScanLine));
 	w->otherLastScanLine = NULL;
