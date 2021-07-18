Make installed files writable by the installing user.

--- cpan/ExtUtils-Install/lib/ExtUtils/Install.pm.orig	2021-01-04 00:39:17 UTC
+++ cpan/ExtUtils-Install/lib/ExtUtils/Install.pm
@@ -795,7 +795,7 @@ sub install { #XXX OS-SPECIFIC
                 utime($atime,$mtime + _Is_VMS,$targetfile) unless $dry_run>1;
 
 
-                $mode = 0444 | ( $mode & 0111 ? 0111 : 0 );
+                $mode = 0644 | ( $mode & 0111 ? 0111 : 0 );
                 $mode = $mode | 0222
                     if $realtarget ne $targetfile;
                 _chmod( $mode, $targetfile, $verbose );
