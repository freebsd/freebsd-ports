--- ./libcnary/node.c.orig	2012-01-29 11:49:28.786656365 +0100
+++ ./libcnary/node.c	2012-01-29 11:53:54.146697468 +0100
@@ -104,7 +104,7 @@
 
 int node_insert(node_t* parent, unsigned int index, node_t* child)
 {
-	if (!parent || !child) return;
+	if (!parent || !child) return -1;
 	child->isLeaf = TRUE;
 	child->isRoot = FALSE;
 	child->parent = parent;
