--- src/drivers/olethros/driver.cpp.orig	2018-02-11 21:23:59 UTC
+++ src/drivers/olethros/driver.cpp
@@ -802,7 +802,7 @@ namespace olethros {
             rpmMaxTq,
             rpmMaxPw,
             rpmMax,
-            rpmMax*2.0
+            rpmMax*2.0f
 	};
 	int N = 5;
 	for (int i=0; i<N - 1; i++) {
