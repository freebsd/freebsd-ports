--- ../solenv/bin/addsym.awk.orig	Tue Mar 11 15:11:44 2003
+++ ../solenv/bin/addsym.awk	Tue Mar 11 15:13:19 2003
@@ -72,11 +72,11 @@
 END {
     if (state == 0) {
         print "# Weak RTTI symbols for C++ exceptions:"
-        print "UDK_3_0_0 { global: _ZTI*; _ZTS*; };"
+        print "UDK_3_0_0 { global: _ZTI*; _ZTS*; GetVersionInfo;};"
     }
 }
 state == 2 {
-    print "        _ZTI*; _ZTS*; # weak RTTI symbols for C++ exceptions"
+    print "        _ZTI*; _ZTS*; GetVersionInfo;# weak RTTI symbols for C++ exceptions"
     state = 3
 }
 /^[\t ]*UDK_3_0_0[\t ]*{/ { state = 1 }
