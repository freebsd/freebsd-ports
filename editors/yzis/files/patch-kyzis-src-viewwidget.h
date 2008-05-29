--- kyzis/src/viewwidget.h.orig	2008-05-18 18:52:01.119247190 +0200
+++ kyzis/src/viewwidget.h	2008-05-18 18:52:14.123333743 +0200
@@ -77,8 +77,8 @@
 		 */
 		void setkid( int kId ) { mkId = kId; }
 
-		void KYZisView::wheelEvent( QWheelEvent * e );
-		void KYZisView::contextMenuEvent( QContextMenuEvent * e );
+		void wheelEvent( QWheelEvent * e );
+		void contextMenuEvent( QContextMenuEvent * e );
 
 		/**
 		 * @internal
