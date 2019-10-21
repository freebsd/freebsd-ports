--- src/EtrexLegendC/CDevice.cpp.orig	2019-10-07 13:15:56 UTC
+++ src/EtrexLegendC/CDevice.cpp
@@ -37,7 +37,7 @@ using namespace std;
 namespace EtrexLegendC
 {
 
-    static const char _clrtbl[1024]= {
+    static const signed char _clrtbl[1024]= {
         0,0,0,0,32,0,0,0,65,0,0,0,106,0,0,0,-117,0,0,0,
         -76,0,0,0,-43,0,0,0,-1,0,0,0,0,48,0,0,32,48,0,0,
         65,48,0,0,106,48,0,0,-117,48,0,0,-76,48,0,0,-43,48,0,0,
