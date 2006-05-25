--- Makefile.PL	Thu Aug 11 19:31:58 2005
+++ Makefile.PL	Thu May 25 15:13:58 2006
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
