Obtained from:	https://git.slackbuilds.org/slackbuilds/tree/gis/osgEarth/geos-3_8-support.patch

--- src/osgEarthSymbology/GEOS.cpp.orig	2019-04-19 16:45:18 UTC
+++ src/osgEarthSymbology/GEOS.cpp
@@ -49,7 +49,7 @@ using namespace geos::operation;
 
 namespace
 {
-    geom::CoordinateSequence*
+    std::unique_ptr<geom::CoordinateSequence>
     vec3dArray2CoordSeq( const Symbology::Geometry* input, bool close, const geom::CoordinateSequenceFactory* factory )
     {   
         bool needToClose = close && input->size() > 2 && input->front() != input->back();
@@ -64,7 +64,7 @@ namespace
         {
             coords->push_back( coords->front() );
         }
-        geom::CoordinateSequence* seq = factory->create( coords );
+	std::unique_ptr<geom::CoordinateSequence> seq = factory->create( coords );
 
         return seq;
     }
@@ -108,7 +108,8 @@ namespace
         else
         {
             // any other type will at least contain points:
-            geom::CoordinateSequence* seq = 0L;
+	    std::unique_ptr<geom::CoordinateSequence> seq = 0L;
+
             try
             {
                 switch( input->getType() )
@@ -119,24 +120,24 @@ namespace
 
                 case Symbology::Geometry::TYPE_POINTSET:
                     seq = vec3dArray2CoordSeq( input, false, f->getCoordinateSequenceFactory() );
-                    if ( seq ) output = f->createPoint( seq );
+                    if ( seq ) output = f->createPoint( *seq );
                     break;
 
                 case Symbology::Geometry::TYPE_LINESTRING:
                     seq = vec3dArray2CoordSeq( input, false, f->getCoordinateSequenceFactory() );
-                    if ( seq ) output = f->createLineString( seq );
+                    if ( seq ) output = f->createLineString( *seq );
                     break;
 
                 case Symbology::Geometry::TYPE_RING:
                     seq = vec3dArray2CoordSeq( input, true, f->getCoordinateSequenceFactory() );
-                    if ( seq ) output = f->createLinearRing( seq );
+                    if ( seq ) output = f->createLinearRing( *seq );
                     break;
 
                 case Symbology::Geometry::TYPE_POLYGON:
                     seq = vec3dArray2CoordSeq( input, true, f->getCoordinateSequenceFactory() );
                     geom::LinearRing* shell = 0L;
                     if ( seq )
-                        shell = f->createLinearRing( seq );
+                        shell = f->createLinearRing( *seq );
 
                     if ( shell )
                     {
@@ -155,7 +156,7 @@ namespace
                                 holes = 0L;
                             }
                         }
-                        output = f->createPolygon( shell, holes );
+                        output = f->createPolygon( shell, (std::vector<geom::LinearRing * >*)holes );
                     }
                 
                     break;
