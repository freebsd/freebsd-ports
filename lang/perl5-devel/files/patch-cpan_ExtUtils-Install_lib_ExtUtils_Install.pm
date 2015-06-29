--- cpan/ExtUtils-Install/lib/ExtUtils/Install.pm.orig	2015-06-22 12:55:33 UTC
+++ cpan/ExtUtils-Install/lib/ExtUtils/Install.pm
@@ -809,7 +809,7 @@ sub install { #XXX OS-SPECIFIC
                 utime($atime,$mtime + $Is_VMS,$targetfile) unless $dry_run>1;
 
 
-                $mode = 0444 | ( $mode & 0111 ? 0111 : 0 );
+                $mode = 0644 | ( $mode & 0111 ? 0111 : 0 );
                 $mode = $mode | 0222
                     if $realtarget ne $targetfile;
                 _chmod( $mode, $targetfile, $verbose );
