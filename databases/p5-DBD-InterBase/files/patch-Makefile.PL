--- Makefile.PL.orig	Sat Nov 22 06:12:11 2003
+++ Makefile.PL	Mon Dec  8 20:01:27 2003
@@ -28,7 +28,7 @@
 use DBI::DBD;   # DBD creation tools
 
 my $ib_dir_prefix;
-
+=rem
 # init stuff
 my $IB_Bin_path = '';
 my $isql_name;
@@ -82,7 +82,12 @@
     @ib_bin_dirs = (qw(/usr/interbase/bin /opt/interbase/bin /opt/firebird/bin /usr/bin /usr/local/bin));
     @ib_inc_dirs = (qw(/usr/interbase/include /opt/interbase/include /opt/firebird/include /usr/include));
 }
-
+=cut
+my $IB_BASE='%%IB_BASE%%';
+my $IB_Bin_path = $IB_BASE.'/bin';
+my $isql_name = 'isql';
+my $ib_lib_dir = $IB_BASE.'/lib';
+my $ib_inc = $IB_BASE.'/include';
 sub locate_dbi_arch_dir {
     my $dbidir = dbd_dbi_dir();
     my @try = map { "$_/auto/DBI" } @INC;
@@ -91,7 +96,7 @@
     Carp::carp( "Multiple copies of Driver.xst found in: @xst") if @xst > 1;
     return $xst[0];
 }
-
+=rem
 ################################################################################
 # sub test_files - checks if at least one of the files in the list exists
 # Paramters:
@@ -296,13 +301,13 @@
 
 # prompt for InterBase bin directory
 $IB_Bin_path = dir_choice("InterBase/Firebird bin directory", [@ib_bin_dirs], [qw(gfix gfix.exe)]);
-
+=cut
 unless(-x $IB_Bin_path)
 {
     carp "I cannot find your InterBase/Firebird installation.\nDBD::InterBase cannot build or run without InterBase.\n";
     exit 1;
 }
-
+=rem
 # get InterBase version
 my $IBVERSION;
 my $GFIX_PATH = $IB_Bin_path . "/" . test_files($IB_Bin_path, [qw(gfix gfix.exe)]);
@@ -312,7 +317,7 @@
 
 # prompt for IB include dir
 my $ib_inc = dir_choice("InterBase/Firebird include directory", [@ib_inc_dirs], [qw(gds.h ibase.h)]);
-
+=cut
 
 # we use a hash for the MakeMaker parameters
 my %MakeParams = (
@@ -323,14 +328,14 @@
     'CCFLAGS'       => '',
     'INC'           => qq(-I"$ib_inc" -I"${\locate_dbi_arch_dir()}"),
     'OBJECT'        => "InterBase.o dbdimp.o",
-    'LIBS'          => [''],
+    'LIBS'          => "-L$ib_lib_dir -lgds",
     'OPTIMIZE'      => $Config::Config{'optimize'},
     'XSPROTOARG'    => '-noprototypes',
     'dist'          => {COMPRESS=>'gzip -9f', SUFFIX=>'gz'},
     'clean'         => {FILES => "*.xsi *.old t/*.old *~ t/*~ trace.txt t/trace.txt lib/DBD/InterBase/*~ lib/DBD/InterBase/*.old lib/Bundle/DBD/*~ lib/Bundle/DBD/*.old"},
     'realclean'     => {FILES => "t/test.conf"},
 );
-
+=rem
 # the OS specific build environment setup
 my $os = $Config::Config{'osname'};
 if ($os eq 'MSWin32')
@@ -530,7 +535,7 @@
 
 # create the test config file
 make_test_conf();
-
+=cut
 # and last but not least write the makefile
 WriteMakefile(%MakeParams);
 
