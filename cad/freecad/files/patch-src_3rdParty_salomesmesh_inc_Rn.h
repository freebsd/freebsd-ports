--- src/3rdParty/salomesmesh/inc/Rn.h.orig	2019-10-04 10:14:23 UTC
+++ src/3rdParty/salomesmesh/inc/Rn.h
@@ -180,12 +180,12 @@ class R4: public R3
 {
   friend std::ostream& operator <<(std::ostream& f, const R4 & P )
   { f << P.x << ' ' << P.y << ' ' << P.z << ' ' << P.omega; return f; }
-  friend istream& operator >>(istream& f,  R4 & P)
+  friend std::istream& operator >>(std::istream& f,  R4 & P)
   { f >> P.x >>  P.y >>  P.z >> P.omega ; return f; }
 
   friend std::ostream& operator <<(std::ostream& f, const R4 * P )
   { f << P->x << ' ' << P->y << ' ' << P->z << ' ' << P->omega; return f; }
-  friend istream& operator >>(istream& f,  R4 * P)
+  friend std::istream& operator >>(std::istream& f,  R4 * P)
   { f >> P->x >>  P->y >>  P->z >> P->omega ; return f; }
 
 public:  
