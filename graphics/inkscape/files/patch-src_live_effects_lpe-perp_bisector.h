--- src/live_effects/lpe-perp_bisector.h.orig      2011-07-08 20:25:09.468790000 +0200
+++ src/live_effects/lpe-perp_bisector.h
@@ -27,7 +27,7 @@
   class KnotHolderEntityEnd;
   class KnotHolderEntityLeftEnd;
   class KnotHolderEntityRightEnd;
-  void bisector_end_set(SPItem *item, Geom::Point const &p, bool left);
+  void bisector_end_set(SPItem *item, Geom::Point const &p, bool left = true);
 }
 
 class LPEPerpBisector : public Effect {
@@ -46,7 +46,7 @@
     friend class PB::KnotHolderEntityEnd;
     friend class PB::KnotHolderEntityLeftEnd;
     friend class PB::KnotHolderEntityRightEnd;
-    friend void PB::bisector_end_set(SPItem *item, Geom::Point const &p, bool left = true);
+    friend void PB::bisector_end_set(SPItem *item, Geom::Point const &p, bool left);
 
 private:
     ScalarParam length_left;
