--- misc.cpp.orig	Sun Sep 26 22:45:57 2004
+++ misc.cpp	Sat Jan 15 12:30:23 2005
@@ -223,13 +223,13 @@
 		if (pix.width()>max_w)
 		{
 			r=max_w / pix.width();
-			pix.resize(lrint(pix.width()*r), lrint(pix.height()*r));
+			pix.resize((long)rint(pix.width()*r), (long)rint(pix.height()*r));
 			// TODO not a resize, but a shrink/enlarge is needed here...
 		}
 		if (pix.height()>max_h)
 		{
 			r=max_h / pix.height();
-			pix.resize(lrint(pix.width()*r), lrint(pix.height()*r));
+			pix.resize((long)rint(pix.width()*r), (long)rint(pix.height()*r));
 			// TODO not a resize, but a shrink/enlarge is needed here...
 		}
         setPixmap( pix );
