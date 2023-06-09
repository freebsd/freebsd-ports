--- Makefile.PL.orig	2008-01-08 05:28:47 UTC
+++ Makefile.PL
@@ -29,7 +29,7 @@ use Test::More 0.4;
 use DBI::DBD;   # DBD creation tools
 
 my $ib_dir_prefix;
-
+=rem
 # init stuff
 my $IB_Bin_path = '';
 my $isql_name;
@@ -83,7 +83,12 @@ else
     @ib_bin_dirs = (qw(/usr/interbase/bin /opt/interbase/bin /opt/firebird/bin /usr/bin /usr/local/bin));
     @ib_inc_dirs = (qw(/usr/interbase/include /opt/interbase/include /opt/firebird/include /usr/include));
 }
-
+=cut
+my $IB_BASE='/usr/local';
+my $IB_Bin_path = $IB_BASE.'/bin';
+my $isql_name = 'isql';
+my $ib_lib_dir = $IB_BASE.'/lib';
+my $ib_inc = $IB_BASE.'/include';
 sub locate_dbi_arch_dir {
     my $dbidir = dbd_dbi_dir();
     my @try = map { "$_/auto/DBI" } @INC;
@@ -92,7 +97,7 @@ sub locate_dbi_arch_dir {
     Carp::carp( "Multiple copies of Driver.xst found in: @xst") if @xst > 1;
     return $xst[0];
 }
-
+=rem
 ################################################################################
 # sub test_files - checks if at least one of the files in the list exists
 # Paramters:
@@ -305,13 +310,13 @@ sub create_test_db
 
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
@@ -321,8 +326,8 @@ my $is_final = $IBVERSION =~ /\.6\d+$/ ? 1 : 0;
 
 # prompt for IB include dir
 my $ib_inc = dir_choice("InterBase/Firebird include directory", [@ib_inc_dirs], [qw(gds.h ibase.h)]);
+=cut
 
-
 # we use a hash for the MakeMaker parameters
 my %MakeParams = (
     'NAME'          => 'DBD::InterBase',
@@ -332,14 +337,14 @@ my %MakeParams = (
     'CCFLAGS'       => '-Wall -fno-strict-aliasing',
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
@@ -545,7 +550,7 @@ else
 
 # create the test config file
 make_test_conf();
-
+=cut
 # and last but not least write the makefile
 WriteMakefile(%MakeParams);
 
