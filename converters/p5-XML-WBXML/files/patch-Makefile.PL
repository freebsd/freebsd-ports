--- Makefile.PL	Thu Aug 11 19:31:58 2005
+++ Makefile.PL	Thu May 25 15:42:44 2006
@@ -1,4 +1,4 @@
-use 5.008003;
+use 5.00600;
 use ExtUtils::MakeMaker;
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
@@ -8,9 +8,9 @@
     PREREQ_PM         => {}, # e.g., Module::Name => 1.1
     ABSTRACT_FROM  => 'lib/XML/WBXML.pm', # retrieve abstract from module
     AUTHOR         => 'David Glasser <glasser@bestpractical.com>',
-    LIBS              => ['-lwbxml2'], # e.g., '-lm'
+    LIBS              => ['-L/usr/local/lib -lwbxml2'], # e.g., '-lm'
     DEFINE            => '', # e.g., '-DHAVE_SOMETHING'
-    INC               => '-I.', # e.g., '-I. -I/usr/include/other'
+    INC               => '-I. -I/usr/local/include', # e.g., '-I. -I/usr/include/other'
 	# Un-comment this if you add C files to link with later:
     # OBJECT            => '$(O_FILES)', # link all the C files too
 );
