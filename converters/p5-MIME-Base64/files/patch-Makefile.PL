--- Makefile.PL.orig	Mon Mar 10 00:07:50 2003
+++ Makefile.PL	Sat Apr  5 18:49:51 2003
@@ -6,6 +6,4 @@
     VERSION_FROM => 'Base64.pm',
     EXE_FILES    => [qw(encode-base64 decode-base64 encode-qp decode-qp)],
     dist         => { COMPRESS => 'gzip -9f', SUFFIX => 'gz', },
-    ($] >= 5.008) ?
-      (INSTALLDIRS => 'perl') : (),
 );
