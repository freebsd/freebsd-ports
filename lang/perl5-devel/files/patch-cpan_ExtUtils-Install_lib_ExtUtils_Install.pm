Make installed files writable by the installing user.

--- cpan/ExtUtils-Install/lib/ExtUtils/Install.pm.orig	2017-06-05 16:14:15 UTC
+++ cpan/ExtUtils-Install/lib/ExtUtils/Install.pm
@@ -825,7 +825,7 @@ sub install { #XXX OS-SPECIFIC
                 utime($atime,$mtime + Is_VMS,$targetfile) unless $dry_run>1;
 
 
-                $mode = 0444 | ( $mode & 0111 ? 0111 : 0 );
+                $mode = 0644 | ( $mode & 0111 ? 0111 : 0 );
                 $mode = $mode | 0222
                     if $realtarget ne $targetfile;
                 _chmod( $mode, $targetfile, $verbose );
