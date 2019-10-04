--- src/Mod/Part/App/Geometry2d.cpp.orig	2019-10-04 10:33:33 UTC
+++ src/Mod/Part/App/Geometry2d.cpp
@@ -183,7 +183,7 @@ void Geom2dPoint::Save(Base::Writer &writer) const
         << "<Geom2dPoint "
         << "X=\"" << Point.x << "\" "
         << "Y=\"" << Point.y << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dPoint::Restore(Base::XMLReader &reader)
@@ -875,7 +875,7 @@ void Geom2dCircle::Save(Base::Writer& writer) const
     SaveAxis(writer, axis);
     writer.Stream()
         << "Radius=\"" << c.Radius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dCircle::Restore(Base::XMLReader& reader)
@@ -990,7 +990,7 @@ void Geom2dArcOfCircle::Save(Base::Writer &writer) con
     SaveAxis(writer, axis, u, v);
     writer.Stream()
         << "Radius=\"" << c.Radius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dArcOfCircle::Restore(Base::XMLReader &reader)
@@ -1152,7 +1152,7 @@ void Geom2dEllipse::Save(Base::Writer& writer) const
     writer.Stream()
         << "MajorRadius=\"" << e.MajorRadius() << "\" "
         << "MinorRadius=\"" << e.MinorRadius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dEllipse::Restore(Base::XMLReader& reader)
@@ -1329,7 +1329,7 @@ void Geom2dArcOfEllipse::Save(Base::Writer &writer) co
     writer.Stream()
         << "MajorRadius=\"" << e.MajorRadius() << "\" "
         << "MinorRadius=\"" << e.MinorRadius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dArcOfEllipse::Restore(Base::XMLReader &reader)
@@ -1458,7 +1458,7 @@ void Geom2dHyperbola::Save(Base::Writer& writer) const
     writer.Stream()
         << "MajorRadius=\"" <<  h.MajorRadius() << "\" "
         << "MinorRadius=\"" <<  h.MinorRadius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dHyperbola::Restore(Base::XMLReader& reader)
@@ -1591,7 +1591,7 @@ void Geom2dArcOfHyperbola::Save(Base::Writer &writer) 
     writer.Stream()
         << "MajorRadius=\"" <<  h.MajorRadius() << "\" "
         << "MinorRadius=\"" <<  h.MinorRadius() << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dArcOfHyperbola::Restore(Base::XMLReader &reader)
@@ -1702,7 +1702,7 @@ void Geom2dParabola::Save(Base::Writer& writer) const
     SaveAxis(writer, axis);
     writer.Stream()
         << "Focal=\"" << focal << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dParabola::Restore(Base::XMLReader& reader)
@@ -1815,7 +1815,7 @@ void Geom2dArcOfParabola::Save(Base::Writer &writer) c
     SaveAxis(writer, axis, u, v);
     writer.Stream()
         << "Focal=\"" << focal << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dArcOfParabola::Restore(Base::XMLReader &reader)
@@ -1930,7 +1930,7 @@ void Geom2dLine::Save(Base::Writer &writer) const
         << "PosY=\"" << Pos.y << "\" "
         << "DirX=\"" << Dir.x << "\" "
         << "DirY=\"" << Dir.y << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dLine::Restore(Base::XMLReader &reader)
@@ -2064,7 +2064,7 @@ void Geom2dLineSegment::Save(Base::Writer &writer) con
         << "StartY=\"" << Start.y << "\" "
         << "EndX=\"" << End.x << "\" "
         << "EndY=\"" << End.y << "\" "
-        << "/>" << endl;
+        << "/>" << std::endl;
 }
 
 void Geom2dLineSegment::Restore(Base::XMLReader &reader)
