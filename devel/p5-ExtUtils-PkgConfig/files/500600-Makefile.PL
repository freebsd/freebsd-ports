--- Makefile.PL.orig	Wed Sep 17 08:07:33 2003
+++ Makefile.PL	Sun Nov  2 21:13:30 2003
@@ -45,4 +45,14 @@
 	rpmbuild -ba --define \"_topdir $cwd/rpms\" perl-\$(DISTNAME).spec
 "
 }
-package MAIN;
+sub 	manifypods	{
+	my $self=shift;
+	$self->{MAN3PODS}->{'lib/ExtUtils/PkgConfig.pm'}='$(INST_MAN3DIR)/ExtUtils::PkgConfig.$(MAN3EXT)';
+	$self->SUPER::manifypods(@_);
+}
+sub	constants	{
+	my $self=shift;
+	$self->{MAN3PODS}->{'lib/ExtUtils/PkgConfig.pm'}='$(INST_MAN3DIR)/ExtUtils::PkgConfig.$(MAN3EXT)';
+	$self->SUPER::constants(@_);
+}
+
