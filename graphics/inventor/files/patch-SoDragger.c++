--- lib/interaction/src/draggers/SoDragger.c++.orig	2011-06-08 14:34:05.000000000 +0200
+++ lib/interaction/src/draggers/SoDragger.c++	2011-06-08 14:34:13.000000000 +0200
@@ -686,7 +686,7 @@
 		int indexInPath = tempPathToThis->getIndex(numFmHead+1);
 
 		int numKidsNow    = children->getLength();
-#if (_MIPS_SZPTR == 64 || __ia64)
+#if (_MIPS_SZPTR == 64 || __ia64 || __amd64__)
 		int numKidsBefore = (int) ((long) (*tempPathNumKidsHack)[numFmHead]);
 #else
 		int numKidsBefore = (int) (*tempPathNumKidsHack)[numFmHead];
