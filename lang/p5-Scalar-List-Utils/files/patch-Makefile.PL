--- Makefile.PL.orig	Sun Sep 11 21:43:16 2005
+++ Makefile.PL	Sun Sep 11 21:43:37 2005
@@ -18,6 +18,7 @@ license		('perl');
 
 makemaker_args	( XS => {}, C => []) unless $do_xs;
 makemaker_args	( DEFINE      => "-DPERL_EXT",);
+makemaker_args  ( TYPEMAPS    => ["mytypemap"]) unless $] >= 5.006_01;
 
 installdirs	(qw(Scalar::Util List::Util));
 
