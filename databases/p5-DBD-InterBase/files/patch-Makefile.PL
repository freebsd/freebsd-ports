--- Makefile.PL.OOO	Thu Jul 18 21:02:53 2002
+++ Makefile.PL	Thu Jul 18 21:16:22 2002
@@ -28,6 +28,7 @@
 
 my $ib_dir_prefix;
 
+=rem
 # init stuff
 my $IB_Bin_path = '';
 my $isql_name;
@@ -78,6 +79,12 @@
     @ib_bin_dirs = (qw(/usr/interbase/bin /opt/interbase/bin /usr/bin /usr/local/bin));
     @ib_inc_dirs = (qw(/usr/interbase/include /opt/interbase/include /usr/include));
 }
+=cut
+my $IB_BASE='%%IB_BASE%%';
+my $IB_Bin_path = $IB_BASE.'/bin';
+my $isql_name = 'isql';
+my $ib_lib_dir = $IB_BASE.'/lib';
+my $ib_inc = $IB_BASE.'/include';
 
 sub locate_dbi_arch_dir {
     my $dbidir = dbd_dbi_dir();
@@ -88,6 +95,7 @@
     return $xst[0];
 }
 
+=rem
 ################################################################################
 # sub test_files - checks if at least one of the files in the list exists
 # Paramters:
@@ -264,6 +272,7 @@
 
 # prompt for InterBase bin directory
 $IB_Bin_path = dir_choice("InterBase bin directory", [@ib_bin_dirs], [qw(gfix gfix.exe)]);
+=cut
 
 unless(-x $IB_Bin_path)
 {
@@ -271,6 +280,7 @@
     exit 1;
 }
 
+=rem
 # get InterBase version
 my $IBVERSION;
 my $GFIX_PATH = $IB_Bin_path . "/" . test_files($IB_Bin_path, [qw(gfix gfix.exe)]);
@@ -281,6 +291,7 @@
 # prompt for IB include dir
 my $ib_inc = dir_choice("InterBase include directory", [@ib_inc_dirs], [qw(gds.h ibase.h)]);
 
+=cut
 
 # we use a hash for the MakeMaker parameters
 my %MakeParams = (
@@ -291,7 +302,7 @@
     'CCFLAGS'       => '',
     'INC'           => qq(-I"$ib_inc" -I"${\locate_dbi_arch_dir()}"),
     'OBJECT'        => "InterBase.o dbdimp.o",
-    'LIBS'          => [''],
+    'LIBS'          => "-L$ib_lib_dir -lgds",
     'OPTIMIZE'      => $Config::Config{'optimize'},
     'XSPROTOARG'    => '-noprototypes',
     'dist'          => {COMPRESS=>'gzip -9f', SUFFIX=>'gz'},
@@ -299,6 +310,7 @@
     'realclean'     => {FILES => "t/test.conf"},
 );
 
+=rem
 # the OS specific build environment setup
 my $os = $Config::Config{'osname'};
 if ($os eq 'MSWin32')
@@ -473,6 +485,7 @@
 
 # create the test config file
 make_test_conf();
+=cut
 
 # and last but not least write the makefile
 WriteMakefile(%MakeParams);
@@ -482,6 +495,7 @@
     return dbd_postamble(@_);
 }
 
+=rem
 package main;
 
 # the data used to create the database creation script
@@ -489,3 +503,4 @@
 CREATE DATABASE "__TESTDB__" user "__USER__" password "__PASS__";
 
 quit;
+=cut
