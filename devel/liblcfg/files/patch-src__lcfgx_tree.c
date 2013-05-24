--- ./src/lcfgx_tree.c.orig	2013-05-24 17:33:26.742836442 +0200
+++ ./src/lcfgx_tree.c	2013-05-24 17:33:48.764827155 +0200
@@ -41,17 +41,17 @@
 	return node;
 }
 
+static void sp(int n)
+{
+	int i;
+
+	for( i = 0; i < n; i++ )
+		printf("%c", ' ');
+}
 
 void lcfgx_tree_dump(struct lcfgx_tree_node *node, int depth)
 {
 //	printf("%s node %p node->key %s depth %i\n", __PRETTY_FUNCTION__, node, node->key, depth);
-	void sp(int n)
-	{
-		int i;
-
-		for( i = 0; i < n; i++ )
-			printf("%c", ' ');
-	}
 
 	sp(depth);
 	if( node->key != NULL )
