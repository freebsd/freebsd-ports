--- bin/otrs.CheckModules.pl.orig	2010-12-02 18:26:47.000000000 +0000
+++ bin/otrs.CheckModules.pl	2010-12-02 18:39:46.000000000 +0000
@@ -39,7 +39,7 @@
         Required => 1,
     },
     {
-        Module   => 'CSS::Minifier',
+        Module   => 'CSS::Minifier::XS',
         Required => 1,
     },
     {
@@ -64,7 +64,7 @@
         Required => 1,
     },
     {
-        Module   => 'Digest::SHA::PurePerl',
+        Module   => 'Digest::SHA',
         Version  => '5.48',
         Required => 1,
         Comment  => 'Required to authenticate users and customers using SHA-1 or SHA-2 methods',
@@ -111,8 +111,7 @@
         Required => 1,
     },
     {
-        Module   => 'JavaScript::Minifier',
-        Version  => '1.05',
+        Module   => 'JavaScript::Minifier::XS',
         Required => 1,
     },
     {
