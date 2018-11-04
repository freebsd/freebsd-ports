--- common.pl.orig	2016-05-02 03:41:48 UTC
+++ common.pl
@@ -10,8 +10,8 @@ my $gimptool = File::Spec->catfile($gimp
 my ($plugindir, $pluginlibs) = split /\n/, `$gimptool --gimpplugindir --libs`;
 
 my $gimpbinname = ExtUtils::PkgConfig->modversion("gimp-2.0");
-$gimpbinname =~ s/^(\d\.\d).*/$1/; # strip off minor versions
-die "Need GIMP version at least 2.8.0\n" unless $gimpbinname >= 2.8;
+$gimpbinname =~ s/^(\d+\.\d+\.\d+).*/$1/; # strip off minor versions
+die "Need GIMP version at least 2.8.0\n" unless $gimpbinname >= 2.8.0;
 
 sub ag_getconfig {
   my %cfg = (
