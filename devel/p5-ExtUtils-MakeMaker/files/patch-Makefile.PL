--- Makefile.PL.orig	2009-01-19 15:12:43.000000000 +0000
+++ Makefile.PL	2009-01-19 15:13:44.000000000 +0000
@@ -133,6 +133,8 @@
 
         $self->SUPER::init_PM;
 
+	return;
+
         # Only override older versions of modules with ours in inc/
         for my $inc (grep /^inc/, keys %{$self->{PM}}) {
             next unless $inc =~ /\.pm$/;
