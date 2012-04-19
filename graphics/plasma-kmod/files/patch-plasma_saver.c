--- plasma_saver.c.orig	2001-01-24 12:03:23.000000000 -0500
+++ plasma_saver.c	2012-04-18 17:51:10.000000000 -0400
@@ -52,7 +52,7 @@
 #define SCR_W 320
 #define SCR_H 200
 #define PLAS_S	128	/* Plasma is 128x128 */
-#define WAVEMOD 1.3	/* Shrink/stretch factor for sine wave.
+#define WAVEMOD 1300	/* Shrink/stretch factor for sine wave.
 			   Effectively controls the 'speed' */
 
 /* Miscellaneous global variables */
@@ -61,11 +61,18 @@
 static char xbuffer[SCR_W];
 static char ybuffer[SCR_H];
 
-static float angle[5];
-static float anglebak[3];
+static int64_t angle[5];
+static int64_t anglebak[3];
 
-static float
-aprsin(float theta)
+static __inline int64_t
+fdiv(int64_t a, int64_t b)
+{
+
+	return (a / b + ((a % b * 2) >= b));
+}
+
+static __inline int64_t
+aprsin(int64_t theta)
 /*
  * An evil, evil approximation of sin(x). It computes the sin
  * value by first standardising the input into the range
@@ -86,11 +93,11 @@
         }
 
         if(theta > TWO_PI)
-		theta -= (float)((int)(theta/TWO_PI)*TWO_PI);
+		theta %= TWO_PI;
 
 	/* theta now > 0, < 2pi, look up in table */
 
-        apos = (int)((theta/TWO_PI)*90.0);
+	apos = fdiv(theta * SCALE, TWO_PI) * 90 / SCALE;
 	return((neg) ? -aprsinv[apos] : aprsinv[apos]);
 }
 
@@ -100,7 +107,11 @@
 	video_info_t	info;
 
 	/* Console capable of running 320x200x256? */
+#if __FreeBSD_version < 800000
 	if(get_mode_info(adp, M_VGA_CG320, &info)) {
+#else
+	if (vidd_get_info(adp, M_VGA_CG320, &info)) {
+#endif
 		log(LOG_NOTICE, "plasma_saver: the console does not support M_VGA_CG320\n");
 		return(ENODEV);
 	}
@@ -123,14 +134,15 @@
 	anglebak[2] = angle[2];
         for (i=0; i<PLAS_S; i++)
         {
-	        xbuffer[i] =	16*aprsin(angle[0]) + 8*aprsin(angle[1])
-				+ 4*aprsin(angle[2]);
-	        angle[0] += 2*PI/PLAS_S;
-                angle[1] += 4*PI/PLAS_S;
-                angle[2] += 8*PI/PLAS_S;
-                angle[3] += 2*PI/PLAS_S;
-                angle[4] += 4*PI/PLAS_S;
-		ybuffer[i] = 16*aprsin(angle[3]) + 8*aprsin(angle[4]);
+		xbuffer[i] = fdiv(16 * aprsin(angle[0]) +
+		    8 * aprsin(angle[1]) + 4 * aprsin(angle[2]), SCALE);
+		angle[0] += fdiv(2 * PI, PLAS_S);
+		angle[1] += fdiv(4 * PI, PLAS_S);
+		angle[2] += fdiv(8 * PI, PLAS_S);
+		angle[3] += fdiv(2 * PI, PLAS_S);
+		angle[4] += fdiv(4 * PI, PLAS_S);
+		ybuffer[i] = fdiv(16 * aprsin(angle[3]) +
+		    8 * aprsin(angle[4]), SCALE);
 	}
 	for(i=0; i<PLAS_S; i++)
 	{
@@ -144,11 +156,11 @@
 			buffer[((i+45)*SCR_W) + (j+96)] = 128 + 
 				ybuffer[i] + xbuffer[j];
 	}
-        angle[0] = anglebak[0] - ((2*PI/SCR_W)*WAVEMOD);
-        angle[1] = anglebak[1] + ((6*PI/SCR_W)*WAVEMOD);
-        angle[2] = anglebak[2] + ((4*PI/SCR_W)*WAVEMOD);
-        angle[3] = anglebak[0] + ((6*PI/SCR_W)*WAVEMOD);
-        angle[4] = anglebak[1] + ((10*PI/SCR_W)*WAVEMOD);
+	angle[0] = anglebak[0] - fdiv(fdiv(2 * PI, SCR_W) * WAVEMOD, 1000);
+	angle[1] = anglebak[1] + fdiv(fdiv(6 * PI, SCR_W) * WAVEMOD, 1000);
+	angle[2] = anglebak[2] + fdiv(fdiv(4 * PI, SCR_W) * WAVEMOD, 1000);
+	angle[3] = anglebak[0] + fdiv(fdiv(6 * PI, SCR_W) * WAVEMOD, 1000);
+	angle[4] = anglebak[1] + fdiv(fdiv(10 * PI, SCR_W) * WAVEMOD, 1000);
 }
 
 static int
@@ -156,8 +168,13 @@
 {
 	if(blank) {
 		if(blanked <= 0) {
+#if __FreeBSD_version < 800000
 			set_video_mode(adp, M_VGA_CG320);
 	            	load_palette(adp, plasma_pal);
+#else
+			vidd_set_mode(adp, M_VGA_CG320);
+			vidd_load_palette(adp, plasma_pal);
+#endif
 			blanked++;
 			video = (u_char *)adp->va_window;
 			/* Zero various stuff */
