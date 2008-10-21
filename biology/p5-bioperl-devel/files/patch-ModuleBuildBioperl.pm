--- ModuleBuildBioperl.pm.orig	2007-02-14 05:37:47.000000000 -0600
+++ ModuleBuildBioperl.pm	2008-10-17 23:16:52.000000000 -0500
@@ -93,7 +93,7 @@
     closedir($scripts_dir);
     my $question = $int_ok ? "Install [a]ll Bioperl scripts, [n]one, or choose groups [i]nteractively?" : "Install [a]ll Bioperl scripts or [n]one?";
     
-    my $prompt = $self->prompt($question, 'a');
+    my $prompt = 'a'; # $self->prompt($question, 'a');
     
     if ($prompt =~ /^[aA]/) {
         $self->log_info("  - will install all scripts\n");
@@ -328,7 +328,7 @@
                     
                     $status->{message} .= "\n   (wanted for $why, used by $by_what)";
                     
-                    my $installed = $self->install_optional($modname, $preferred_version, $status->{message});
+                    my $installed = 'skip'; # $self->install_optional($modname, $preferred_version, $status->{message});
                     next if $installed eq 'ok';
                     $status->{message} = $installed unless $installed eq 'skip';
                 }
