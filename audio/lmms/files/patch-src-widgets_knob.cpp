--- src/widgets/knob.cpp.orig	2009-04-11 22:43:48.000000000 +0200
+++ src/widgets/knob.cpp	2009-04-11 22:44:54.000000000 +0200
@@ -471,7 +471,7 @@
 			eng()->getMainWindow()->isShiftPressed() == TRUE )
 	{
 		new stringPairDrag( "link_object",
-						QString::number( (uint) this ),
+						QString::number( (intptr_t) this ),
 						QPixmap(), this, eng() );
 	}
 	else if( _me->button() == Qt::MidButton )
