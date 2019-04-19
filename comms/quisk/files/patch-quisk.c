--- quisk.c.orig	2019-04-19 15:39:19 UTC
+++ quisk.c
@@ -4065,7 +4065,7 @@ static PyObject * get_bandscope(void)	//
 				j2 = floor(d2);
 				sample = (j1 + 1 - d1) * bandscopeAverage[j1];
 				for (j = j1 + 1; j < j2; j++)
-					sample += cabs(bandscopeAverage[j]);
+					sample += fabs(bandscopeAverage[j]);
 				sample += (d2 - j2) * bandscopeAverage[j2];
 				sample = sample / frac;
 				// Normalize to max == 1
