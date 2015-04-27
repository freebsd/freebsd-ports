--- cpan/Pod-Perldoc/lib/Pod/Perldoc/BaseTo.pm.orig	2013-03-04 15:16:21 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc/BaseTo.pm
@@ -33,6 +33,7 @@ BEGIN {
  *is_linux   = $^O eq 'linux'    ? \&TRUE : \&FALSE unless defined &is_linux;
  *is_hpux    = $^O =~ m/hpux/    ? \&TRUE : \&FALSE unless defined &is_hpux;
  *is_openbsd = $^O =~ m/openbsd/ ? \&TRUE : \&FALSE unless defined &is_openbsd;
+ *is_freebsd = $^O =~ m/freebsd/ ? \&TRUE : \&FALSE unless defined &is_freebsd;
 }
 
 sub _perldoc_elem {
