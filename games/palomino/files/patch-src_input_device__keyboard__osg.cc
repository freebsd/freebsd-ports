--- src/input/device_keyboard_osg.cc.orig	2012-10-26 01:35:57 UTC
+++ src/input/device_keyboard_osg.cc
@@ -105,12 +105,6 @@ KeyboardDeviceOSG::HandlerOSG::handle( c
     }
 }
 
-void
-KeyboardDeviceOSG::HandlerOSG::accept( osgGA::GUIEventHandlerVisitor& v )
-{
-    v.visit( *this );
-}
-
 } // namespace input
 
 #endif // COMPILE_OSG
