--- lib/VCP/Source/p4.pm.orig	Fri Jan 30 10:48:36 2004
+++ lib/VCP/Source/p4.pm	Mon Apr 19 01:10:03 2004
@@ -781,8 +781,9 @@
             next ;
          }
          next if $spec =~ m{^error: //\.\.\.\@.+ file(\(s\))?( not in label.)?$} ;
+         next if $spec =~ m{^error: //\.\.\..+ - no such file\(s\)\.};
          $spec =~ /^.*?: *(\/\/.*#\d+)/
-            or die "Couldn't parse name & rev from '$spec' in p4 output:\n$files\n" ;
+            or die "Couldn't parse name & rev from '$spec' in p4 output:\n$files\n";
          my $id = $1;
 
          debug "p4 label '$label' => '$id'" if debugging ;
