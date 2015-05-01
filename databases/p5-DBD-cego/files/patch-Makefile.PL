--- Makefile.PL.orig	2015-05-01 16:47:29 UTC
+++ Makefile.PL
@@ -28,49 +28,30 @@ $opt = { "help" => \&Usage, };
 Getopt::Long::GetOptions(
     $opt,
     "help",
-    "prefix=s",
     "verbose",
     ) || die Usage();
 
-if (! exists $opt->{'prefix'}) 
-{
-  print "Missing prefix, use option --prefix\n"; 
-  die Usage();
-}
-
-use vars qw($loadlibs);
-$loadlibs= "-L" . $opt->{'prefix'} . " -llfc";
 my $so = $Config{so};
 
 WriteMakefile(
     'NAME'          => 'DBD::Cego',
     'VERSION_FROM'  => 'Cego.pm',
-    'PREREQ_PM'     => {DBI => 1.03},
+    'PREREQ_PM'     => {DBI => 1.633},
     'OBJECT'        => '$(O_FILES)',
-    'INC'           => '-I$(DBI_INSTARCH_DIR) -I' . $opt->{'prefix'} . '/include -I' . $opt->{'prefix'} . '/include',
-    'MYEXTLIB'    => $opt->{'prefix'} . "/lib/libcego.$so* " 
-	      . $opt->{'prefix'} . "/lib/liblfcxml.$so* " 
-	      . $opt->{'prefix'} . "/lib/liblfcbase.$so",
-    "CC" => "c++",
-    "LD" => "c++",
-    "XSPROTOARG" => "-noprototypes",
+    'INC'           => '-I$(DBI_INSTARCH_DIR) -I/usr/local/include',
+    'MYEXTLIB'      => '-lcego -llfcxml -llfcbase',
+    'CCFLAGS'       => '-O2 -pipe -fno-strict-aliasing -fpermissive',
+    'LD'            => '$(CC) -L/usr/local/lib',
     'OPTIMIZE'      => '-O3 -DNDEBUG=1',
-    'XSOPT'             => '-C++',
-    'TYPEMAPS'          => ['perlobject.map' ],
-    'LICENSE'	=> 'gpl3',
+    'XSPROTOARG'    => '-noprototypes',
+    'XSOPT'         => '-C++',
+    'TYPEMAPS'      => ['perlobject.map' ],
+    'LICENSE'       => 'gpl3',
     'clean'         => { FILES => 'config.h' },
 );
 
 sub Usage {
-  print STDERR <<"USAGE";
-Usage: perl $0 [options]
-
-Possible options are:
-
-  --prefix=<prefix path>       Use <prefix> for setting up the appropriate prefix path
-                               to find cego libs and includes
-
-USAGE
+  print STDERR "Usage: perl $0 [options]\n";
   exit 1;
 }
 
