--- tools/gnupod_install.pl.old	Sun Oct  5 12:10:32 2003
+++ tools/gnupod_install.pl	Fri Dec 12 21:38:37 2003
@@ -70,8 +70,7 @@
 my($basedir, $modi, $perlbin) = @_;
 die "Strange Perl installation, no \@INC! Can't install Perl-Module(s), killing myself..\n" if !$INC[0];
 
-mkdir("$INC[0]/$modi");
-chmod 0755, "$INC[0]/$modi";
+mkdir("$INC[0]/$modi", 0755);
 print "Installing Modules at $INC[0]/$modi\n";
 
  foreach my $file (glob("$basedir/*.pm")) {
