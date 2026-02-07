--- src/FTContour.cpp.orig	2019-02-07 21:39:58 UTC
+++ src/FTContour.cpp
@@ -174,7 +174,7 @@ void FTContour::SetParity(int parity)
 }
 
 
-FTContour::FTContour(FT_Vector* contour, char* tags, unsigned int n)
+FTContour::FTContour(FT_Vector* contour, unsigned char* tags, unsigned int n)
 {
     FTPoint prev, cur(contour[(n - 1) % n]), next(contour[0]);
     double olddir, dir = atan2((next - cur).Y(), (next - cur).X());
