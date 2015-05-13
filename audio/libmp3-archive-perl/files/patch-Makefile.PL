--- Makefile.PL.orig	2015-04-20 11:29:37 UTC
+++ Makefile.PL
@@ -77,7 +77,7 @@ sub MY::install {
   my $self = shift;
   my $inherited = $self->SUPER::install(@_);
   my $conf="\t\t\$(INST_SYSCONFDIR) \$(DESTINSTALLSYSCONFDIR)";
-  $inherited =~ s/(^\s*\$\(INST_MAN3DIR\s*.*MAN3DIR\))/$1 \\\n$conf/gm;
+  $inherited =~ s/(^\s*"?\$\(INST_MAN3DIR\s*.*MAN3DIR\).*$)/$1 \\\n$conf/gm;
 
   return $inherited;
 }
