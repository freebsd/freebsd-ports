--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Any.pm.orig	2016-05-29 22:48:24 UTC
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Any.pm
@@ -2018,13 +2018,14 @@ sub init_INSTALL_from_PREFIX {
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
