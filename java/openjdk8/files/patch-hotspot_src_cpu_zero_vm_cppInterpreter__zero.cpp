--- hotspot/src/cpu/zero/vm/cppInterpreter_zero.cpp	Mon Apr 25 21:03:53 2016 +0000
+++ hotspot/src/cpu/zero/vm/cppInterpreter_zero.cpp	Tue Apr 26 02:49:59 2016 +0100
@@ -220,9 +220,16 @@
   // Push our result
   for (int i = 0; i < result_slots; i++) {
     // Adjust result to smaller
-    intptr_t res = result[-i];
+    union {
+      intptr_t res;
+      jint res_jint;
+    };
+    res = result[-i];
     if (result_slots == 1) {
-      res = narrow(method->result_type(), res);
+      BasicType t = method->result_type();
+      if (is_subword_type(t)) {
+        res_jint = (jint)narrow(t, res_jint);
+      }
     }
     stack->push(res);
   }
