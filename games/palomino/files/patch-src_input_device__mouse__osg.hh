--- src/input/device_mouse_osg.hh.orig	2011-12-14 01:56:48 UTC
+++ src/input/device_mouse_osg.hh
@@ -41,7 +41,6 @@ private:
                         HandlerOSG( void ) { }
         virtual         ~HandlerOSG() { }
         virtual bool    handle( const osgGA::GUIEventAdapter& event, osgGA::GUIActionAdapter& action );
-        virtual void    accept( osgGA::GUIEventHandlerVisitor& visitor );
     };
 };
 
