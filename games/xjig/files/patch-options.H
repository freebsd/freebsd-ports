--- objects.H.orig	Wed Jul 24 15:08:44 1996
+++ objects.H	Tue Apr  7 15:34:33 1998
@@ -241,6 +241,7 @@
 	protected:
 		void CreateTilemap8();
 		void CreateTilemap16();
+		void CreateTilemap24();
 		void CreateTilemap32();
 
 		Pixmap	tilemap;
