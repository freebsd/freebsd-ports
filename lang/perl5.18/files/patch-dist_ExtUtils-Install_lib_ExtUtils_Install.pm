--- dist/ExtUtils-Install/lib/ExtUtils/Install.pm.orig	2014-10-01 01:33:00 UTC
+++ dist/ExtUtils-Install/lib/ExtUtils/Install.pm
@@ -797,7 +797,7 @@ sub install { #XXX OS-SPECIFIC
                 utime($atime,$mtime + $Is_VMS,$targetfile) unless $dry_run>1;
 
 
-                $mode = 0444 | ( $mode & 0111 ? 0111 : 0 );
+                $mode = 0644 | ( $mode & 0111 ? 0111 : 0 );
                 $mode = $mode | 0222
                     if $realtarget ne $targetfile;
                 _chmod( $mode, $targetfile, $verbose );
