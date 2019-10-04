--- src/Mod/Part/App/Geometry.cpp.orig	2019-10-04 10:23:58 UTC
+++ src/Mod/Part/App/Geometry.cpp
@@ -203,7 +203,7 @@ unsigned int Geometry::getMemSize (void) const
 void Geometry::Save(Base::Writer &writer) const
 {
     const char c = Construction?'1':'0';
-    writer.Stream() << writer.ind() << "<Construction value=\"" <<  c << "\"/>" << endl;
+    writer.Stream() << writer.ind() << "<Construction value=\"" <<  c << "\"/>" << std::endl;
 }
 
 void Geometry::Restore(Base::XMLReader &reader)
@@ -323,7 +323,7 @@ void GeomPoint::Save(Base::Writer &writer) const
                 << "X=\"" <<  Point.x <<
                 "\" Y=\"" <<  Point.y <<
                 "\" Z=\"" <<  Point.z <<
-             "\"/>" << endl;
+             "\"/>" << std::endl;
 }
 
 void GeomPoint::Restore(Base::XMLReader &reader)
@@ -793,7 +793,7 @@ void GeomBezierCurve::Save(Base::Writer& writer) const
          << writer.ind()
              << "<BezierCurve "
                 << "PolesCount=\"" <<  poles.size() <<
-             "\">" << endl;
+             "\">" << std::endl;
 
     writer.incInd();
 
@@ -808,11 +808,11 @@ void GeomBezierCurve::Save(Base::Writer& writer) const
             "\" Y=\"" << (*itp).y <<
             "\" Z=\"" << (*itp).z <<
             "\" Weight=\"" << (*itw) <<
-        "\"/>" << endl;
+        "\"/>" << std::endl;
     }
 
     writer.decInd();
-    writer.Stream() << writer.ind() << "</BezierCurve>" << endl ;
+    writer.Stream() << writer.ind() << "</BezierCurve>" << std::endl ;
 }
 
 void GeomBezierCurve::Restore(Base::XMLReader& reader)
@@ -1270,7 +1270,7 @@ void GeomBSplineCurve::Save(Base::Writer& writer) cons
                  "\" KnotsCount=\"" <<  knots.size() <<
                  "\" Degree=\"" <<  degree <<
                  "\" IsPeriodic=\"" <<  (int) isperiodic <<
-             "\">" << endl;
+             "\">" << std::endl;
 
     writer.incInd();
 
@@ -1285,7 +1285,7 @@ void GeomBSplineCurve::Save(Base::Writer& writer) cons
             "\" Y=\"" << (*itp).y <<
             "\" Z=\"" << (*itp).z <<
             "\" Weight=\"" << (*itw) <<
-        "\"/>" << endl;
+        "\"/>" << std::endl;
     }
 
     std::vector<double>::const_iterator itk;
@@ -1297,11 +1297,11 @@ void GeomBSplineCurve::Save(Base::Writer& writer) cons
             << "<Knot "
             << "Value=\"" << (*itk)
             << "\" Mult=\"" << (*itm) <<
-        "\"/>" << endl;
+        "\"/>" << std::endl;
     }
 
     writer.decInd();
-    writer.Stream() << writer.ind() << "</BSplineCurve>" << endl ;
+    writer.Stream() << writer.ind() << "</BSplineCurve>" << std::endl ;
 }
 
 void GeomBSplineCurve::Restore(Base::XMLReader& reader)
@@ -1903,7 +1903,7 @@ void GeomCircle::Save(Base::Writer& writer) const
                 "\" NormalZ=\"" <<  normal.Z() <<
                 "\" AngleXU=\"" <<  AngleXU <<
                 "\" Radius=\"" <<  this->myCurve->Radius() <<
-             "\"/>" << endl;
+             "\"/>" << std::endl;
 }
 
 void GeomCircle::Restore(Base::XMLReader& reader)
@@ -2132,7 +2132,7 @@ void GeomArcOfCircle::Save(Base::Writer &writer) const
                 "\" Radius=\"" <<  circle->Radius() <<
                 "\" StartAngle=\"" <<  this->myCurve->FirstParameter() <<
                 "\" EndAngle=\"" <<  this->myCurve->LastParameter() <<
-             "\"/>" << endl;
+             "\"/>" << std::endl;
 }
 
 void GeomArcOfCircle::Restore(Base::XMLReader &reader)
@@ -2383,7 +2383,7 @@ void GeomEllipse::Save(Base::Writer& writer) const
             << "MajorRadius=\"" <<  this->myCurve->MajorRadius() << "\" "
             << "MinorRadius=\"" <<  this->myCurve->MinorRadius() << "\" "
             << "AngleXU=\"" << AngleXU << "\" "
-            << "/>" << endl;
+            << "/>" << std::endl;
 }
 
 void GeomEllipse::Restore(Base::XMLReader& reader)
@@ -2653,7 +2653,7 @@ void GeomArcOfEllipse::Save(Base::Writer &writer) cons
             << "AngleXU=\"" << AngleXU << "\" "
             << "StartAngle=\"" <<  this->myCurve->FirstParameter() << "\" "
             << "EndAngle=\"" <<  this->myCurve->LastParameter() << "\" "
-            << "/>" << endl;
+            << "/>" << std::endl;
 }
 
 void GeomArcOfEllipse::Restore(Base::XMLReader &reader)
@@ -2826,7 +2826,7 @@ void GeomHyperbola::Save(Base::Writer& writer) const
             << "MajorRadius=\"" <<  this->myCurve->MajorRadius() << "\" "
             << "MinorRadius=\"" <<  this->myCurve->MinorRadius() << "\" "
             << "AngleXU=\"" << AngleXU << "\" "
-            << "/>" << endl;
+            << "/>" << std::endl;
 }
 
 void GeomHyperbola::Restore(Base::XMLReader& reader)
@@ -3083,7 +3083,7 @@ void GeomArcOfHyperbola::Save(Base::Writer &writer) co
             << "AngleXU=\"" << AngleXU << "\" "
             << "StartAngle=\"" <<  this->myCurve->FirstParameter() << "\" "
             << "EndAngle=\"" <<  this->myCurve->LastParameter() << "\" "
-            << "/>" << endl;
+            << "/>" << std::endl;
 }
 
 void GeomArcOfHyperbola::Restore(Base::XMLReader &reader)
@@ -3236,7 +3236,7 @@ void GeomParabola::Save(Base::Writer& writer) const
             << "NormalZ=\"" <<  normal.Z() << "\" "
             << "Focal=\"" <<  this->myCurve->Focal() << "\" "
             << "AngleXU=\"" << AngleXU << "\" "
-            << "/>" << endl;
+            << "/>" << std::endl;
 }
 
 void GeomParabola::Restore(Base::XMLReader& reader)
@@ -3436,7 +3436,7 @@ void GeomArcOfParabola::Save(Base::Writer &writer) con
             << "AngleXU=\"" << AngleXU << "\" "
             << "StartAngle=\"" <<  this->myCurve->FirstParameter() << "\" "
             << "EndAngle=\"" <<  this->myCurve->LastParameter() << "\" "
-            << "/>" << endl;
+            << "/>" << std::endl;
 }
 
 void GeomArcOfParabola::Restore(Base::XMLReader &reader)
@@ -3581,7 +3581,7 @@ void GeomLine::Save(Base::Writer &writer) const
                 "\" DirX=\"" <<  Dir.x <<
                 "\" DirY=\"" <<  Dir.y <<
                 "\" DirZ=\"" <<  Dir.z <<
-             "\"/>" << endl;
+             "\"/>" << std::endl;
 }
 void GeomLine::Restore(Base::XMLReader &reader)
 {
@@ -3722,7 +3722,7 @@ void GeomLineSegment::Save       (Base::Writer &writer
                 "\" EndX=\"" <<  End.x <<
                 "\" EndY=\"" <<  End.y <<
                 "\" EndZ=\"" <<  End.z <<
-             "\"/>" << endl;
+             "\"/>" << std::endl;
 }
 
 void GeomLineSegment::Restore    (Base::XMLReader &reader)
