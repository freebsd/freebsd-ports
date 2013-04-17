--- src/libjasper/jpc/jpc_tagtree.c.orig	2007-01-19 22:43:07.000000000 +0100
+++ src/libjasper/jpc/jpc_tagtree.c	2013-04-17 22:32:23.000000000 +0200
@@ -125,7 +125,7 @@
 		++numlvls;
 	} while (n > 1);
 
-	if (!(tree->nodes_ = jas_malloc(tree->numnodes_ * sizeof(jpc_tagtreenode_t)))) {
+	if (!(tree->nodes_ = jas_malloc2(tree->numnodes_, sizeof(jpc_tagtreenode_t)))) {
 		return 0;
 	}
 
