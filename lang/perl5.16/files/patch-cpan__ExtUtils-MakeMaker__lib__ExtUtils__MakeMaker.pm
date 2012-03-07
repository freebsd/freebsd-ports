--- ./cpan/ExtUtils-MakeMaker/lib/ExtUtils/MakeMaker.pm.orig	2012-03-07 04:45:16.252747795 +0000
+++ ./cpan/ExtUtils-MakeMaker/lib/ExtUtils/MakeMaker.pm	2012-03-07 04:46:18.391746557 +0000
@@ -401,6 +401,8 @@
     my($class,$self) = @_;
     my($key);
 
+    _convert_compat_attrs($self) if defined $self && $self;
+
     # Store the original args passed to WriteMakefile()
     foreach my $k (keys %$self) {
         $self->{ARGS}{$k} = $self->{$k};
