--- libray/libtext/texture.c.orig	1992-02-10 03:04:02 UTC
+++ libray/libtext/texture.c
@@ -162,7 +162,7 @@ Float *u, *v;
 	*u = ptmp.x;
 	*v = ptmp.y;
 	if (dpdu == (Vector *)NULL || dpdv == (Vector *)NULL)
-		return;
+		return FALSE;
 	/*
 	 * Here's the ugly part.
 	 * Build initial UVN-->XYZ matrix...
