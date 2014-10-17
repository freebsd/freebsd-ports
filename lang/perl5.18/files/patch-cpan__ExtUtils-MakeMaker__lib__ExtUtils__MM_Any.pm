--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Any.pm.orig	2014-10-01 01:32:59 UTC
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Any.pm
@@ -1714,13 +1714,14 @@
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
