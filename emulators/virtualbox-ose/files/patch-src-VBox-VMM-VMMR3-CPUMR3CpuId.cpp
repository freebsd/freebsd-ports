--- src/VBox/VMM/VMMR3/CPUMR3CpuId.cpp.orig	2015-03-02 10:10:12.000000000 -0500
+++ src/VBox/VMM/VMMR3/CPUMR3CpuId.cpp	2015-03-12 18:58:11.784386000 -0400
@@ -146,15 +146,15 @@
             case 0x06:
                 switch (bModel)
                 {
-                    case  0: kCpumMicroarch_AMD_K7_Palomino;
-                    case  1: kCpumMicroarch_AMD_K7_Palomino;
-                    case  2: kCpumMicroarch_AMD_K7_Palomino;
-                    case  3: kCpumMicroarch_AMD_K7_Spitfire;
-                    case  4: kCpumMicroarch_AMD_K7_Thunderbird;
-                    case  6: kCpumMicroarch_AMD_K7_Palomino;
-                    case  7: kCpumMicroarch_AMD_K7_Morgan;
-                    case  8: kCpumMicroarch_AMD_K7_Thoroughbred;
-                    case 10: kCpumMicroarch_AMD_K7_Barton; /* Thorton too. */
+                    case  0: return kCpumMicroarch_AMD_K7_Palomino;
+                    case  1: return kCpumMicroarch_AMD_K7_Palomino;
+                    case  2: return kCpumMicroarch_AMD_K7_Palomino;
+                    case  3: return kCpumMicroarch_AMD_K7_Spitfire;
+                    case  4: return kCpumMicroarch_AMD_K7_Thunderbird;
+                    case  6: return kCpumMicroarch_AMD_K7_Palomino;
+                    case  7: return kCpumMicroarch_AMD_K7_Morgan;
+                    case  8: return kCpumMicroarch_AMD_K7_Thoroughbred;
+                    case 10: return kCpumMicroarch_AMD_K7_Barton; /* Thorton too. */
                 }
                 return kCpumMicroarch_AMD_K7_Unknown;
             case 0x0f:
