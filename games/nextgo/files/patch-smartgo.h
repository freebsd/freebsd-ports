--- smartgo.h.orig	Sun Jan 12 05:01:52 2003
+++ smartgo.h	Sat Nov 18 17:18:57 2006
@@ -122,7 +122,7 @@
 extern node* parse_tree(char* inputBuffer);
 
 /*   Routines from smartgoeval.c needed by other routines.   */
-extern void evaluateNode(char *c, unsigned char b[][]);
+extern void evaluateNode(char *c, unsigned char b[19][19]);
 
 
 /*   Routines from smartgotree.c needed by other routines.  */
@@ -134,7 +134,7 @@
 extern node* forwardOneVariant(node* currentNode);
 extern node* backOneVariant(node* currentNode);
 extern void clearNodeFlags(node* currentNode);
-extern int evaluateSteps(node* currentNode, node* targetNode, unsigned char b[][]);
+extern int evaluateSteps(node* currentNode, node* targetNode, unsigned char b[19][19]);
 extern void buildToNode(node* targetNode);
 extern node* stepForward(node* currentNode);
 extern node* stepBackward(node* currentNode);
