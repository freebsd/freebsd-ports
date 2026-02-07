--- Makefile.PL.orig	2016-04-25 19:04:54 UTC
+++ Makefile.PL
@@ -1,7 +1,6 @@
 use 5.008003;
 use ExtUtils::MakeMaker;
 
-use Canary::Stability JSON::XS => 1, 5.008003;
 
 WriteMakefile(
     dist	 => {
@@ -16,6 +15,6 @@ WriteMakefile(
        common::sense     => 0,
        Types::Serialiser => 0,
     },
-    CONFIGURE_REQUIRES => { ExtUtils::MakeMaker => 6.52, Canary::Stability => 0 },
+    CONFIGURE_REQUIRES => { ExtUtils::MakeMaker => 6.52 },
 );
 
