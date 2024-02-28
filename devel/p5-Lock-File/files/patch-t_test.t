--- t/test.t.orig	2013-06-16 20:59:45 UTC
+++ t/test.t
@@ -177,8 +177,8 @@ sub timeout :Tests {
         sleep 5; # timeout don't support float values, so we can't use tsleep here
     });
 
-    ok(exception { lockf("tfiles/lock", { timeout => 3, blocking => 0 }) }, "timeout is incompatible with blocking => 0");
-    ok(!exception { lockf("tfiles/lock", { timeout => 3, blocking => 1 }) }, "timeout is compatible with blocking => 1");
+    ok(exception { lockfile("tfiles/lock", { timeout => 3, blocking => 0 }) }, "timeout is incompatible with blocking => 0");
+    ok(!exception { lockfile("tfiles/lock", { timeout => 3, blocking => 1 }) }, "timeout is compatible with blocking => 1");
 }
 
 sub mode :Tests {
