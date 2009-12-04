--- Build.PL.orig	2009-09-30 00:33:45.000000000 +0800
+++ Build.PL	2009-12-01 10:25:51.000000000 +0800
@@ -37,7 +37,7 @@
                             'Test::More'                => 0,
                             'Module::Build'             => 0.2805,
                             'Test::Harness'             => 2.62,
-                            'CPAN'                      => 1.81
+                            #'CPAN'                      => 1.81
                            },
     recommends          => { # does what you would expect of recommends, except more informative output and generates optional_features in META.yml
                             'Ace'                       => '0/access of ACeDB database/Bio::DB::Ace,Bio::DB::GFF::Adaptor::ace',
@@ -234,86 +234,9 @@
 
 sub prompt_for_biodb {
     my $accept = shift;
-    my $proceed = $accept ? 0 : $build->y_n("Do you want to run the Bio::DB::GFF or ".
-                              "Bio::DB::SeqFeature::Store live database tests? ".
-                              "y/n", 'n');
-    
-    if ($proceed) {
-        my @driver_choices;
-        foreach my $poss ('SQLite', 'mysql', 'Pg', 'Oracle') {
-            if (grep {/$poss/i} @drivers) {
-                my $choice = $poss;
-                $choice =~ s/^(.)/[$1]/;
-                push(@driver_choices, $choice);
-            }
-        }
-        
-        my $driver;
-        if (@driver_choices > 1) {
-            my ($default) = $driver_choices[0] =~ /\[(.)/;
-            $driver = $build->prompt("Which database driver should be used? ".join(" ", @driver_choices), $default);
-        }
-        else {
-            ($driver) = $driver_choices[0] =~ /\[(.)/;
-        }
-        if ($driver =~ /^[mM]/) {
-            $driver = 'mysql';
-        }
-        elsif ($driver =~ /^[pP]/) {
-            $driver = 'Pg';
-        }
-        elsif ($driver =~ /^[oO]/) {
-            $driver = 'Oracle';
-        }
-        elsif ($driver =~ /^[sS]/) {
-            $driver = 'SQLite';
-        }
-        
-        my $test_db = $build->prompt("Which database should I use for testing the $driver driver?\n".
-                                     "This database should already be present but doesn't have to ".
-                                     "be preloaded for any schema", 'test');
-        my $test_host = $build->prompt("On which host is database '$test_db' running (hostname, ip address or host:port)", 'localhost');
-        my $test_user = $build->prompt("User name for connecting to database '$test_db'?", 'undef');
-        my $test_pass = $build->prompt("Password for connecting to database '$test_db'?", 'undef');
-        
-        my $use_host = 1;
-        if ($test_host eq 'undef' || $test_host eq 'localhost') {
-            $use_host = 0;
-        }
-        
-        my $test_dsn;
-        if ($driver eq 'Pg' || $driver eq 'SQLite') {
-            $test_dsn = "dbi:$driver:dbname=$test_db";
-            $mysql_ok = 0;
-        }
-        else {
-            $test_dsn = "dbi:$driver:database=$test_db";
-            $mysql_ok = 0;
-        }
-        if ($use_host) {
-            $test_dsn .= ";host=$test_host";
-        }
-        
-        $build->notes(dbd_driver => $driver);
-        $build->notes(test_db => $test_db);
-        $build->notes(test_host => $test_host);
-        $build->notes(test_user => $test_user eq 'undef' ? undef : $test_user);
-        $build->notes(test_pass => $test_pass eq 'undef' ? undef : $test_pass);
-        $build->notes(test_dsn => $test_dsn);
-        
-        $build->log_info("  - will run tests with database driver '$driver' and these settings:\n",
-                        "    Database $test_db\n",
-                        "    Host     $test_host\n",
-                        "    DSN      $test_dsn\n",
-                        "    User     $test_user\n",
-                        "    Password $test_pass\n");
-        $build->log_info("  - will not run the BioDBSeqFeature live ".
-                         "database tests (requires MySQL or Pg driver)\n") unless ($driver eq 'mysql' or $driver eq 'Pg');
-    }
-    else {
-        $build->log_info("  - will not run the BioDBGFF or BioDBSeqFeature live database tests\n");
-    }
     
+    my $proceed = 0;
+    $build->log_info("  - will not run the BioDBGFF or BioDBSeqFeature live database tests\n");
     $build->log_info("\n");
     return $proceed;
 }
