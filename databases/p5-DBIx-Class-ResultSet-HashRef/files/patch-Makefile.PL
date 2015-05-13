--- Makefile.PL.orig	2009-06-14 17:01:15 UTC
+++ Makefile.PL
@@ -13,5 +13,5 @@ requires 'DBIx::Class';
 
 test_requires 'Test::More';
 
-auto_install;
+#auto_install;
 WriteAll;
