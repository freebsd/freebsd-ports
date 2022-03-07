Update methods 45, B1, and C2. Implement method E4.
https://sourceforge.net/p/ktoblzcheck/code/merge-requests/14/

--- src/lib/methods.cc.orig	2020-01-20 15:07:55 UTC
+++ src/lib/methods.cc
@@ -530,15 +530,15 @@ AccountNumberCheck::Result method_44(const int *accoun
     return algo01(11, weight, false, 10, account);
 }
 
+// method 45 was extended for due-date 2018-06-04
 AccountNumberCheck::Result method_45(const int *account, int *weight)
 {
-    // some numbers do not have a checksum
-    if (0 == account[0] || 1 == account[4]) {
+    // accountIDs starting with "0" or "48" do not have a check digit
+    // accountIDs that have "1" as the fifth digit do not have a check digit
+    if (0 == account[0] || 1 == account[4] || (4 == account[0] && 8 == account[1])) {
         return AccountNumberCheck::OK;
     }
-
-    number2Array("2121212120", weight);
-    return algo01(10, weight, true, 10, account);
+    return method_00(account, weight);
 }
 
 AccountNumberCheck::Result method_46(const int *account, int *weight)
@@ -1644,13 +1644,13 @@ AccountNumberCheck::Result method_B0(const int *accoun
 // Checked with Bundesbank-Testnumbers
 AccountNumberCheck::Result method_B1(const int *account, int *weight)
 {
-    number2Array("1371371370", weight);
-    if (AccountNumberCheck::OK == algo01(10, weight, false, 10, account)) {
-        return AccountNumberCheck::OK; // variant 1 (method "05")
+    if (AccountNumberCheck::OK == method_05(account, weight)) {
+        return AccountNumberCheck::OK; // variant 1
     }
-    number2Array("1731731730", weight);
-    return algo01(10, weight, false, 10, account);
-    // variant 2 (method "01")
+    if (AccountNumberCheck::OK == method_01(account, weight)) {
+        return AccountNumberCheck::OK; // variant 2
+    }
+    return method_00(account, weight); //variant 3, extended for due-date 2017-06-05
 }
 
 // Added by Jens Gecius (new Method as of September 6th, 2004)
@@ -1824,7 +1824,10 @@ AccountNumberCheck::Result method_C2(const int *accoun
     if (AccountNumberCheck::OK == method_22(account, weight)) { // variant 1
         return AccountNumberCheck::OK;
     }
-    return method_00(account, weight);   // variant 2
+    if (AccountNumberCheck::OK == method_00(account, weight)) { // variant 2
+        return AccountNumberCheck::OK;
+    }
+    return method_04(account, weight); // variant 3, extended for due-date 2017-09-04
 }
 
 // new method C3 and C4 valid from March 5th, 2007, checked with Bundesbank-Testnumbers
@@ -2190,6 +2193,16 @@ AccountNumberCheck::Result method_E3(const int *accoun
     return method_21(account, weight);               // variant 2
 }
 
+// new method E4 valid from 2017-06-05
+// checked with Bundesbank-Testnumbers
+AccountNumberCheck::Result method_E4(const int *account, int *weight)
+{
+    if (AccountNumberCheck::OK == method_02(account, weight)) { // variant 1
+        return AccountNumberCheck::OK;
+    }
+    return method_00(account, weight); // variant 2
+}
+
 struct method_func_s {
     const char *str;
     AccountNumberCheck::MethodFunc func;
@@ -2337,6 +2350,7 @@ const struct method_func_s cb_funcs[] = {
     { "E1", method_E1},
     { "E2", method_E2},
     { "E3", method_E3},
+    { "E4", method_E4},
     { 0, 0} // Important: The array has to end with the {0,0} entry,
     // otherwise initMethodMap() will runaway and crash!
 };
