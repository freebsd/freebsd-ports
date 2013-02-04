--- zot.c.orig
+++ zot.c
@@ -23,7 +23,7 @@
 	GC bgc;
 
 	if (!wflump)
-		return;
+		return(0);
 	zot(dx, dy, cmaps, cdpy, cscr, cgc, cwin, cmap);
 }
 
