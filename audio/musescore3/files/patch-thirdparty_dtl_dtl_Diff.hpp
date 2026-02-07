--- thirdparty/dtl/dtl/Diff.hpp.orig	2024-10-29 20:20:10 UTC
+++ thirdparty/dtl/dtl/Diff.hpp
@@ -162,14 +162,6 @@ namespace dtl {
             return trivial;
         }
         
-        void enableTrivial () const {
-            this->trivial = true;
-        }
-        
-        void disableTrivial () {
-            this->trivial = false;
-        }
-        
         void editDistanceOnlyEnabled () {
             this->editDistanceOnly = true;
         }
