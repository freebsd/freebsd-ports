--- src/precession.c.orig	Tue Jan 10 23:35:08 2006
+++ src/precession.c	Tue Aug 15 18:03:50 2006
@@ -56,21 +56,21 @@
 	theta = ln_deg_to_rad (theta); 
 
 	/* calc A,B,C equ 20.4 */
-	A = cosl (mean_dec) * sinl (mean_ra + zeta);
-	B = cosl (theta) * cosl (mean_dec) * cosl (mean_ra + zeta) - sinl (theta) * sinl (mean_dec);
-	C = sinl (theta) * cosl (mean_dec) * cosl (mean_ra + zeta) + cosl (theta) * sinl (mean_dec);
+	A = cos (mean_dec) * sin (mean_ra + zeta);
+	B = cos (theta) * cos (mean_dec) * cos (mean_ra + zeta) - sin (theta) * sin (mean_dec);
+	C = sin (theta) * cos (mean_dec) * cos (mean_ra + zeta) + cos (theta) * sin (mean_dec);
 	
-	ra = atan2l (A,B) + eta;
+	ra = atan2 (A,B) + eta;
 	
 	/* check for object near celestial pole */
 	if (mean_dec > (0.4 * M_PI) || mean_dec < (-0.4 * M_PI)) {
 		/* close to pole */
-		dec = acosl (sqrt(A * A + B * B));
+		dec = acos (sqrt(A * A + B * B));
 		if (mean_dec < 0.)
 		  dec *= -1; /* 0 <= acos() <= PI */
 	} else {
 		/* not close to pole */
-		dec = asinl (C);
+		dec = asin (C);
 	}
 
 	/* change to degrees */
@@ -114,21 +114,21 @@
 	theta = ln_deg_to_rad (theta); 
 
 	/* calc A,B,C equ 20.4 */
-	A = cosl (mean_dec) * sinl (mean_ra + zeta);
-	B = cosl (theta) * cosl (mean_dec) * cosl (mean_ra + zeta) - sinl (theta) * sinl (mean_dec);
-	C = sinl (theta) * cosl (mean_dec) * cosl (mean_ra + zeta) + cosl (theta) * sinl (mean_dec);
+	A = cos (mean_dec) * sin (mean_ra + zeta);
+	B = cos (theta) * cos (mean_dec) * cos (mean_ra + zeta) - sin (theta) * sin (mean_dec);
+	C = sin (theta) * cos (mean_dec) * cos (mean_ra + zeta) + cos (theta) * sin (mean_dec);
 	
-	ra = atan2l (A,B) + eta;
+	ra = atan2 (A,B) + eta;
 	
 	/* check for object near celestial pole */
 	if (mean_dec > (0.4 * M_PI) || mean_dec < (-0.4 * M_PI)) {
 		/* close to pole */
-		dec = acosl (sqrt(A * A + B * B));
+		dec = acos (sqrt(A * A + B * B));
 		if (mean_dec < 0.)
 		  dec *= -1; /* 0 <= acos() <= PI */
 	} else {
 		/* not close to pole */
-		dec = asinl (C);
+		dec = asin (C);
 	}
 
 	/* change to degrees */
