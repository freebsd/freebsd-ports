--- libray/libtext/texture.c.orig	1992-02-10 12:04:02.000000000 +0900
+++ libray/libtext/texture.c	2013-05-28 22:41:59.000000000 +0900
@@ -162,7 +162,7 @@
 	*u = ptmp.x;
 	*v = ptmp.y;
 	if (dpdu == (Vector *)NULL || dpdv == (Vector *)NULL)
-		return;
+		return FALSE;
 	/*
 	 * Here's the ugly part.
 	 * Build initial UVN-->XYZ matrix...
