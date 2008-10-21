--- Build.PL.orig	Wed Feb 14 05:37:47 2007
+++ Build.PL	Sun Jun 15 02:24:07 2008
@@ -32,7 +32,6 @@
                             'Test::More'                => 0,
                             'Module::Build'             => 0.2805,
                             'Test::Harness'             => 2.62,
-                            'CPAN'                      => 1.81
                            },
     recommends          => { # does what you would expect of recommends, except more informative output and generates optional_features in META.yml
                             'Ace'                       => '0/access of ACeDB database/Bio::DB::Ace,Bio::DB::GFF::Adaptor::ace',
@@ -174,7 +173,7 @@
 }
 
 sub prompt_for_biodbgff {
-    my $proceed = $build->y_n("Do you want to run the BioDBGFF live database tests? y/n", 'n');
+    my $proceed = undef; # $build->y_n("Do you want to run the BioDBGFF live database tests? y/n", 'n');
     
     if ($proceed) {
         my @driver_choices;
