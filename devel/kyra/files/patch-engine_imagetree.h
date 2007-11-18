--- engine/imagetree.h.orig	2007-11-12 17:22:54.000000000 +0100
+++ engine/imagetree.h	2007-11-12 17:23:06.000000000 +0100
@@ -217,7 +217,7 @@
 	void Clear( KrImNode* root );	// delete the entire tree
 
 	// Recursive hit test walk.
-	bool KrImageTree::HitTestRec( KrImNode* node, int x, int y, int flags, GlDynArray<KrImage*>* outputArray, int windowIndex );
+	bool HitTestRec( KrImNode* node, int x, int y, int flags, GlDynArray<KrImage*>* outputArray, int windowIndex );
 
 	KrImNode*  root;			// The root to position the window
 	KrImNode*  offsetRoot;		// The root as returned to the client
