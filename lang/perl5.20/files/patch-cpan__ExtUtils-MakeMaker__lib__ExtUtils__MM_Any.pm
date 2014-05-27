--- ./cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Any.pm.orig	2014-05-12 16:56:54.000000000 +0200
+++ ./cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Any.pm	2014-05-23 01:02:51.000000000 +0200
@@ -1744,13 +1744,14 @@
           ('$(PREFIX)') x 3;
     }
     else {
+        $self->{PREFIX}   ||= $iprefix;
         $self->{PERLPREFIX}   ||= $iprefix;
         $self->{SITEPREFIX}   ||= $sprefix;
         $self->{VENDORPREFIX} ||= $vprefix;
 
         # Lots of MM extension authors like to use $(PREFIX) so we
         # put something sensible in there no matter what.
-        $self->{PREFIX} = '$('.uc $self->{INSTALLDIRS}.'PREFIX)';
+        #$self->{PREFIX} = '$('.uc $self->{INSTALLDIRS}.'PREFIX)';
     }
 
     my $arch    = $Config{archname};
