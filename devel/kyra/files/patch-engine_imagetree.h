--- engine/imagetree.h.orig	2005-03-31 01:02:38 UTC
+++ engine/imagetree.h
@@ -190,7 +190,7 @@ class KrImageTree
 	void Clear( KrImNode* root );	// delete the entire tree
 
 	// Recursive hit test walk.
-	bool KrImageTree::HitTestRec( KrImNode* node, int x, int y, int flags, std::vector<KrImage*>* outputArray, int windowIndex );
+	bool HitTestRec( KrImNode* node, int x, int y, int flags, std::vector<KrImage*>* outputArray, int windowIndex );
 
 	KrImNode*  root;			// The root to position the window
 	KrImNode*  offsetRoot;		// The root as returned to the client
