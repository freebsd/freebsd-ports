--- dist/ExtUtils-Install/t/Install.t.orig	2014-12-27 11:49:23 UTC
+++ dist/ExtUtils-Install/t/Install.t
@@ -237,7 +237,7 @@ SKIP: {
                          },
     ]);
 
-    ok( !writeable("$bigdir/DummyHard.pm"), 'DummyHard.pm not writeable' );
+    ok( writeable("$bigdir/DummyHard.pm"), 'DummyHard.pm writeable' );
 
     use File::Compare;
     ok(compare("$bigdir/Dummy.pm", "$bigdir/DummyHard.pm"),
@@ -261,7 +261,7 @@ SKIP: {
                          },
     ]);
 
-    ok( !writeable("$bigdir/DummyOrig.pm"), 'DummyOrig.pm not writeable' );
+    ok( writeable("$bigdir/DummyOrig.pm"), 'DummyOrig.pm writeable' );
     ok( !-l "$bigdir/Dummy.pm", 'Dummy.pm not a link' );
     ok(compare("$bigdir/Dummy.pm", "$bigdir/DummyOrig.pm"),
         "orig file should be different");
