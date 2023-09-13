--- t/01-proxy-proc-safeexec.t.orig	2023-09-13 21:35:18 UTC
+++ t/01-proxy-proc-safeexec.t
@@ -6,7 +6,7 @@ use warnings;
 use English;
 use Syntax::Keyword::Try;
 
-use Test::More tests => 23;
+use Test::More tests => 24;
 
 use Log::Log4perl;
 Log::Log4perl->easy_init( { level   => 'ERROR' } );
