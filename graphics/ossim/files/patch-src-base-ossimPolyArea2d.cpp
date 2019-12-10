Obtained from:	https://github.com/ossimlabs/ossim/commit/c456397821cf369af4d9ff1fb60a5dfd1bcefc24
		https://github.com/ossimlabs/ossim/commit/c0d97536f9ac967941b6ca48a6a7a4dde44f4ee3

--- src/base/ossimPolyArea2d.cpp.orig	2019-10-17 21:54:21 UTC
+++ src/base/ossimPolyArea2d.cpp
@@ -3,153 +3,169 @@
 //
 // $Id: ossimPolyArea2d.cpp 23623 2015-11-13 18:24:28Z gpotts $
 //---
-
 #include <ossim/base/ossimPolyArea2d.h>
-#include <ossim/base/ossimDrect.h>
-#include <ossim/base/ossimIrect.h>
+#include <ossim/base/ossimReferenced.h>
+#include <ossim/base/ossimPolygon.h>
+#include <ossim/base/ossimNotifyContext.h>
+#include <ossim/base/ossimKeywordlist.h>
 #include <ossim/base/ossimKeywordNames.h>
-#include <ossim/base/ossimNotify.h>
-#include <ossim/base/ossimRefPtr.h>
-#include <ossim/base/ossimString.h>
-#include <geos/geom/Coordinate.h>
-#include <geos/geom/CoordinateArraySequence.h>
-#include <geos/geom/GeometryFactory.h>
-#include <geos/geom/LinearRing.h>
-#include <geos/opBuffer.h>
-#include <geos/geom/Point.h>
-#include <geos/geom/Polygon.h>
-#include <geos/geom/MultiPolygon.h>
-#include <geos/geom/PrecisionModel.h>
-#include <geos/io/WKTReader.h>
-#include <geos/io/WKTWriter.h>
-#include <geos/util/GEOSException.h>
-#include <geos/operation/valid/IsValidOp.h>
-#include <geos/opBuffer.h>
-#include <cstdlib>
-#include <exception>
-#include <memory>
 #include <vector>
-#include <mutex>
-
-using namespace std;
+#include <cstdio>
+#include <cstdarg>
+#include <geos_c.h>
 
-class MyGeomFactory : public geos::geom::GeometryFactory
+class ossimPolyArea2dPrivate
 {
 public:
-   MyGeomFactory():
-   geos::geom::GeometryFactory(new geos::geom::PrecisionModel(geos::geom::PrecisionModel::FLOATING),
-                             -1)
+   typedef GEOSGeometry *GEOSGeometryPtr;
+   typedef const GEOSGeometry *ConstGEOSGeometryPtr;
+   ossimPolyArea2dPrivate() : m_geometry(GEOSGeom_createEmptyPolygon()) {}
+   virtual ~ossimPolyArea2dPrivate() { deleteGeometry(); }
+   void deleteGeometry()
    {
+      if (m_geometry)
+         GEOSGeom_destroy(m_geometry);
+      m_geometry = 0;
+   }
 
+   void setGeometry(GEOSGeometryPtr geom)
+   {
+      if(geom != m_geometry)
+      {
+         deleteGeometry();
+         m_geometry = geom;
+      }
    }
-}; 
-class ossimGeometryFactoryWrapper : public ossimReferenced
-{
-public:
-   ossimGeometryFactoryWrapper()
-      : m_geomFactory(0)
+   void setGeometry(const ossimPolygon &polygon, const std::vector<ossimPolygon> &holes = std::vector<ossimPolygon>());
+
+   void ringToPoints(const ConstGEOSGeometryPtr geom, std::vector<ossimDpt> &points) const;
+   void recurseVisibleGeometries(ossimPolygon::Vector &polyList) const
    {
-      //geos::geom::PrecisionModel *pm =
-      //   new geos::geom::PrecisionModel(geos::geom::PrecisionModel::FLOATING);
-      m_geomFactory = new MyGeomFactory();//new geos::geom::GeometryFactory(pm, -1); 
+      recurseVisibleGeometries(m_geometry, polyList);
    }
-   virtual ~ossimGeometryFactoryWrapper(){if(m_geomFactory) delete m_geomFactory;m_geomFactory=0;}
-   
-   MyGeomFactory* m_geomFactory;
-};
 
-class OssimPolyArea2dPrivate
-{
-public:
-   typedef geos::geom::Geometry* GeometryPtr;
-   typedef const geos::geom::Geometry* ConstGeometryPtr;
-   
-   OssimPolyArea2dPrivate(GeometryPtr geom=0);
-   ~OssimPolyArea2dPrivate();
-   
-   void deleteGeometry() { if(m_geometry) { delete m_geometry; m_geometry = 0; }}
-   void setGeometry(const ossimPolygon& polygon, const vector<ossimPolygon>& holes = vector<ossimPolygon>());
-   void setGeometry(GeometryPtr geom){deleteGeometry();m_geometry=geom;}
-   geos::geom::GeometryFactory* geomFactory(){{return m_globalFactory.valid()?m_globalFactory->m_geomFactory:0;}}
-   GeometryPtr m_geometry;
-   static ossimRefPtr<ossimGeometryFactoryWrapper> m_globalFactory; 
-};
+   void recurseVisibleGeometries(ConstGEOSGeometryPtr geom,
+                                 ossimPolygon::Vector &polygons) const;
 
-ossimRefPtr<ossimGeometryFactoryWrapper> OssimPolyArea2dPrivate::m_globalFactory;
+   void getVisiblePolygons(ConstGEOSGeometryPtr geom,
+                           ossimPolygon::Vector &polygons) const;
 
-OssimPolyArea2dPrivate::OssimPolyArea2dPrivate(GeometryPtr geom)
-:m_geometry(geom)
-{
-   static std::mutex globalFactoryMutex;
-   
+   bool getVisiblePolygons(ossimPolygon::Vector &polygons) const;
+
+   void getHoles(ConstGEOSGeometryPtr geom,
+                 ossimPolygon::Vector &polygons) const;
+   bool getPolygonHoles(ossimPolygon::Vector &polygons) const;
+   bool getPolygonHoles(ConstGEOSGeometryPtr geom,
+                        ossimPolygon::Vector &polygons) const;
+   void recurseGeometryHoles(ConstGEOSGeometryPtr geom,
+                             ossimPolygon::Vector &polygons) const;
+   void getBoundingRect(ossimDrect &bounds) const
    {
-      std::lock_guard<std::mutex> lock(globalFactoryMutex);
-      if(!m_globalFactory.valid())
+      bounds.makeNan();
+      if (!isEmpty())
       {
-         m_globalFactory = new ossimGeometryFactoryWrapper();
-      }    
+         GEOSGeometry *geom = GEOSEnvelope(m_geometry);
+
+         if (geom)
+         {
+            ossimPolygon::Vector polys;
+            getVisiblePolygons(geom, polys);
+            for (ossim_int32 idx = 0; idx < polys.size(); ++idx)
+            {
+               if (bounds.isNan())
+               {
+                  polys[idx].getBoundingRect(bounds);
+               }
+               else
+               {
+                  ossimDrect tempRect;
+                  polys[idx].getBoundingRect(tempRect);
+                  bounds = bounds.combine(tempRect);
+               }
+            }
+            GEOSGeom_destroy(geom);
+            geom = 0;
+         }
+      }
    }
-}
+   std::string toString() const;
+   bool setFromWkt(const std::string &s);
 
-OssimPolyArea2dPrivate::~OssimPolyArea2dPrivate()
-{
-   deleteGeometry();
-}
+   bool isEmpty() const;
+   bool isValid(bool displayValidationError = false) const;
+   bool isPointWithin(const ossimDpt &pt) const;
+   GEOSGeometryPtr m_geometry;
+};
 
-void OssimPolyArea2dPrivate::setGeometry(
-   const ossimPolygon& exteriorRing, const vector<ossimPolygon>& interiorRings)
+void ossimPolyArea2dPrivate::setGeometry(const ossimPolygon &exteriorRing,
+                                         const std::vector<ossimPolygon> &interiorRings)
 {
+
    deleteGeometry();
-   
-   geos::geom::CoordinateArraySequence *cas = new geos::geom::CoordinateArraySequence();
-   
-   const std::vector<ossimDpt>& pts = exteriorRing.getVertexList();
 
-   int idx = 0;
-   int n = (int)pts.size();
-   
-   if(n > 0)
+   if (exteriorRing.getNumberOfVertices() < 1)
+      return;
+   GEOSGeometryPtr shell = 0;
+   std::vector<GEOSGeometryPtr> holes;
+   const std::vector<ossimDpt> &pts = exteriorRing.getVertexList();
+   ossim_int32 idx = 0;
+   ossim_int32 n = (int)pts.size();
+
+   bool firstAndLastSame = ((pts[0].x == pts[n - 1].x) && (pts[0].y == pts[n - 1].y));
+   if (n > 0)
    {
+      GEOSCoordSequence *shellSeq = GEOSCoordSeq_create(
+          n + ((firstAndLastSame) ? 0 : 1), 2);
+
       //fill the exterior ring
       for (idx = 0; idx < n; idx++)
       {
-         cas->add(geos::geom::Coordinate(pts[idx].x, pts[idx].y));
+         GEOSCoordSeq_setXY(shellSeq, idx, pts[idx].x, pts[idx].y);
       }
-      
       //if the original polygon didn't have the first and last point the same, make it so
-      if((pts[0].x != pts[n-1].x) || (pts[0].y!=pts[n-1].y))
+      if (!firstAndLastSame)
       {
-         cas->add(geos::geom::Coordinate(pts[0].x, pts[0].y));
+         GEOSCoordSeq_setXY(shellSeq, n, pts[0].x, pts[0].y);
       }
-      
+      shell = GEOSGeom_createLinearRing(shellSeq);
       //fill the interior rings
-      vector<geos::geom::Geometry*> *holes = new vector<geos::geom::Geometry*>();
-      for (ossim_uint32 interiorRingIdx = 0; interiorRingIdx < interiorRings.size(); ++interiorRingIdx)
+      if (!interiorRings.empty())
       {
-         geos::geom::CoordinateArraySequence *interiorCas =
-            new geos::geom::CoordinateArraySequence();
-         const std::vector<ossimDpt>& vertexPts = interiorRings[interiorRingIdx].getVertexList();
-         for(ossim_uint32 vertexIndex=0; vertexIndex < vertexPts.size(); ++vertexIndex)
-         {
-            interiorCas->add(geos::geom::Coordinate(vertexPts[vertexIndex].x,
-                                                    vertexPts[vertexIndex].y));
-         }
-         
-         //if the original polygon didn't have the first and last point the same, make it so
-         if((vertexPts[0].x != vertexPts[vertexPts.size()-1].x) ||
-            (vertexPts[0].y!=vertexPts[vertexPts.size()-1].y))
+         for (ossim_uint32 interiorRingIdx = 0; interiorRingIdx < interiorRings.size(); ++interiorRingIdx)
          {
-            interiorCas->add(geos::geom::Coordinate(vertexPts[0].x, vertexPts[0].y));
+            if (interiorRings[interiorRingIdx].getNumberOfVertices() > 0)
+            {
+               const std::vector<ossimDpt> &vertexPts = interiorRings[interiorRingIdx].getVertexList();
+               firstAndLastSame = ((vertexPts[0].x == vertexPts[n - 1].x) && (vertexPts[0].y == vertexPts[n - 1].y));
+
+               GEOSCoordSequence *ring = GEOSCoordSeq_create(
+                   vertexPts.size() + ((firstAndLastSame) ? 0 : 1), 2);
+               for (ossim_uint32 vertexIndex = 0; vertexIndex < vertexPts.size(); ++vertexIndex)
+               {
+                  GEOSCoordSeq_setXY(ring, vertexIndex, vertexPts[vertexIndex].x, vertexPts[vertexIndex].y);
+               }
+
+               //if the original polygon didn't have the first and last point the same, make it so
+               if (!firstAndLastSame)
+               {
+                  GEOSCoordSeq_setXY(ring, vertexPts.size(), vertexPts[0].x, vertexPts[0].y);
+               }
+               GEOSGeometryPtr hole = GEOSGeom_createLinearRing(ring);
+               holes.push_back(hole);
+            }
          }
-         
-         geos::geom::LinearRing *hole = geomFactory()->createLinearRing(interiorCas);
-         holes->push_back(hole);
       }
-      
-      geos::geom::LinearRing* shell = geomFactory()->createLinearRing(cas);
-      if ( shell )
+
+      if (shell)
       {
-         m_geometry = geomFactory()->createPolygon(shell, holes);
+         if (holes.size())
+         {
+            m_geometry = GEOSGeom_createPolygon(shell, &holes.front(), holes.size());
+         }
+         else
+         {
+            m_geometry = GEOSGeom_createPolygon(shell, 0, 0);
+         }
       }
       else
       {
@@ -158,708 +174,540 @@ void OssimPolyArea2dPrivate::setGeometry
    }
 }
 
-void ossimPolyArea2d::recurseVisibleGeometries(
-   std::vector<ossimPolygon>& polyList, const geos::geom::Geometry* geom) const
+void ossimPolyArea2dPrivate::ringToPoints(const ConstGEOSGeometryPtr geom, std::vector<ossimDpt> &points) const
 {
-   int nGeoms = (int)geom->getNumGeometries();
-   
-   if(nGeoms < 2 )
+   double x, y;
+   if (!geom)
+      return;
+   ossim_int32 nPoints = GEOSGetNumCoordinates(geom);
+   if (nPoints > 0)
    {
-      const geos::geom::Polygon* poly = dynamic_cast<const geos::geom::Polygon*> (geom);
-      
-      if (poly)
+      const GEOSCoordSequence *seq = GEOSGeom_getCoordSeq(geom);
+      ossim_int32 i = 0;
+      for (i = 0; i < nPoints; i++)
       {
-         const geos::geom::LineString* lineString = dynamic_cast<const geos::geom::LineString*> (poly->getExteriorRing());
-         if (lineString)
-         {
-            int currentPolyIdx = (int)polyList.size();
-            int nPoints = (int)lineString->getNumPoints();
-            int idx = 0;
-            
-            polyList.push_back(ossimPolygon());
-            
-            for (idx=0; idx<nPoints; idx++)
-            {
-               std::unique_ptr<const geos::geom::Point> point(lineString->getPointN(idx));
-               polyList[currentPolyIdx].addPoint(point->getX(), point->getY());
-            }
-         }
+         GEOSCoordSeq_getX(seq, i, &x);
+         GEOSCoordSeq_getY(seq, i, &y);
+         points.push_back(ossimDpt(x, y));
       }
    }
-   else
+}
+
+void ossimPolyArea2dPrivate::getHoles(ConstGEOSGeometryPtr geom,
+                                      ossimPolygon::Vector &polygons) const
+{
+   int geomType = GEOSGeomTypeId(geom);
+   std::vector<ossimDpt> points;
+   switch (geomType)
    {
-      for (int idx=0; idx < nGeoms; ++idx)
-      {
-         recurseVisibleGeometries(polyList, geom->getGeometryN(idx));
-      }
+   case GEOS_LINESTRING:
+   case GEOS_LINEARRING:
+   {
+      ringToPoints(geom, points);
+      polygons.push_back(ossimPolygon(points));
+      break;
+   }
    }
 }
 
-void ossimPolyArea2d::recurseHoles(std::vector<ossimPolygon>& polyList,
-                                   const geos::geom::Geometry* geom) const
+void ossimPolyArea2dPrivate::getVisiblePolygons(ConstGEOSGeometryPtr geom,
+                                                ossimPolygon::Vector &polygons) const
 {
-   int nGeoms = (int)geom->getNumGeometries();
-   
-   if(nGeoms < 2 )
+   int geomType = GEOSGeomTypeId(geom);
+   std::vector<ossimDpt> points;
+
+   switch (geomType)
    {
-      const geos::geom::Polygon* poly = dynamic_cast<const geos::geom::Polygon*> (geom);
+   case GEOS_LINESTRING:
+   case GEOS_LINEARRING:
+   {
+      ringToPoints(geom, points);
+      polygons.push_back(ossimPolygon(points));
+      break;
+   }
+   case GEOS_POLYGON:
+   {
+      ConstGEOSGeometryPtr geom2 = GEOSGetExteriorRing(geom);
+      ringToPoints(geom2, points);
+      polygons.push_back(ossimPolygon(points));
 
-      if (poly)
+      break;
+   }
+   }
+}
+void ossimPolyArea2dPrivate::recurseVisibleGeometries(ConstGEOSGeometryPtr geom,
+                                                      ossimPolygon::Vector &polygons) const
+{
+   ossim_int32 nGeoms = GEOSGetNumGeometries(geom);
+   ConstGEOSGeometryPtr geomPtr = 0;
+   if (nGeoms < 2)
+   {
+      geomPtr = GEOSGetGeometryN(geom, 0);
+      if (geomPtr)
       {
-         ossim_uint32 nInteriorRings = (ossim_uint32)poly->getNumInteriorRing();
-         ossim_uint32 idx = 0;
-         
-         for(idx = 0; idx < nInteriorRings; ++idx)
-         {
-            const geos::geom::LineString* lineString = poly->getInteriorRingN(idx);
-            if (lineString)
-            {
-               int currentPolyIdx = (int)polyList.size();
-               int nPoints = (int)lineString->getNumPoints();
-               int idx = 0;
-
-               polyList.push_back(ossimPolygon());
-
-               for (idx=0; idx<nPoints; idx++)
-               {
-                  std::unique_ptr<const geos::geom::Point> point(lineString->getPointN(idx));
-                  polyList[currentPolyIdx].addPoint(point->getX(), point->getY());
-               }
-            }
-         }
+         getVisiblePolygons(geomPtr, polygons);
       }
    }
    else
    {
-      int idx = 0;
-      
-      for (idx=0; idx < nGeoms; idx++)
+      for (int idx = 0; idx < nGeoms; ++idx)
       {
-         recurseHoles(polyList, geom->getGeometryN(idx));
+         geomPtr = GEOSGetGeometryN(geom, idx);
+         recurseVisibleGeometries(geomPtr, polygons);
       }
    }
 }
 
-void ossimPolyArea2d::recurseCompleteGeometries(std::vector<ossimPolyArea2d>& polyList,
-                                                const geos::geom::Geometry* geom) const
+void ossimPolyArea2dPrivate::recurseGeometryHoles(ConstGEOSGeometryPtr geom,
+                                                  ossimPolygon::Vector &polygons) const
 {
-   int nGeoms = (int)geom->getNumGeometries();
-   if(nGeoms < 2 )
+   ossim_int32 nGeoms = GEOSGetNumGeometries(geom);
+   ConstGEOSGeometryPtr geomPtr = 0;
+   if (nGeoms < 2)
    {
-      const geos::geom::Polygon* poly = dynamic_cast<const geos::geom::Polygon*> (geom);
+      ossim_int32 nInteriorRings = GEOSGetNumInteriorRings(geom);
+      ossim_int32 idx = 0;
 
-      if (poly)
+      for (idx = 0; idx < nInteriorRings; ++idx)
       {
-         //get exterior shell for the geometry
-         ossimPolygon shell;
-         const geos::geom::LineString* lineString =
-            dynamic_cast<const geos::geom::LineString*> (poly->getExteriorRing());
-         if (lineString)
-         {
-            int nPoints = (int)lineString->getNumPoints();
-            for (int idx = 0; idx<nPoints; idx++)
-            {
-               std::unique_ptr<const geos::geom::Point> point(lineString->getPointN(idx));
-               shell.addPoint(point->getX(), point->getY());
-            }
-         }
-         
-         // Get interior rings for the geometry.
-         std::size_t nInteriorRings = poly->getNumInteriorRing();
-         vector<ossimPolygon> holes(nInteriorRings);
-         for(std::size_t holeIdx = 0; holeIdx < nInteriorRings; ++holeIdx)
-         {
-            const geos::geom::LineString* lineString = poly->getInteriorRingN(holeIdx);
-            if (lineString)
-            {
-               std::size_t nPoints = lineString->getNumPoints();
-               for (std::size_t idx = 0; idx<nPoints; ++idx)
-               {
-                  std::unique_ptr<const geos::geom::Point> point(lineString->getPointN(idx));
-                  holes[holeIdx].addPoint(point->getX(), point->getY());
-               }
-            }
-         }
-         polyList.push_back(ossimPolyArea2d(shell, holes));
+         const GEOSGeometry *ringGeom = GEOSGetInteriorRingN(geom, idx);
+         getHoles(ringGeom, polygons);
       }
    }
    else
    {
-      int idx = 0;
-      
-      for (idx=0; idx < nGeoms; idx++)
+      for (int idx = 0; idx < nGeoms; ++idx)
       {
-         recurseCompleteGeometries(polyList, geom->getGeometryN(idx));
+         geomPtr = GEOSGetGeometryN(geom, idx);
+         recurseGeometryHoles(geomPtr, polygons);
       }
    }
 }
 
-std::ostream& operator <<(std::ostream& out, const ossimPolyArea2d& rhs)
+bool ossimPolyArea2dPrivate::getVisiblePolygons(ossimPolygon::Vector &polygons) const
 {
-   if(rhs.m_privateData->m_geometry)
+   bool foundPolys = false;
+   if (m_geometry)
    {
-      out << rhs.m_privateData->m_geometry->toString();
+      ossim_uint32 sizeBefore = (ossim_uint32)polygons.size();
+      recurseVisibleGeometries(m_geometry, polygons);
+      foundPolys = (sizeBefore != polygons.size());
    }
-   return out;
-}
 
-ossimPolyArea2d::ossimPolyArea2d()
-   :m_privateData(new OssimPolyArea2dPrivate)
-{
+   return foundPolys;
 }
-
-ossimPolyArea2d::ossimPolyArea2d(const vector<ossimGpt>& polygon)
-   :m_privateData(new OssimPolyArea2dPrivate)
+bool ossimPolyArea2dPrivate::getPolygonHoles(ossimPolygon::Vector &polygons) const
 {
-   (*this) = polygon;
+   return getPolygonHoles(m_geometry, polygons);
 }
 
-ossimPolyArea2d::ossimPolyArea2d(const vector<ossimDpt>& polygon)
-   :m_privateData(new OssimPolyArea2dPrivate)
+bool ossimPolyArea2dPrivate::getPolygonHoles(ConstGEOSGeometryPtr geom,
+                                             ossimPolygon::Vector &polygons) const
 {
-   (*this) = polygon;
-}
+   bool foundPolys = false;
+   if (m_geometry)
+   {
+      ossim_uint32 sizeBefore = (ossim_uint32)polygons.size();
+      recurseGeometryHoles(m_geometry, polygons);
+      foundPolys = (sizeBefore != polygons.size());
+   }
 
-ossimPolyArea2d::ossimPolyArea2d(const ossimIrect& rect)
-   :m_privateData(new OssimPolyArea2dPrivate)
-{
-   (*this) = rect;
+   return foundPolys;
 }
 
-ossimPolyArea2d::ossimPolyArea2d(const ossimDrect& rect)
-   :m_privateData(new OssimPolyArea2dPrivate)
+std::string ossimPolyArea2dPrivate::toString() const
 {
-   (*this) = rect;
-}
+   std::string result;
 
-ossimPolyArea2d::ossimPolyArea2d(const ossimPolygon& polygon)
-   :m_privateData(new OssimPolyArea2dPrivate)
-{
-   (*this) = polygon;
-}
+   if (m_geometry)
+   {
+      GEOSWKTWriter *wktWriter = GEOSWKTWriter_create();
+      GEOSWKTWriter_setRoundingPrecision(wktWriter, 20);
+      char *wkt_c = GEOSWKTWriter_write(wktWriter, m_geometry);
 
-ossimPolyArea2d::ossimPolyArea2d(const ossimPolygon& exteriorRing, const vector<ossimPolygon>& interiorRings)
-   :m_privateData(new OssimPolyArea2dPrivate)
-{	
-	m_privateData->setGeometry(exteriorRing, interiorRings);
-}
+      result = wkt_c;
+      GEOSWKTWriter_destroy(wktWriter);
 
-ossimPolyArea2d::ossimPolyArea2d(const ossimPolyArea2d& rhs)
-   :m_privateData(new OssimPolyArea2dPrivate) 
-{
-   *this = rhs;
-}
+      GEOSFree(wkt_c);
+   }
 
-ossimPolyArea2d::ossimPolyArea2d(const ossimDpt& p1,
-                                 const ossimDpt& p2,
-                                 const ossimDpt& p3,
-                                 const ossimDpt& p4)
-   :
-   m_privateData(new OssimPolyArea2dPrivate)
+   return result;
+}
+bool ossimPolyArea2dPrivate::setFromWkt(const std::string &s)
 {
-   ossimPolygon temp(p1,p2,p3,p4);
-   *this = temp;
+   bool result = false;
+
+   GEOSWKTReader *reader = GEOSWKTReader_create();
+   GEOSGeometry *geom = GEOSWKTReader_read(reader, s.c_str());
+   result = (geom != 0);
+   setGeometry(geom);
+
+   GEOSWKTReader_destroy(reader);
+
+   return result;
 }
 
-ossimPolyArea2d::~ossimPolyArea2d()
+
+bool ossimPolyArea2dPrivate::isEmpty() const
 {
-   if(m_privateData)
+   bool result = true;
+   if (m_geometry)
    {
-      delete m_privateData;
-      m_privateData = 0;
+      result = (GEOSisEmpty(m_geometry) == 1);
    }
+
+   return result;
 }
 
-const ossimPolyArea2d& ossimPolyArea2d::operator =(const ossimPolyArea2d& rhs)
-{ 
-   if(this != &rhs)
+bool ossimPolyArea2dPrivate::isValid(bool displayValidationError) const
+{
+   bool result = false;
+
+   if (!displayValidationError)
    {
-      if(rhs.m_privateData->m_geometry)
+      result = GEOSisValid(m_geometry) == 1;
+   }
+   else
+   {
+      char *reason = GEOSisValidReason(m_geometry);
+      if (reason)
       {
-         m_privateData->setGeometry(rhs.m_privateData->m_geometry->clone());
+         ossimNotify(ossimNotifyLevel_INFO)
+             << "ossimPolyArea2dPrivate::isValid: " << reason << "\n";
+
+         GEOSFree(reason);
+         reason = 0;
       }
    }
-   return *this;
+
+   return result;
 }
+bool ossimPolyArea2dPrivate::isPointWithin(const ossimDpt &pt) const
+{
+   bool result = false;
 
-const ossimPolyArea2d& ossimPolyArea2d::operator =(const ossimPolygon& polygon)
+   if (!isEmpty())
+   {
+      GEOSCoordSequence *pointSeq = GEOSCoordSeq_create(1, 2);
+      GEOSCoordSeq_setXY(pointSeq, 0, pt.x, pt.y);
+      GEOSGeometry *geom = GEOSGeom_createPoint(pointSeq);
+      result = (GEOSWithin(geom, m_geometry) == 1);
+
+      GEOSGeom_destroy(geom);
+   }
+
+   return result;
+}
+
+
+ossimPolyArea2d::ossimPolyArea2d()
+    : m_privateData(new ossimPolyArea2dPrivate())
 {
-   m_privateData->setGeometry(polygon);
+}
 
-   return *this;
+ossimPolyArea2d::ossimPolyArea2d(const std::vector<ossimGpt> &polygon)
+    : m_privateData(new ossimPolyArea2dPrivate())
+{
+   m_privateData->setGeometry(polygon);
 }
 
-const ossimPolyArea2d& ossimPolyArea2d::operator =(const ossimIrect& rect)
+ossimPolyArea2d::ossimPolyArea2d(const std::vector<ossimDpt> &polygon)
+    : m_privateData(new ossimPolyArea2dPrivate())
 {
-   return (*this = ossimPolygon(rect));
+   m_privateData->setGeometry(polygon);
 }
 
-const ossimPolyArea2d& ossimPolyArea2d::operator =(const ossimDrect& rect)
+ossimPolyArea2d::ossimPolyArea2d(const ossimPolygon &shell, const std::vector<ossimPolygon> &holes)
+    : m_privateData(new ossimPolyArea2dPrivate())
 {
-   return (*this = ossimPolygon(rect));
+   m_privateData->setGeometry(shell, holes);
 }
 
-const ossimPolyArea2d& ossimPolyArea2d::operator =(const vector<ossimGpt>& polygon)
+ossimPolyArea2d::ossimPolyArea2d(const ossimDpt &p1,
+                                 const ossimDpt &p2,
+                                 const ossimDpt &p3,
+                                 const ossimDpt &p4)
+    : m_privateData(new ossimPolyArea2dPrivate())
 {
-   std::vector<ossimDpt> pts;
-   int idx = 0;
-   int n = (int)polygon.size();
-   for(idx = 0; idx < n;++idx)
-   {
-      pts.push_back(polygon[idx]);
-   }
-  
-   return (*this = ossimPolygon(pts));
+   m_privateData->setGeometry(ossimPolygon(p1, p2, p3, p4));
 }
 
-const ossimPolyArea2d& ossimPolyArea2d::operator =(const vector<ossimDpt>& polygon)
+ossimPolyArea2d::ossimPolyArea2d(const ossimPolyArea2d &rhs)
+    : m_privateData(new ossimPolyArea2dPrivate())
 {
-   return (*this = ossimPolygon(polygon));
+   m_privateData->deleteGeometry();
+   m_privateData->m_geometry = GEOSGeom_clone(rhs.m_privateData->m_geometry);
 }
 
-bool ossimPolyArea2d::intersects(const ossimPolyArea2d& rhs)const
+ossimPolyArea2d::ossimPolyArea2d(const ossimIrect &rect)
+    : m_privateData(new ossimPolyArea2dPrivate())
 {
-   bool result = false;
+   m_privateData->setGeometry(ossimPolygon(rect));
+}
 
-   if(m_privateData->m_geometry&&rhs.m_privateData->m_geometry)
-   {
-      result = m_privateData->m_geometry->intersects(rhs.m_privateData->m_geometry); 
-   }
+ossimPolyArea2d::ossimPolyArea2d(const ossimDrect &rect)
+    : m_privateData(new ossimPolyArea2dPrivate())
+{
+   m_privateData->setGeometry(ossimPolygon(rect));
+}
 
-   return result;
+ossimPolyArea2d::ossimPolyArea2d(const ossimPolygon &polygon)
+    : m_privateData(new ossimPolyArea2dPrivate())
+{
+   m_privateData->setGeometry(polygon);
 }
 
-ossimPolyArea2d ossimPolyArea2d::operator &(const ossimPolyArea2d& rhs)const
+ossimPolyArea2d::~ossimPolyArea2d()
 {
-   if((this!=&rhs) && m_privateData->m_geometry && rhs.m_privateData->m_geometry)
+   if (m_privateData)
    {
-      ossimPolyArea2d result;
-      try // GEOS code throws exceptions...
-      {
-         result.m_privateData->setGeometry(m_privateData->m_geometry->intersection(
-                                              rhs.m_privateData->m_geometry));
-      }
-      catch( const std::exception& e )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator& Caught exception: " << e.what() << std::endl;
-         result.clearPolygons();
-      }
-      catch( ... )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator& Caught exception!" << std::endl;
-         result.clearPolygons();
-      }
-      return result;
+      delete m_privateData;
    }
-   return *this;
+   m_privateData = 0;
 }
 
-ossimPolyArea2d ossimPolyArea2d::operator +(const ossimPolyArea2d& rhs)const
+void ossimPolyArea2d::clearPolygons()
 {
-   if((this!=&rhs) && m_privateData->m_geometry && rhs.m_privateData->m_geometry)
-   {
-      ossimPolyArea2d result;
-      try // GEOS code throws exceptions...
-      {
-         result.m_privateData->setGeometry(m_privateData->m_geometry->Union(
-                                              rhs.m_privateData->m_geometry));
-      }  
-      catch( const std::exception& e )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator+ Caught exception: " << e.what() << std::endl;
-         result.clearPolygons();
-      }
-      catch( ... )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator+ Caught exception!" << std::endl;
-         result.clearPolygons();
-      }
-      return result;
-   }
-   return *this;
+   m_privateData->setGeometry(GEOSGeom_createEmptyPolygon());
 }
-ossimPolyArea2d ossimPolyArea2d::operator -(const ossimPolyArea2d& rhs)const
+
+const ossimPolyArea2d &ossimPolyArea2d::operator=(const ossimPolyArea2d &rhs)
 {
-   if((this!=&rhs) && m_privateData->m_geometry && rhs.m_privateData->m_geometry)
+   if (&rhs != this)
    {
-      ossimPolyArea2d result;
-      try // GEOS code throws exceptions...
-      {
-         result.m_privateData->setGeometry(m_privateData->m_geometry->difference(
-                                              rhs.m_privateData->m_geometry));
-      }
-      catch( const std::exception& e )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator- Caught exception: " << e.what() << std::endl;
-         result.clearPolygons();
-      }
-      catch( ... )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator- Caught exception!" << std::endl;
-         result.clearPolygons();
-      }
-      return result;
+      m_privateData->deleteGeometry();
+      m_privateData->m_geometry = GEOSGeom_clone(rhs.m_privateData->m_geometry);
    }
+
    return *this;
 }
 
-const ossimPolyArea2d& ossimPolyArea2d::operator &=(const ossimPolyArea2d& rhs)
+const ossimPolyArea2d &ossimPolyArea2d::operator=(const ossimPolygon &rhs)
 {
-   if((this!=&rhs) && m_privateData->m_geometry && rhs.m_privateData->m_geometry)
-   {
-      try // GEOS code throws exceptions...
-      {
-         m_privateData->setGeometry(m_privateData->m_geometry->intersection(
-                                       rhs.m_privateData->m_geometry));
-      }
-      catch( const std::exception& e )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator&= Caught exception: " << e.what() << std::endl;
-         this->clearPolygons();
-      }
-      catch( ... )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator&= Caught exception!" << std::endl;
-         this->clearPolygons();
-      }      
-   }
+   m_privateData->setGeometry(rhs);
+
    return *this;
 }
 
-const ossimPolyArea2d& ossimPolyArea2d::operator +=(const ossimPolyArea2d& rhs)
+const ossimPolyArea2d &ossimPolyArea2d::operator=(const ossimIrect &rect)
 {
-   if((this!=&rhs) && m_privateData->m_geometry && rhs.m_privateData->m_geometry)
-   {
-      try // GEOS code throws exceptions...
-      {
-         m_privateData->setGeometry(m_privateData->m_geometry->Union(
-                                       rhs.m_privateData->m_geometry));
-      }
-      catch( const std::exception& e )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator+= Caught exception: " << e.what() << std::endl;
-         this->clearPolygons();
-      }
-      catch( ... )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator+= Caught exception!" << std::endl;
-         this->clearPolygons();
-      }      
-   }
+   m_privateData->setGeometry(ossimPolygon(rect));
+
    return *this;
 }
 
-const ossimPolyArea2d& ossimPolyArea2d::operator -=(const ossimPolyArea2d& rhs)
+const ossimPolyArea2d &ossimPolyArea2d::operator=(const ossimDrect &rect)
 {
-   if((this!=&rhs) && m_privateData->m_geometry && rhs.m_privateData->m_geometry)
-   {
-      try // GEOS code throws exceptions...
-      {
-         m_privateData->setGeometry(m_privateData->m_geometry->difference(
-                                       rhs.m_privateData->m_geometry));
-      }
-      catch( const std::exception& e )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator-= Caught exception: " << e.what() << std::endl;
-         this->clearPolygons();
-      }
-      catch( ... )
-      {
-         ossimNotify(ossimNotifyLevel_DEBUG)
-            << "ossimPolyArea2d::operator-= Caught exception!" << std::endl;
-         this->clearPolygons();
-      }      
-   }
+   m_privateData->setGeometry(ossimPolygon(rect));
+
    return *this;
 }
 
-void ossimPolyArea2d::add(const ossimPolyArea2d& rhs)
+const ossimPolyArea2d &ossimPolyArea2d::operator=(const std::vector<ossimGpt> &polygon)
 {
-   if(isEmpty())
-   {
-      *this=rhs;
-   }
-   else
-   {
-      geos::geom::Geometry* geom = m_privateData->m_geometry->Union(rhs.m_privateData->m_geometry);
-      if(geom) m_privateData->setGeometry(geom);
-   }
+   m_privateData->setGeometry(ossimPolygon(polygon));
+
+   return *this;
 }
 
-void ossimPolyArea2d::clearPolygons()
+const ossimPolyArea2d &ossimPolyArea2d::operator=(const std::vector<ossimDpt> &polygon)
 {
-   m_privateData->deleteGeometry();
-#if 0
-   clearEngine();
-#endif
+   m_privateData->setGeometry(ossimPolygon(polygon));
+
+   return *this;
 }
 
-bool ossimPolyArea2d::getVisiblePolygons(vector<ossimPolygon>& polyList)const
+const ossimPolyArea2d &ossimPolyArea2d::operator&=(const ossimPolyArea2d &rhs)
 {
-   bool foundPolys = false;
-   if(m_privateData->m_geometry)
-   {
-      ossim_uint32 sizeBefore = (ossim_uint32)polyList.size();
-      recurseVisibleGeometries(polyList, m_privateData->m_geometry);
-      foundPolys = (sizeBefore != polyList.size());
-   }
+   GEOSGeometry *geom = GEOSIntersection(m_privateData->m_geometry, rhs.m_privateData->m_geometry);
+   m_privateData->setGeometry(geom);
 
-   return foundPolys;
+   return *this;
 }
 
-bool ossimPolyArea2d::getPolygonHoles(vector<ossimPolygon>& polyList)const
+ossimPolyArea2d ossimPolyArea2d::operator&(const ossimPolyArea2d &rhs) const
 {
-   bool foundPolys = false;
-   if(m_privateData->m_geometry)
-   {
-      ossim_uint32 sizeBefore = (ossim_uint32)polyList.size();
-      recurseHoles(polyList, m_privateData->m_geometry);
-      foundPolys = (sizeBefore != polyList.size());
-   }
+   ossimPolyArea2d result(*this);
 
-   return foundPolys;
+   result &= rhs;
+
+   return result;
 }
 
-bool ossimPolyArea2d::getCompletePolygons(vector<ossimPolyArea2d>& polyList)const
+ossimPolyArea2d ossimPolyArea2d::operator+(const ossimPolyArea2d &rhs) const
 {
-	bool foundPolys = false;
-	if(m_privateData->m_geometry){
-		ossim_uint32 sizeBefore = (ossim_uint32)polyList.size();
-		recurseCompleteGeometries(polyList, m_privateData->m_geometry);
-		foundPolys = (sizeBefore != polyList.size());
-	}
-	return foundPolys;
+   ossimPolyArea2d result(*this);
+
+   result += rhs;
+
+   return result;
 }
 
-bool ossimPolyArea2d::isEmpty()const
+const ossimPolyArea2d &ossimPolyArea2d::operator+=(const ossimPolyArea2d &rhs)
 {
-   bool result = true;
-   if (m_privateData&&m_privateData->m_geometry)
-   {
-      result = m_privateData->m_geometry->isEmpty();
-   }
+   GEOSGeometry *geom = GEOSUnion(m_privateData->m_geometry, rhs.m_privateData->m_geometry);
 
-   return result;
+   m_privateData->setGeometry(geom);
+
+   return *this;
 }
 
-bool ossimPolyArea2d::isValid(bool displayValidationError)const
+ossimPolyArea2d ossimPolyArea2d::operator-(const ossimPolyArea2d &rhs) const
 {
-   bool result = false;
-   
-   if(m_privateData&&m_privateData->m_geometry)
-   {
-      if(displayValidationError)
-      {
-         geos::operation::valid::IsValidOp validityCheck(m_privateData->m_geometry);
-         geos::operation::valid::TopologyValidationError*
-            topologyValidationError(validityCheck.getValidationError());
-         // if(topologyValidationError == nullptr)
-         if(topologyValidationError == 0)
-         {
-            result = true;
-         }
-         else
-         {
-            ossimNotify(ossimNotifyLevel_INFO)
-               << "ossimPolyArea2d::isValid: " << topologyValidationError->toString() << std::endl;
-         }
-      }
-      else
-      {
-         result = m_privateData->m_geometry->isValid();
-      }
-   }
-   
+   ossimPolyArea2d result(*this);
+
+   result -= rhs;
+
    return result;
 }
 
-bool ossimPolyArea2d::isPointWithin(const ossimDpt& point)const
+const ossimPolyArea2d &ossimPolyArea2d::operator-=(const ossimPolyArea2d &rhs)
 {
-   return isPointWithin(point.x, point.y);
+   GEOSGeometry *geom = GEOSDifference(m_privateData->m_geometry, rhs.m_privateData->m_geometry);
+
+   m_privateData->setGeometry(geom);
+
+   return *this;
 }
 
-bool ossimPolyArea2d::isPointWithin(double x, double y)const
+ossim_float64 ossimPolyArea2d::getArea()const
 {
-   bool result = false;
-
+   double result = 0.0;
+   
    if(!isEmpty())
    {
-      geos::geom::Coordinate c(x,y);
-      geos::geom::Geometry* geom = m_privateData->geomFactory()->createPoint(c);
-  
-      result = m_privateData->m_geometry->intersects(geom);
-
-      delete geom;
+      GEOSArea(m_privateData->m_geometry, &result);
    }
 
    return result;
 }
 
-void ossimPolyArea2d::getBoundingRect(ossimDrect& rect)
+bool ossimPolyArea2d::isEmpty() const
 {
-   rect.makeNan();
+   return m_privateData->isEmpty();
+}
 
-   if(!isEmpty())
-   {
-      const geos::geom::Envelope* envelope = m_privateData->m_geometry->getEnvelopeInternal();
+bool ossimPolyArea2d::isValid(bool displayValidationError) const
+{
+   return m_privateData->isValid(displayValidationError);
+}
 
-      rect = ossimDrect(envelope->getMinX(), envelope->getMinY(), envelope->getMaxX(), envelope->getMaxY());
-   }
+bool ossimPolyArea2d::isPointWithin(const ossimDpt &point) const
+{
+   return m_privateData->isPointWithin(point);
 }
 
-std::string ossimPolyArea2d::toString()const
+bool ossimPolyArea2d::isPointWithin(double x, double y) const
 {
-   std::string result = "";
+   return isPointWithin(ossimDpt(x, y));
+}
 
-   if(m_privateData->m_geometry)
-   {
-      result = m_privateData->m_geometry->toString();
-   }
+void ossimPolyArea2d::getBoundingRect(ossimDrect &rect) const
+{
+   m_privateData->getBoundingRect(rect);
+}
 
-   return result;
+bool ossimPolyArea2d::intersects(const ossimPolyArea2d &rhs) const
+{
+   return (GEOSIntersects(m_privateData->m_geometry,
+                          rhs.m_privateData->m_geometry) == 1);
 }
 
-ossimPolyArea2d ossimPolyArea2d::getBufferedShape(double distance) const{
-	ossimPolyArea2d result;
-	try{
-		geos::operation::buffer::BufferOp buffer_operation(m_privateData->m_geometry);
-		result.m_privateData->setGeometry( buffer_operation.getResultGeometry(distance));
-	}catch( const std::exception& e ){
-		ossimNotify(ossimNotifyLevel_DEBUG)
-			<< "ossimPolyArea2d::getBufferedShape Caught exception: " << e.what() << std::endl;
-		result.clearPolygons();
-	}catch( ... ){
-		ossimNotify(ossimNotifyLevel_DEBUG)
-			<< "ossimPolyArea2d::getBufferedShape Caught exception!" << std::endl;
-		result.clearPolygons();
-	}
-	return result;
+void ossimPolyArea2d::makeValid()
+{
+   ossimPolyArea2dPrivate::GEOSGeometryPtr geom = GEOSMakeValid(m_privateData->m_geometry);
+   if(geom) m_privateData->setGeometry(geom);
 }
-ossimPolyArea2d& ossimPolyArea2d::setToBufferedShape(double distance)
+
+
+void ossimPolyArea2d::add(const ossimPolyArea2d &rhs)
 {
-   try{
-      geos::operation::buffer::BufferOp buffer_operation(m_privateData->m_geometry);
-      m_privateData->setGeometry( buffer_operation.getResultGeometry(distance));
-   }catch( const std::exception& e ){
-      ossimNotify(ossimNotifyLevel_DEBUG)
-         << "ossimPolyArea2d::getBufferedShape Caught exception: " << e.what() << std::endl;
-   }catch( ... ){
-      ossimNotify(ossimNotifyLevel_DEBUG)
-         << "ossimPolyArea2d::getBufferedShape Caught exception!" << std::endl;
-   }
-   return *this;
+   *this += rhs;
 }
 
-ossimPolyArea2d& ossimPolyArea2d::toMultiPolygon()
+bool ossimPolyArea2d::getVisiblePolygons(std::vector<ossimPolygon> &polyList) const
 {
+   m_privateData->getVisiblePolygons(polyList);
 
+   return (polyList.size() > 0);
+}
 
-   try{
-      if(m_privateData->m_geometry)
-      {
-         switch(m_privateData->m_geometry->getGeometryTypeId())
-         {
-            case geos::geom::GEOS_POLYGON:
-            {
-               std::vector<geos::geom::Geometry*> values;
-               values.push_back(m_privateData->m_geometry->clone());
+bool ossimPolyArea2d::getPolygonHoles(std::vector<ossimPolygon> &polyList) const
+{
+   m_privateData->getPolygonHoles(polyList);
 
-               m_privateData->setGeometry(m_privateData->m_geometry->getFactory()->createMultiPolygon(values));
-               break;
-            }
-            case geos::geom::GEOS_MULTIPOLYGON:
-            {
-               // intentionally left blank
-               break;
-            }
-            default:
-            {  
-               // might need an error at a later date
-               ossimNotify(ossimNotifyLevel_WARN)
-                  << "ossimPolyArea2d::toMultiPolygon Geometry type can not be converted to a multi polygon: " <<m_privateData->m_geometry->getGeometryType()<< std::endl;
+   return (polyList.size() > 0);
+}
 
-               break;
-            }
-         }
-      }
-   }
-   catch(const std::exception& e)
-   {
-      ossimNotify(ossimNotifyLevel_WARN)
-         << "ossimPolyArea2d::toMultiPolygon Caught exception: " << e.what() << std::endl;
-   }
-   catch(...)
+ossimPolyArea2d &ossimPolyArea2d::toMultiPolygon()
+{
+   int geomType = GEOSGeomTypeId(m_privateData->m_geometry);
+
+   if (geomType != GEOS_MULTIPOLYGON)
    {
-      ossimNotify(ossimNotifyLevel_WARN)
-         << "ossimPolyArea2d::toMultiPolygon Caught exception!" << std::endl;
+      std::vector<GEOSGeometry *> geoms(1);
+      geoms[0] = GEOSGeom_clone(m_privateData->m_geometry);
+      GEOSGeometry *result = GEOSGeom_createCollection(GEOS_MULTIPOLYGON,
+                                                       &geoms.front(), 1);
+      m_privateData->setGeometry(result);
    }
 
    return *this;
 }
 
-bool ossimPolyArea2d::saveState(ossimKeywordlist& kwl,
-                                const char* prefix)const
+std::string ossimPolyArea2d::toString() const
+{
+   return m_privateData->toString();
+}
+
+bool ossimPolyArea2d::setFromWkt(const std::string &s)
+{
+   return m_privateData->setFromWkt(s);
+}
+
+bool ossimPolyArea2d::saveState(ossimKeywordlist &kwl,
+                                const char *prefix) const
 {
    kwl.add(prefix,
            ossimKeywordNames::TYPE_KW,
            "ossimPolyArea2d",
            true);
 
-   if(!isEmpty())
+   if (!isEmpty())
    {
-      geos::io::WKTWriter writer;
 
       kwl.add(prefix,
               "wkt",
-              writer.write(m_privateData->m_geometry).c_str(),
+              toString().c_str(),
               true);
    }
-   // else
-   // {
-   //
-   // }
-
    return true;
 }
 
-bool ossimPolyArea2d::loadState(const ossimKeywordlist& kwl,
-                                const char* prefix)
+bool ossimPolyArea2d::loadState(const ossimKeywordlist &kwl,
+                                const char *prefix)
 {
-   if(m_privateData)
+   bool result = true;
+
+   if (m_privateData)
    {
       ossimString wkt = kwl.find(prefix, "wkt");
 
-      if(!wkt.empty())
+      if (!wkt.empty())
       {
-         geos::io::WKTReader reader(m_privateData->geomFactory());
-         try
-         {
-            m_privateData->setGeometry(reader.read(wkt.c_str()));
-         }
-         catch( const std::exception& e )
-         {
-            ossimNotify(ossimNotifyLevel_DEBUG)
-               << "ossimPolyArea2d::loadState Caught exception: " << e.what() << std::endl;
-            this->clearPolygons();
-         }
-         catch(...)
-         {
-            ossimNotify(ossimNotifyLevel_DEBUG)
-               << "ossimPolyArea2d::loadState Caught exception!" << std::endl;
-            this->clearPolygons(); 
-         }
+         result = setFromWkt(wkt.string());
       }
    }
-   return true;
+
+   return result;
+}
+
+std::ostream &operator<<(std::ostream &out, const ossimPolyArea2d &rhs)
+{
+   if (!rhs.isEmpty())
+   {
+      out << rhs.toString();
+   }
+
+   return out;
 }
