--- Bio/Root/Build.pm.orig	2014-07-10 22:13:23.000000000 +0200
+++ Bio/Root/Build.pm	2014-07-24 11:55:59.000000000 +0200
@@ -83,49 +83,9 @@
         }
     }
     closedir($scripts_dir);
-    my $question = $int_ok ? "Install [a]ll BioPerl scripts, [n]one, ".
-        "or choose groups [i]nteractively?" : "Install [a]ll BioPerl scripts ".
-        "or [n]one?";
-
-    my $prompt = $accept ? 'a' : $self->prompt($question, 'a');
-
-    if ($prompt =~ /^[aA]/) {
-        $self->log_info("  - will install all scripts\n");
-        $self->notes(chosen_scripts => 'all');
-    }
-    elsif ($prompt =~ /^[iI]/) {
-        $self->log_info("  - will install interactively:\n");
-
-        my @chosen_scripts;
-        foreach my $group_dir (@group_dirs) {
-            my $group = File::Basename::basename($group_dir);
-            print "    * group '$group' has:\n";
-
-            my @script_files = @{$self->rscan_dir($group_dir, qr/\.PLS$|\.pl$/)};
-            foreach my $script_file (@script_files) {
-                my $script = File::Basename::basename($script_file);
-                print "      $script\n";
-            }
-
-            my $result = $self->prompt("    Install scripts for group '$group'? [y]es [n]o [q]uit", 'n');
-            die if $result =~ /^[qQ]/;
-            if ($result =~ /^[yY]/) {
-                $self->log_info("      + will install group '$group'\n");
-                push(@chosen_scripts, @script_files);
-            }
-            else {
-                $self->log_info("      - will not install group '$group'\n");
-            }
-        }
 
-        my $chosen_scripts = @chosen_scripts ? join("|", @chosen_scripts) : 'none';
-
-        $self->notes(chosen_scripts => $chosen_scripts);
-    }
-    else {
-        $self->log_info("  - won't install any scripts\n");
-        $self->notes(chosen_scripts => 'none');
-    }
+    $self->log_info("  - willt install all scripts\n");
+    $self->notes(chosen_scripts => 'all');
 
     print "\n";
 }
@@ -1153,22 +1113,9 @@
 sub prompt_for_network {
     my ($self, $accept) = @_;
 
-    my $proceed = $accept ? 0 : $self->y_n(  "Do you want to run tests that require connection to servers across the internet\n"
-                                           . "(likely to cause some failures)? y/n", 'n');
-
-    if ($proceed) {
-        $self->notes('network' => 1);
-        $self->log_info("  - will run internet-requiring tests\n");
-        my $use_email = $self->y_n("Do you want to run tests requiring a valid email address? y/n",'n');
-        if ($use_email) {
-            my $address = $self->prompt("Enter email address:");
-            $self->notes(email => $address);
-        }
-    }
-    else {
-        $self->notes(network => 0);
-        $self->log_info("  - will not run internet-requiring tests\n");
-    }
+    my $proceed = 0;
+    $self->notes(network => 0);
+    $self->log_info("  - will not run internet-requiring tests\n");
 }
 
 =head2 print_build_script
