
$FreeBSD$

--- checksetup.pl.orig
+++ checksetup.pl
@@ -288,7 +288,7 @@
     }, 
     { 
         name => 'File::Spec', 
-        version => '0.82' 
+        version => '0' 
     }, 
     {
         name => 'File::Temp',
@@ -616,7 +616,7 @@
 
 my $webservergroup_default;
 if ($^O !~ /MSWin32/i) {
-    $webservergroup_default = 'apache';
+    $webservergroup_default = 'www';
 } else {
     $webservergroup_default = '';
 }
