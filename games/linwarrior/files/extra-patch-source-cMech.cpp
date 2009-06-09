--- source/cMech.cpp.orig	2009-05-23 21:01:21.000000000 +0400
+++ source/cMech.cpp	2009-06-08 18:39:11.000000000 +0400
@@ -1756,9 +1756,14 @@
         // Set XYZ to Not-A-Number (NaN) for no location.
         // Note that NaN-ity can only be tested either by
         // isnanf(x), !finite(x) or by x!=x as NaN always != NaN.
-        mDestination[0] = nanf("");
-        mDestination[1] = nanf("");
-        mDestination[2] = nanf("");
+		union { /* from src/lib/msun/src/s_nan.c of FreeBSD HEAD */
+			float f;
+			uint32_t bits[1];
+		} u;
+		u.bits[0] = 0x7fc00000;
+        mDestination[0] = u.f;
+        mDestination[1] = u.f;
+        mDestination[2] = u.f;
         //printf("Destination is %s\n", (finitef(mDestination[0])) ? "finite" : "infinite" );
     }
 }
