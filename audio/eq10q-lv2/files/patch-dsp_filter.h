--- dsp/filter.h.orig	2016-12-11 12:07:54 UTC
+++ dsp/filter.h
@@ -237,13 +237,13 @@ static inline void calcCoefs(Filter *fil
 	double G12 = G1 * G1;
 	
 	//Digital filter
-	double F   = fabsf(G2  - GB2);// + 0.00000001f; ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0 
-	double G00 = fabsf(G2  - 1.0);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
-	double F00 = fabsf(GB2 - 1.0);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
-	double G01 = fabsf(G2  - G1);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
-	double G11 = fabsf(G2  - G12);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
-	double F01 = fabsf(GB2 - G1);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
-	double F11 = fabsf(GB2 - G12);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
+	double F   = fabs(G2  - GB2);// + 0.00000001f; ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0 
+	double G00 = fabs(G2  - 1.0);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
+	double F00 = fabs(GB2 - 1.0);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
+	double G01 = fabs(G2  - G1);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
+	double G11 = fabs(G2  - G12);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
+	double F01 = fabs(GB2 - G1);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
+	double F11 = fabs(GB2 - G12);// + 0.00000001f;  ///TODO akest petit num sumat en teoria no hi va pero he detectat div by 0
 	double W2 = sqrtf(G11 / G00) * tanf(w0/2.0) * tanf(w0/2.0);
 
 	//Bandwidth condition
