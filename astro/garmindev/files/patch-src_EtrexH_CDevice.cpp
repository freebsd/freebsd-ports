--- src/EtrexH/CDevice.cpp.orig	2019-10-07 13:16:44 UTC
+++ src/EtrexH/CDevice.cpp
@@ -47,7 +47,7 @@ callback ( state,0,cancel,0,message )
 
 namespace EtrexH
 {
-    static const char _clrtbl[1024]= {
+    static const signed char _clrtbl[1024]= {
         -127,-127,-127,0,-60,-60,-60,0,90,90,90,0,0,0,0,0,-117,0,0,0,
         -76,0,0,0,-43,0,0,0,-1,0,0,0,0,48,0,0,32,48,0,0,
         65,48,0,0,106,48,0,0,-117,48,0,0,-76,48,0,0,-43,48,0,0,
