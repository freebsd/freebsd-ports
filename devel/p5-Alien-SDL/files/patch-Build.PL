--- Build.PL.orig	2015-02-21 19:53:18 UTC
+++ Build.PL
@@ -7,10 +7,6 @@ use Config;
 use My::Utility qw(check_config_script check_prebuilt_binaries check_prereqs_libs check_prereqs_tools $source_packs
                    check_perl_buildlibs);
 
-use Getopt::Long;
-my ( $ans, $travis ) = 0;
-GetOptions( "travis" => \$travis );
-
 print "Welcome to Alien::SDL module installation\n";
 print "-----------------------------------------\n";
 print "checking operating system... $^O\n";
@@ -215,23 +211,6 @@ else {
 
     $prompt_string .= "[" . $i++ . "] " . $c->{title} . "\n";
   }
-
-  # select option '1' for travis
-  if ( defined $travis and $travis == 1 ) {
-    $ans = 1;
-  }
-
-# or prompt user for build option
-  else {
-    $prompt_string .= "\nWhat way do you wanna go?";
-    $ans = $build->prompt( $prompt_string, $recommended_candidate );
-  }
-
-  if($ans > 0 && $ans < scalar(@candidates)) {
-    $choice = $candidates[$ans - 1];
-  }
-
-  $| = 0;
 } # end else search and prompt for build method
 
 #### store build params into 'notes'
