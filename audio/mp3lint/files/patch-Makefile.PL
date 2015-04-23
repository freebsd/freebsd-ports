--- Makefile.PL.orig	2015-04-22 12:59:15 UTC
+++ Makefile.PL
@@ -124,7 +124,7 @@ sub MY::install {
   my $self = shift;
   my $inherited = $self->SUPER::install(@_);
   my $conf="\t\t\$(INST_SYSCONFDIR) \$(DESTINSTALLSYSCONFDIR)";
-  $inherited =~ s/(^\s*\$\(INST_MAN)3(DIR\s*.*MAN)3(DIR\))/${1}3${2}3$3 \\\n${1}5${2}5$3 \\\n$conf/gm;
+  $inherited =~ s/(^\s*"?\$\(INST_MAN)3(DIR"?.*MAN)3(DIR\)"?)/${1}3${2}3$3 \\\n${1}5${2}5$3 \\\n$conf/gm;
 
   return $inherited;
 }
