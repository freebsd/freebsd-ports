--- ./toolkit/source/awt/animatedimagespeer.cxx.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./toolkit/source/awt/animatedimagespeer.cxx	2012-04-16 15:40:08.000000000 +0200
@@ -219,7 +219,7 @@
                             ||  ( !lcl_ensureImage_throw( xGraphicProvider, isHighContrast, rImageSet[0] ) )
                             )
                         {
-                            aImageSizes[ nImageSet ] = Size( ::std::numeric_limits< long >::max(), ::std::numeric_limits< long >::max() );
+                            aImageSizes[ nImageSet ] = Size( SAL_MAX_INT32, SAL_MAX_INT32 );
                         }
                         else
                         {
