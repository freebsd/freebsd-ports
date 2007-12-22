--- plugins/glyph/cylinder.cpp.orig	2007-12-18 22:29:43.000000000 +0100
+++ plugins/glyph/cylinder.cpp	2007-12-18 22:29:50.000000000 +0100
@@ -17,7 +17,7 @@
   virtual ~Cylinder();
   virtual string getName() {return string("Cylinder");}
   virtual void draw(node n);
-  virtual Coord Cylinder::getAnchor(const Coord &vector) const;
+  virtual Coord getAnchor(const Coord &vector) const;
   virtual void setLOD(int n);
 
 private:
