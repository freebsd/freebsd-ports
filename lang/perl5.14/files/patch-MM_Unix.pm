--- lib/ExtUtils/MM_Unix.pm.orig	Tue Oct 28 22:12:01 2003
+++ lib/ExtUtils/MM_Unix.pm	Tue Oct 28 22:14:18 2003
@@ -2089,6 +2089,7 @@
           ('$(PREFIX)') x 3;
     }
     else {
+        $self->{PREFIX}   ||= $iprefix;  # for FreeBSD ports collection
         $self->{PERLPREFIX}   ||= $iprefix;
         $self->{SITEPREFIX}   ||= $sprefix;
         $self->{VENDORPREFIX} ||= $vprefix;
