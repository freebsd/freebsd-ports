--- runtime/druntime/src/core/stdc/config.d.orig	2026-06-11 09:58:17 UTC
+++ runtime/druntime/src/core/stdc/config.d
@@ -689,6 +689,11 @@
 }
 
 version (PPC64)
-    enum PPCUseIEEE128 = real.mant_dig == 113;
+{
+    version (CRuntime_Glibc)
+        enum PPCUseIEEE128 = real.mant_dig == 113;
+    else
+        enum PPCUseIEEE128 = false;
+}
 else
     enum PPCUseIEEE128 = false;
