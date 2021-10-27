--- engine/encoder.h.orig	2005-03-31 01:02:36 UTC
+++ engine/encoder.h
@@ -148,7 +148,7 @@ class KrEncoder
 														GLASSERT( numRGBA >= numSegment );
 //														GLASSERT( numSegment >= numLine );
 													 }
-	void KrEncoder::Save();
+	void Save();
 
 	KrResourceVault* GetVault()						{ return &vault; }
 
