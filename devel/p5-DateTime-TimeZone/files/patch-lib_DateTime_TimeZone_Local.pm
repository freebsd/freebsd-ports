--- lib/DateTime/TimeZone/Local.pm.orig	Tue Aug 29 09:32:17 2006
+++ lib/DateTime/TimeZone/Local.pm	Fri Dec 22 11:00:55 2006
@@ -144,6 +144,7 @@
                     if ( ! defined $real_name
                          && -f $_
                          && ! -l $_
+                         && $_ ne "/usr/share/zoneinfo/posixrules"
                          && $size == -s $_
                          && File::Compare::compare( $_, $file_to_match ) == 0
                        )
