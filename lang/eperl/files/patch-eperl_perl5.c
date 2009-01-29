--- ./eperl_perl5.c.orig	1998-08-02 10:33:55.000000000 -0400
+++ ./eperl_perl5.c	2009-01-29 13:27:30.000000000 -0500
@@ -33,6 +33,8 @@
 **  eperl_perl5.c -- ePerl Perl5 related stuff
 */
 
+#define PERL_POLLUTE
+
 #include "eperl_config.h"
 #include "eperl_global.h"
 #include "eperl_perl5.h"
