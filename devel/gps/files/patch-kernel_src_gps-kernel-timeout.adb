--- kernel/src/gps-kernel-timeout.adb.orig	2016-05-16 09:45:57 UTC
+++ kernel/src/gps-kernel-timeout.adb
@@ -388,7 +388,7 @@ package body GPS.Kernel.Timeout is
       Fd := Data.D.Descriptor;
       if Fd /= null then
          loop
-            Expect (Fd.all, Result, Data.Expect_Regexp.all, Timeout => 1);
+            Expect (Fd.all, Result, Data.Expect_Regexp.all, Timeout => 100);
 
             if Result /= Expect_Timeout then
                --  Received something. Cancel timeout
