--- source/cMech.cpp.orig	2009-11-08 16:18:05.000000000 +0300
+++ source/cMech.cpp	2009-11-12 07:03:04.000000000 +0300
@@ -1494,9 +1494,15 @@
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
+		mDestination[0] = u.f;
+		mDestination[1] = u.f;
+		mDestination[2] = u.f;
+
         //cout << "Destination is " << ((finitef(mDestination[0])) ? "finite" : "infinite" ) << "\n";
     }
 }
