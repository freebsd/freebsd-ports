--- reallyslick/c_src/lattice.c.orig	Sun Feb 26 07:47:35 2006
+++ reallyslick/c_src/lattice.c	Fri Apr 28 09:43:41 2006
@@ -714,6 +714,7 @@
 	static float rollVel = 0.0f, rollAcc = 0.0f;
 	int drawDepth = dDrawdepth + 2;
 	static float rollChange = 0;	/* rsRandf (10.0f) + 2.0f; */
+	float dot, maxSpin, rotationInertia;
 
 	where += (float)dSpeed * 0.05f * elapsedTime;
 	if (where >= 1.0f) {
@@ -741,14 +742,14 @@
 	rsVec_cross ((float *)&angvel, dir, oldDir); /* Desired axis of rotation */
 
 	/* Protect against mild "overflow" */
-	float dot = MAX(MIN(rsVec_dot (oldDir, dir), -1.0), 1.0);
-	float maxSpin = 0.25f * (float)dSpeed * elapsedTime;
+	dot = MAX(MIN(rsVec_dot (oldDir, dir), -1.0), 1.0);
+	maxSpin = 0.25f * (float)dSpeed * elapsedTime;
 	angle = MAX(MIN(acos(dot), -maxSpin), maxSpin);
 
 	rsVec_scale ((float *)&angvel, angle); /* Desired angular velocity */
 	rsVec_subtract (angvel, oldAngvel, (float *)&tempVec); /* Change in angular velocity */
 	distance = rsVec_length (tempVec); /* Don't let angular velocity change too much */
-	float rotationInertia = 0.007f * (float)dSpeed * elapsedTime;
+	rotationInertia = 0.007f * (float)dSpeed * elapsedTime;
 	if (distance > rotationInertia * elapsedTime) {
 		rsVec_scale ((float *)&tempVec, ((rotationInertia * elapsedTime) / distance));
 		rsVec_add (oldAngvel, tempVec, (float *)&angvel);
