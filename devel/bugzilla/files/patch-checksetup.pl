--- checksetup.pl.orig	Fri Jan 14 10:51:36 2005
+++ checksetup.pl	Mon Jan 24 17:39:29 2005
@@ -616,7 +616,7 @@
 
 my $webservergroup_default;
 if ($^O !~ /MSWin32/i) {
-    $webservergroup_default = 'apache';
+    $webservergroup_default = 'nogroup';
 } else {
     $webservergroup_default = '';
 }
