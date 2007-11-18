--- engine/encoder.h.orig	2007-11-12 17:25:45.000000000 +0100
+++ engine/encoder.h	2007-11-12 17:25:59.000000000 +0100
@@ -185,7 +185,7 @@
 														GLASSERT( numRGBA >= numSegment );
 //														GLASSERT( numSegment >= numLine );
 													 }
-	void KrEncoder::Save();
+	void Save();
 
 	KrResourceVault* GetVault()						{ return &vault; }
 
