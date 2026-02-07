--- Makefile.PL.orig	2017-07-14 02:47:48 UTC
+++ Makefile.PL
@@ -1,6 +1,5 @@
 use ExtUtils::MakeMaker;
 
-use Canary::Stability Coro => 1, 5.008009;
 
 unless (-e "Coro/libcoro/coro.c") {
    print <<EOF;
@@ -89,7 +88,7 @@ WriteMakefile(
        #BDB              => 1.5,
        #AnyEvent::BDB    => 1.0,
     },
-    CONFIGURE_REQUIRES => { ExtUtils::MakeMaker => 6.52, Canary::Stability => 0 },
+    CONFIGURE_REQUIRES => { ExtUtils::MakeMaker => 6.52 },
     # neither configure_requires nor recommends can be used
     # for optional dependencies. whoever decided that a module needs
     # to build properly without its dependencies installed
