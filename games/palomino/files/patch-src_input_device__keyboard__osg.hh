--- src/input/device_keyboard_osg.hh.orig	2009-11-22 23:05:48 UTC
+++ src/input/device_keyboard_osg.hh
@@ -57,7 +57,6 @@ private:
                         HandlerOSG( void ) { }
         virtual         ~HandlerOSG() { }
         virtual bool    handle( const osgGA::GUIEventAdapter& event, osgGA::GUIActionAdapter& action );
-        virtual void    accept( osgGA::GUIEventHandlerVisitor& visitor );
     };
 };
 
