--- creox/effects_dsp/distortionprocessor.cpp.orig
+++ creox/effects_dsp/distortionprocessor.cpp
@@ -423,7 +424,8 @@
 {
 	const float omega = 2.0f*float(M_PI)*centerFrequency/m_samplerate_f;
 	float sn,cs;
-	sincosf(omega, &sn, &cs);
+	sn = sinf(omega);
+	cs = cosf(omega);
 	const float alpha = sn*sinhf(float(M_LN2/2.0)*bandwidth*(omega/sn));
 	const float a0 = 1.0f/(1.0f + alpha);   //a0 = 1/a0
 
@@ -462,7 +464,8 @@
 	const float A = powf(10., gain/40.0f);
 	const float omega = 2.0f*float(M_PI)*frequency/m_samplerate_f;
 	float sn,cs;
-	sincosf(omega, &sn, &cs);
+	sn = sinf(omega);
+	cs = cosf(omega);
 	register const float beta = sn * sqrtf( (A*A + 1.0f)/slope - powf(A-1.0f, 2.0f) );
 
 	register const float AplusOne  = A + 1.0f;
@@ -500,7 +503,8 @@
 {
 	const float omega = 2.0f*float(M_PI)*cutoffFrequency/m_samplerate_f;
 	float sn,cs;
-	sincosf(omega, &sn, &cs);
+	sn = sinf(omega);
+	cs = cosf(omega);
 	const float alpha = sn/(2.0f * Q);
 	const float a0 = 1.0f/(1.0f + alpha);   //a0 = 1/a0
 
