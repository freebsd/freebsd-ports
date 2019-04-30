--- src/cmd/unit_collide.h.orig	2019-04-05 07:20:53 UTC
+++ src/cmd/unit_collide.h
@@ -94,9 +94,9 @@ class UnitHash3d (public)
     {
         if ( !hugeobjects.empty() )
             hugeobjects.clear();
-        if ( this->active_huge.size() )
+        if ( this->active_huge->size() )
             ha.clear();
-        if ( this->accum_huge.size() )
+        if ( this->accum_huge->size() )
             hb.clear();
         acc_huge.clear();
         act_huge.clear();
