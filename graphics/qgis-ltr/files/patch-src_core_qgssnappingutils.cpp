--- src/core/qgssnappingutils.cpp.orig	2026-07-31 12:35:21 UTC
+++ src/core/qgssnappingutils.cpp
@@ -646,7 +646,7 @@ QString QgsSnappingUtils::dump()
     msg += QString( "layer : %1\n"
                     "config: %2   tolerance %3 %4\n" )
            .arg( layer.layer->name() )
-           .arg( layer.type ).arg( layer.tolerance ).arg( static_cast<int>( layer.unit ) );
+           .arg( static_cast<int>( layer.type ) ).arg( layer.tolerance ).arg( static_cast<int>( layer.unit ) );
 
     if ( mStrategy == IndexAlwaysFull || mStrategy == IndexHybrid || mStrategy == IndexExtent )
     {
