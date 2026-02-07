--- minisat-2.2.1/minisat/core/SolverTypes.h.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/core/SolverTypes.h
@@ -47,7 +47,7 @@ struct Lit {
     int     x;
 
     // Use this as a constructor:
-    friend Lit mkLit(Var var, bool sign = false);
+    //friend Lit mkLit(Var var, bool sign = false);
 
     bool operator == (Lit p) const { return x == p.x; }
     bool operator != (Lit p) const { return x != p.x; }
@@ -55,7 +55,7 @@ struct Lit {
 };
 
 
-inline  Lit  mkLit     (Var var, bool sign) { Lit p; p.x = var + var + (int)sign; return p; }
+inline  Lit  mkLit     (Var var, bool sign = false) { Lit p; p.x = var + var + (int)sign; return p; }
 inline  Lit  operator ~(Lit p)              { Lit q; q.x = p.x ^ 1; return q; }
 inline  Lit  operator ^(Lit p, bool b)      { Lit q; q.x = p.x ^ (unsigned int)b; return q; }
 inline  bool sign      (Lit p)              { return p.x & 1; }
@@ -127,7 +127,10 @@ class Clause {
         unsigned has_extra : 1;
         unsigned reloced   : 1;
         unsigned size      : 27; }                        header;
+#include <util/pragma_push.def>
+#include <util/pragma_wzero_length_array.def>
     union { Lit lit; float act; uint32_t abs; CRef rel; } data[0];
+#include <util/pragma_pop.def>
 
     friend class ClauseAllocator;
 
@@ -142,11 +145,12 @@ class Clause {
         for (int i = 0; i < ps.size(); i++) 
             data[i].lit = ps[i];
 
-        if (header.has_extra)
+        if (header.has_extra) {
             if (header.learnt)
                 data[header.size].act = 0;
             else
                 calcAbstraction();
+        }
     }
 
     // NOTE: This constructor cannot be used directly (doesn't allocate enough memory).
@@ -157,11 +161,12 @@ class Clause {
         for (int i = 0; i < from.size(); i++)
             data[i].lit = from[i];
 
-        if (header.has_extra)
+        if (header.has_extra) {
             if (header.learnt)
                 data[header.size].act = from.data[header.size].act;
             else 
                 data[header.size].abs = from.data[header.size].abs;
+        }
     }
 
 public:
