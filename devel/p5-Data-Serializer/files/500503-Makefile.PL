--- Makefile.PL.orig	Tue Jun 10 21:30:54 2003
+++ Makefile.PL	Tue Jun 10 21:49:49 2003
@@ -15,3 +15,9 @@
                     'ZIP'=>'/usr/bin/zip','ZIPFLAGS'=>'-rl'}
 
 );
+
+sub MY::manifypods	{
+	package MY; my $self=shift;
+	$self->{MAN3PODS}->{'lib/Data/Serializer/Config/General.pm'}='$(INST_MAN3DIR)/Data::Serializer::Config::General.$(MAN3EXT)';
+	$self->SUPER::manifypods(@_);
+}
