--- ../File-HStore-0.09-original/Makefile.PL	Sun Nov 26 11:05:53 2006
+++ Makefile.PL	Tue Jul 17 18:08:11 2007
@@ -5,8 +5,7 @@
 WriteMakefile(
     NAME              => 'File::HStore',
     VERSION_FROM      => 'lib/File/HStore.pm', # finds $VERSION
-    PREREQ_PM         => { 'Digest::SHA1' => '0', 
-			   'Digest::SHA2' => '0', 
+    PREREQ_PM         => { 'Digest::SHA' => '0', 
 			   'File::Copy' => '0',
 			   'Test::More' => '0',
 			   'File::Path' => '0' }, # e.g., Module::Name => 1.1
