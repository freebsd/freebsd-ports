--- cp_info.cc.orig	Wed Jan 30 19:28:19 2002
+++ cp_info.cc	Wed Jan 30 19:28:30 2002
@@ -163,8 +163,8 @@
 		int expo = (high_bytes >> 20) & 0x7ff;
 		expo -= 1075;
 		llong mant = (expo == 0) ?
-			(bytes & 0xfffffffffffff) << 1 :
-			(bytes & 0xfffffffffffff) | 0x10000000000000;
+			(bytes & 0xfffffffffffffLL) << 1 :
+			(bytes & 0xfffffffffffffLL) | 0x10000000000000LL;
 		long double x = sign;
 		x *= mant;
 		x *= pow(2.0, expo);
