--- src/mod_video/crrc_animation.cpp.orig	2016-04-10 16:57:14 UTC
+++ src/mod_video/crrc_animation.cpp
@@ -84,7 +84,7 @@ void createAnimation(SimpleXMLTransfer *
       else
       {
         std::cerr << "createAnimation: unknown animation type \'"
-                  << type << "\'" << std::cerr;
+                  << type << "\'" << std::endl;
       }
       
       if (anim != NULL)
