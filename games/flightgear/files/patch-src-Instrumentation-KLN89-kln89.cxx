--- src/Instrumentation/KLN89/kln89.cxx.orig	2012-04-28 19:44:36.140236845 +0300
+++ src/Instrumentation/KLN89/kln89.cxx	2012-04-28 19:44:58.548236276 +0300
@@ -1032,7 +1032,7 @@ void KLN89::DrawApt(int x, int y) {
 	++j;
 	for(i=x-2; i<=x+2; ++i) _instrument->DrawPixel(i, j, (i != x ? true : false));
 	++j;
-	for(i=x-2; i<=x+2; ++i) _instrument->DrawPixel(i, j, (abs(i - x) > 1 ? true : false));
+	for(i=x-2; i<=x+2; ++i) _instrument->DrawPixel(i, j, (std::abs(i - x) > 1 ? true : false));
 	++j;
 	for(i=x-2; i<=x+2; ++i) _instrument->DrawPixel(i, j, (i != x ? true : false));
 	++j;

