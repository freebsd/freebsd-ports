--- src/other/stepcode/src/exp2cxx/complexSupport.h.orig	2020-03-12 15:32:37 UTC
+++ src/other/stepcode/src/exp2cxx/complexSupport.h
@@ -162,19 +162,19 @@ class EntList {
         // but all we need.
         EntList * firstNot( JoinType );
         EntList * nextNot( JoinType j ) {
-            return next->firstNot( j );
+            return next == NULL ? NULL : next->firstNot( j );
         }
         EntList * firstWanted( MatchType );
         EntList * nextWanted( MatchType mat ) {
-            return next->firstWanted( mat );
+            return next == NULL ? NULL : next->firstWanted( mat );
         }
         EntList * lastNot( JoinType );
         EntList * prevNot( JoinType j ) {
-            return prev->lastNot( j );
+            return prev == NULL ? NULL : prev->lastNot( j );
         }
         EntList * lastWanted( MatchType );
         EntList * prevWanted( MatchType mat ) {
-            return prev->lastWanted( mat );
+            return prev == NULL ? NULL : prev->lastWanted( mat );
         }
 
         JoinType join;
