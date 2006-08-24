--- src/Blip_Buffer.cpp	Thu Aug 24 12:12:17 2006
+++ src/Blip_Buffer.cpp	Thu Aug 24 12:12:48 2006
@@ -190,16 +190,16 @@
 		treble = 5.0;
 
 	long double const maxh = 4096.0;
-	long double const rolloff = powl( 10.0, 1.0 / (maxh * 20.0) * treble / (1.0 - cutoff) );
-	long double const pow_a_n = powl( rolloff, maxh - maxh * cutoff );
+	long double const rolloff = pow( 10.0, 1.0 / (maxh * 20.0) * treble / (1.0 - cutoff) );
+	long double const pow_a_n = pow( rolloff, maxh - maxh * cutoff );
 	long double const to_angle = pi / 2 / maxh / oversample;
 	for ( int i = 0; i < count; i++ )
 	{
 		long double angle = ((i - count) * 2 + 1) * to_angle;
-		long double c = rolloff * cosl( (maxh - 1.0) * angle ) - cosl( maxh * angle );
-		long double cos_nc_angle = cosl( maxh * cutoff * angle );
-		long double cos_nc1_angle = cosl( (maxh * cutoff - 1.0) * angle );
-		long double cos_angle = cosl( angle );
+		long double c = rolloff * cos( (maxh - 1.0) * angle ) - cos( maxh * angle );
+		long double cos_nc_angle = cos( maxh * cutoff * angle );
+		long double cos_nc1_angle = cos( (maxh * cutoff - 1.0) * angle );
+		long double cos_angle = cos( angle );
 		
 		c = c * pow_a_n - rolloff * cos_nc1_angle + cos_nc_angle;
 		long double d = 1.0 + rolloff * (rolloff - cos_angle - cos_angle);
