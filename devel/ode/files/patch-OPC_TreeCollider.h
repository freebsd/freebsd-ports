--- OPCODE/OPC_TreeCollider.h.orig	Mon May 23 20:11:48 2005
+++ OPCODE/OPC_TreeCollider.h	Mon May 23 20:16:16 2005
@@ -28,6 +28,13 @@
 	//! even entering the recursive collision code.
 	struct OPCODE_API BVTCache : Pair
 	{
+		inline_		void	ResetCountDown()
+							{
+#ifdef __MESHMERIZER_H__		// Collision hulls only supported within ICE !
+								CountDown		= 50;
+#endif // __MESHMERIZER_H__
+							}
+
 		//! Constructor
 		inline_				BVTCache()
 							{
@@ -46,13 +53,6 @@
 								SepVector.pid	= 0;
 								SepVector.qid	= 0;
 								SepVector.SV	= Point(1.0f, 0.0f, 0.0f);
-#endif // __MESHMERIZER_H__
-							}
-
-		inline_		void	ResetCountDown()
-							{
-#ifdef __MESHMERIZER_H__		// Collision hulls only supported within ICE !
-								CountDown		= 50;
 #endif // __MESHMERIZER_H__
 							}
 
