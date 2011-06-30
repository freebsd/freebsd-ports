// The patch makes it build with new geos-3.3.0
// create(suze_t, size_t) is pretty straightforward, but
// these dynamic_casts I really don't like
--- build_geometry.cpp.orig	2011-01-16 20:01:16.000000000 +0300
+++ build_geometry.cpp	2011-06-30 02:51:28.000000000 +0400
@@ -71,7 +71,7 @@
 
 char *get_wkt_simple(osmNode *nodes, int count, int polygon) {
     GeometryFactory gf;
-    std::auto_ptr<CoordinateSequence> coords(gf.getCoordinateSequenceFactory()->create(0, 2));
+    std::auto_ptr<CoordinateSequence> coords(gf.getCoordinateSequenceFactory()->create((size_t)0, (size_t)2));
 
     try
     {
@@ -113,7 +113,7 @@
 
 size_t get_wkt_split(osmNode *nodes, int count, int polygon, double split_at) {
     GeometryFactory gf;
-    std::auto_ptr<CoordinateSequence> coords(gf.getCoordinateSequenceFactory()->create(0, 2));
+    std::auto_ptr<CoordinateSequence> coords(gf.getCoordinateSequenceFactory()->create((size_t)0, (size_t)2));
     double area;
     WKTWriter wktw;
     size_t wkt_size = 0;
@@ -143,7 +143,7 @@
 
             double distance = 0;
             std::auto_ptr<CoordinateSequence> segment;
-            segment = std::auto_ptr<CoordinateSequence>(gf.getCoordinateSequenceFactory()->create(0, 2));
+            segment = std::auto_ptr<CoordinateSequence>(gf.getCoordinateSequenceFactory()->create((size_t)0, (size_t)2));
             segment->add(coords->getAt(0));
             for(unsigned i=1; i<coords->getSize(); i++) {
                 segment->add(coords->getAt(i));
@@ -155,7 +155,7 @@
                     areas.push_back(0);
                     wkt_size++;
                     distance=0;
-                    segment = std::auto_ptr<CoordinateSequence>(gf.getCoordinateSequenceFactory()->create(0, 2));
+                    segment = std::auto_ptr<CoordinateSequence>(gf.getCoordinateSequenceFactory()->create((size_t)0, (size_t)2));
                     segment->add(coords->getAt(i));
                 }
             }
@@ -253,7 +253,7 @@
             case GEOS_MULTIPOINT:
                 // Drop through
             case GEOS_MULTILINESTRING:
-                gc = (GeometryCollection *) geometry;
+                gc = dynamic_cast<GeometryCollection *>(geometry);
                 num_geometries = gc->getNumGeometries();
                 *xnodes = (struct osmNode **) malloc((num_geometries + 1) * sizeof(struct osmNode *));
                 *xcount = (int *) malloc(num_geometries * sizeof(int));
@@ -309,7 +309,7 @@
     try
     {
         for (int c=0; xnodes[c]; c++) {
-            std::auto_ptr<CoordinateSequence> coords(gf.getCoordinateSequenceFactory()->create(0, 2));
+            std::auto_ptr<CoordinateSequence> coords(gf.getCoordinateSequenceFactory()->create((size_t)0, (size_t)2));
             for (int i = 0; i < xcount[c]; i++) {
                 struct osmNode *nodes = xnodes[c];
                 Coordinate c;
@@ -358,7 +358,7 @@
                         //std::cerr << "polygon(" << osm_id << ") is no good: points(" << pline->getNumPoints() << "), closed(" << pline->isClosed() << "). " << writer.write(pline.get()) << std::endl;
                 double distance = 0;
                 std::auto_ptr<CoordinateSequence> segment;
-                segment = std::auto_ptr<CoordinateSequence>(gf.getCoordinateSequenceFactory()->create(0, 2));
+                segment = std::auto_ptr<CoordinateSequence>(gf.getCoordinateSequenceFactory()->create((size_t)0, (size_t)2));
                 segment->add(pline->getCoordinateN(0));
                 for(unsigned i=1; i<pline->getNumPoints(); i++) {
                     segment->add(pline->getCoordinateN(i));
@@ -370,7 +370,7 @@
                         areas.push_back(0);
                         wkt_size++;
                         distance=0;
-                        segment = std::auto_ptr<CoordinateSequence>(gf.getCoordinateSequenceFactory()->create(0, 2));
+                        segment = std::auto_ptr<CoordinateSequence>(gf.getCoordinateSequenceFactory()->create((size_t)0, (size_t)2));
                         segment->add(pline->getCoordinateN(i));
                     }
                 }
@@ -484,7 +484,7 @@
             {
                 for(unsigned i=0; i<toplevelpolygons; i++) 
                 {
-                    Polygon* poly = (Polygon*)polygons->at(i);
+                    Polygon* poly = dynamic_cast<Polygon*>(polygons->at(i));
                     std::string text = writer.write(poly);
                     wkts.push_back(text);
                     areas.push_back(poly->getArea());
