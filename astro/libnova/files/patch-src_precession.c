--- src/precession.c.orig	2011-07-28 11:02:50 UTC
+++ src/precession.c
@@ -82,21 +82,21 @@ void ln_get_equ_prec (struct ln_equ_posn
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
@@ -140,21 +140,21 @@ void ln_get_equ_prec2 (struct ln_equ_pos
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
