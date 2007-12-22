--- plugins/glyph/cone.cpp.orig	2007-12-18 22:28:52.000000000 +0100
+++ plugins/glyph/cone.cpp	2007-12-18 22:29:16.000000000 +0100
@@ -18,7 +18,7 @@
   virtual string getName() {return string("Cone");}
   virtual void draw(node n);
   virtual void setLOD(int n);
-  virtual Coord Cone::getAnchor(const Coord &vector) const;
+  virtual Coord getAnchor(const Coord &vector) const;
 
 private:
   GLuint LList;
