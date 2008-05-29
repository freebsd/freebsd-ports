--- libyzis/linesearch.h.orig	2008-05-18 18:47:35.318978999 +0200
+++ libyzis/linesearch.h	2008-05-18 18:47:47.858303411 +0200
@@ -70,7 +70,7 @@
 	/**
 	 * Searches for previously searched character in opposite direction
 	 */
-	YZCursor YZLineSearch::searchAgainOpposite( bool &found, unsigned int times );
+	YZCursor searchAgainOpposite( bool &found, unsigned int times );
 	
 	/**
 	 * Defines types of searches for history
