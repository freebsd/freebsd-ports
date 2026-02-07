Clang compatibility
--- src/physicbody.cpp.orig	2009-06-17 17:47:07 UTC
+++ src/physicbody.cpp
@@ -20,9 +20,21 @@
 #include "physicbody.h"
 #include <math.h>
 #include <algorithm>
+#include <vector>
 
 using namespace std;
 
+template<class T>
+class DynArray {
+private:
+	std::vector<T> data;
+
+public:
+	DynArray(size_t len) : data(len) { }
+
+	operator const T*() const { return data.data(); }
+	operator T*() { return data.data(); }
+};
 
 const double PhysicEngine::G=6.6726e-17;
 
@@ -165,7 +177,6 @@ inline Vector2d PhysicEngine::calculateA
     return acc;
 }
 
-
 void PhysicEngine::_vstep (int delta) {
 #define DELTA_LIMIT 3
 #define ERROR_LIMIT 0.001
@@ -179,11 +190,11 @@ void PhysicEngine::_vstep (int delta) {
     real tempdelta=delta;
     real time=0;
     int n=bodies.size();
-    Vector2d accels[n];
+    DynArray<Vector2d> accels(n);
     calculateForces(0,accels);
     loadcount++;
-    Vector2d temp_pos[n];
-    Vector2d temp_vel[n];
+    DynArray<Vector2d> temp_pos(n);
+    DynArray<Vector2d> temp_vel(n);
     do {
         for (vector<PhysicBody*>::iterator j=bodies.begin();j!=bodies.end();j++) {
             if (!*j) continue;
@@ -306,12 +317,12 @@ void PhysicEngine::_step(int delta,bool 
 real PhysicEngine::vstepRK5 (real delta,Vector2d initaccels[]) {
     real maxdist=0;
     int n=bodies.size();
-    Vector2d accels[n];
-    Vector2d mipos[n];
-    Vector2d k1pos[n];
-    Vector2d k1vel[n];
-    Vector2d k2pos[n];
-    Vector2d k2vel[n];
+    DynArray<Vector2d> accels(n);
+    DynArray<Vector2d> mipos(n);
+    DynArray<Vector2d> k1pos(n);
+    DynArray<Vector2d> k1vel(n);
+    DynArray<Vector2d> k2pos(n);
+    DynArray<Vector2d> k2vel(n);
     for (vector<PhysicBody*>::iterator j=bodies.begin();j!=bodies.end();j++) {
         if (!*j || ((*j)->flags & PhysicBody::FIXED)) continue;
         mipos[(*j)->id]=(*j)->pos;
@@ -321,8 +332,8 @@ real PhysicEngine::vstepRK5 (real delta,
         (*j)->pos=mipos[(*j)->id]+k1pos[(*j)->id]*0.2;
     }
     calculateForces(delta*0.2,accels);
-    Vector2d k3pos[n];
-    Vector2d k3vel[n];
+    DynArray<Vector2d> k3pos(n);
+    DynArray<Vector2d> k3vel(n);
     for (vector<PhysicBody*>::iterator j=bodies.begin();j!=bodies.end();j++) {
         if (!*j || ((*j)->flags & PhysicBody::FIXED)) continue;
         k2vel[(*j)->id]=accels[(*j)->id]*delta;
@@ -330,8 +341,8 @@ real PhysicEngine::vstepRK5 (real delta,
         (*j)->pos=mipos[(*j)->id]+k1pos[(*j)->id]*(3.0/40.0)+k2pos[(*j)->id]*(9.0/40.0);
     }
     calculateForces(delta*0.3,accels);
-    Vector2d k4pos[n];
-    Vector2d k4vel[n];
+    DynArray<Vector2d> k4pos(n);
+    DynArray<Vector2d> k4vel(n);
     for (vector<PhysicBody*>::iterator j=bodies.begin();j!=bodies.end();j++) {
         if (!*j || ((*j)->flags & PhysicBody::FIXED)) continue;
         k3vel[(*j)->id]=accels[(*j)->id]*delta;
@@ -339,8 +350,8 @@ real PhysicEngine::vstepRK5 (real delta,
         (*j)->pos=mipos[(*j)->id]+k1pos[(*j)->id]*0.3+k2pos[(*j)->id]*(-0.9)+k3pos[(*j)->id]*1.2;
     }
     calculateForces(delta*0.6,accels);
-    Vector2d k5pos[n];
-    Vector2d k5vel[n];
+    DynArray<Vector2d> k5pos(n);
+    DynArray<Vector2d> k5vel(n);
     for (vector<PhysicBody*>::iterator j=bodies.begin();j!=bodies.end();j++) {
         if (!*j || ((*j)->flags & PhysicBody::FIXED)) continue;
         k4vel[(*j)->id]=accels[(*j)->id]*delta;
@@ -348,8 +359,8 @@ real PhysicEngine::vstepRK5 (real delta,
         (*j)->pos=mipos[(*j)->id]+k1pos[(*j)->id]*(-11.0/54.0)+k2pos[(*j)->id]*2.5+k3pos[(*j)->id]*(-70.0/27.0)+k4pos[(*j)->id]*(35.0/27.0);
     }
     calculateForces(delta,accels);
-    Vector2d k6pos[n];
-    Vector2d k6vel[n];
+    DynArray<Vector2d> k6pos(n);
+    DynArray<Vector2d> k6vel(n);
     for (vector<PhysicBody*>::iterator j=bodies.begin();j!=bodies.end();j++) {
         if (!*j || ((*j)->flags & PhysicBody::FIXED)) continue;
         k5vel[(*j)->id]=accels[(*j)->id]*delta;
