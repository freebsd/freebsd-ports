--- punc.c.orig	Mon Dec 29 02:10:25 2003
+++ punc.c	Fri Jan  9 21:37:48 2004
@@ -85,11 +85,11 @@
  */
 int IsPunc (int iKey)
 {
+    int             iIndex = 0;
+
     if ( !chnPunc )
 	return -1;
     
-    int             iIndex = 0;
-
     while (chnPunc[iIndex].ASCII) {
 	if (chnPunc[iIndex].ASCII == iKey)
 	    return iIndex;
