--- src/sp-item-rm-unsatisfied-cns.cpp.orig	2011-07-08 20:25:09.468790000 +0200
+++ src/sp-item-rm-unsatisfied-cns.cpp	2013-10-19 09:55:40.000000000 +0200
@@ -23,9 +23,9 @@
         g_assert( snappoint_ix < int(snappoints.size()) );
         if (!approx_equal( sp_guide_distance_from_pt(cn.g, snappoints[snappoint_ix].getPoint()), 0) ) {
             remove_last(cn.g->attached_items, SPGuideAttachment(&item, cn.snappoint_ix));
+
             g_assert( i < item.constraints.size() );
-            vector<SPGuideConstraint>::iterator const ei(&item.constraints[i]);
-            item.constraints.erase(ei);
+            item.constraints.erase(item.constraints.begin() + i);
         }
     }
 }
