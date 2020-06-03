--- src/jiffy/c_src/double-conversion/strtod.cc.orig	2020-02-27 18:01:54 UTC
+++ src/jiffy/c_src/double-conversion/strtod.cc
@@ -38,7 +38,6 @@ namespace double_conversion {
 // 2^53 = 9007199254740992.
 // Any integer with at most 15 decimal digits will hence fit into a double
 // (which has a 53bit significand) without loss of precision.
-static const int kMaxExactDoubleIntegerDecimalDigits = 15;
 // 2^64 = 18446744073709551616 > 10^19
 static const int kMaxUint64DecimalDigits = 19;
 
@@ -54,34 +53,6 @@ static const int kMinDecimalPower = -324;
 // 2^64 = 18446744073709551616
 static const uint64_t kMaxUint64 = UINT64_2PART_C(0xFFFFFFFF, FFFFFFFF);
 
-
-static const double exact_powers_of_ten[] = {
-  1.0,  // 10^0
-  10.0,
-  100.0,
-  1000.0,
-  10000.0,
-  100000.0,
-  1000000.0,
-  10000000.0,
-  100000000.0,
-  1000000000.0,
-  10000000000.0,  // 10^10
-  100000000000.0,
-  1000000000000.0,
-  10000000000000.0,
-  100000000000000.0,
-  1000000000000000.0,
-  10000000000000000.0,
-  100000000000000000.0,
-  1000000000000000000.0,
-  10000000000000000000.0,
-  100000000000000000000.0,  // 10^20
-  1000000000000000000000.0,
-  // 10^22 = 0x21e19e0c9bab2400000 = 0x878678326eac9 * 2^22
-  10000000000000000000000.0
-};
-static const int kExactPowersOfTenSize = ARRAY_SIZE(exact_powers_of_ten);
 
 // Maximum number of significant digits in the decimal representation.
 // In fact the value is 772 (see conversions.cc), but to give us some margin
