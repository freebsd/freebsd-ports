--- quisk.c.orig	2019-05-09 20:50:36 UTC
+++ quisk.c
@@ -4352,7 +4352,7 @@ static PyObject * get_bandscope(void)	// Called by the
 				j2 = floor(d2);
 				sample = (j1 + 1 - d1) * bandscopeAverage[j1];
 				for (j = j1 + 1; j < j2; j++)
-					sample += cabs(bandscopeAverage[j]);
+					sample += fabs(bandscopeAverage[j]);
 				sample += (d2 - j2) * bandscopeAverage[j2];
 				sample = sample / frac;
 				// Normalize to max == 1
