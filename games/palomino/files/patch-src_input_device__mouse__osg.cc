--- src/input/device_mouse_osg.cc.orig	2012-10-26 01:35:57 UTC
+++ src/input/device_mouse_osg.cc
@@ -145,12 +145,6 @@ MouseDeviceOSG::HandlerOSG::handle( cons
     }
 }
 
-void
-MouseDeviceOSG::HandlerOSG::accept( osgGA::GUIEventHandlerVisitor& v )
-{
-    v.visit( *this );
-}
-
 } // namespace input
 
 #endif // COMPILE_OSG
