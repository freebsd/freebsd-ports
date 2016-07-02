--- htapp.cc.orig	2016-07-02 07:48:11 UTC
+++ htapp.cc
@@ -3023,7 +3023,7 @@ static uint isqr(uint u)
 {
 	uint a = 2;
 	uint b = u/a;
-	while (abs(a - b) > 1) {
+	while (abs((int)(a - b)) > 1) {
 		a = (a+b)/2;
 		b = u/a;
         }
