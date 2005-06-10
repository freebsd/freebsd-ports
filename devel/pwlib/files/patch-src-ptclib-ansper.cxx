--- src/ptclib/asnper.cxx	Fri Aug  1 02:11:38 2003
+++ src/ptclib/asnper.cxx	Fri Jun  3 14:32:55 2005
@@ -1224,6 +1224,11 @@
     return -1;
 
   value += lower;
+
+  // clamp value to upper limit
+  if (value > upper)
+    value = upper;
+
   return 0;
 }
 
@@ -1268,7 +1273,14 @@
     unsigned base;
     if (!MultiBitDecode(CountBits(upper - lower + 1), base))
       return -1;
-    return lower + base;   // 10.9.4.1
+    len = lower + base;   // 10.9.4.1
+
+    // clamp value to upper limit
+    if (len > upper)
+      len = upper;
+
+    return len;
+
   }
 
   if (upper < 65536)  // 10.9.3.3
@@ -1279,13 +1291,20 @@
   if (IsAtEnd())
     return -1;
 
-  if (SingleBitDecode() == 0)
-    return MultiBitDecode(7, len) ? 0 : -1;   // 10.9.3.6
+  if (SingleBitDecode() == 0) {
+    if (!MultiBitDecode(7, len))   // 10.9.3.6
+      return -1;                // 10.9.3.8 unsupported
+  }
+  else if (SingleBitDecode() == 0) {
+    if (!MultiBitDecode(14, len))    // 10.9.3.7
+      return -1;  // 10.9.3.8 unsupported
+  }
 
-  if (SingleBitDecode() == 0)
-    return MultiBitDecode(14, len) ? 0 : -1;    // 10.9.3.7
+  // clamp value to upper limit
+  if (len > upper)
+    len = upper;
 
-  return -1;  // 10.9.3.8 unsupported
+  return 0;
 }
 
 
