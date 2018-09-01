Fix build with clang 7:

src/AIModel/AIFlightPlanCreatePushBack.cxx:96:48: error: ordered comparison between pointer and zero ('FGTaxiNode *' and 'int')

--- src/AIModel/AIFlightPlanCreatePushBack.cxx.orig	2018-08-17 19:14:25.768512000 +0200
+++ src/AIModel/AIFlightPlanCreatePushBack.cxx	2018-08-17 19:14:44.343865000 +0200
@@ -93,7 +93,7 @@
   
     FGGroundNetwork* groundNet = dep->groundNetwork();
     FGParking *parking = gate.parking();
-    if (parking && parking->getPushBackPoint() > 0) {
+    if (parking && parking->getPushBackPoint() != NULL) {
         FGTaxiRoute route = groundNet->findShortestRoute(parking, parking->getPushBackPoint(), false);
       
         int size = route.size();
