--- bin/build_vcp_executable.pl.orig	Sat Jan 31 12:03:32 2004
+++ bin/build_vcp_executable.pl	Tue Apr 13 02:08:36 2004
@@ -7,7 +7,8 @@
 =head1 SYNOPSIS
 
     cd VCP
-    bin\build_vcp_executable.pl
+    bin\build_vcp_executable.pl                ## build ./vcp-bin or ./vcp.exe
+    bin\build_vcp_executable.pl --build-vcp-pl ## build ./vcp.pl
 
 =head1 DESCRIPTION
 
@@ -65,8 +66,13 @@
 use lib "lib";
 use constant is_win32 => $^O =~ /Win32/i;
 
+use Getopt::Long;
 use VCP::TestUtils qw( run );
 
+GetOptions( "build-vcp-pl" => \my $build_vcp_pl ) or die $!;
+warn "ignoring command line parameter(s): ", join ", ", map "\"$_\"", @ARGV
+    if @ARGV;
+
 ## VCP uses lazy loading extensively...
 my %skip_modules = (
     "VCP::TestUtils"            => 1,
@@ -121,7 +127,7 @@
     close VCP_OUT;
 }
 
-my $exe_name = is_win32 ? "vcp.exe" : "vcp-bin";
+my $exe_name = $build_vcp_pl ? "vcp.pl" : is_win32 ? "vcp.exe" : "vcp-bin";
 
 if ( 1 ) {
     if ( -e $exe_name ) {
@@ -130,8 +136,9 @@
 
     my @cmd = (
         "pp",
-        "-o", $exe_name,
-#        "-p", "-B",  "-o", "vcp.pl",
+        $build_vcp_pl
+            ? ( "-P", "-o", "vcp.pl" )
+            : ( "-o", $exe_name ),
         "-lib=lib",
         sort(
             map "--add=$_", @modules#, map "lib/$_", @pod_files
