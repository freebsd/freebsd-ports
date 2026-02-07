--- Makefile.PL.orig	2020-11-22 06:53:13 UTC
+++ Makefile.PL
@@ -268,7 +268,7 @@ if (scalar @bad) {
 
 # If we're doing a fake VPATH build, add a stub Makefile which forwards all
 # invocations (.DEFAULT is a GNU-make-ism).
-if (defined $builddir) {
+if (0) {
     open M, '>', "$builddir/Makefile~" or die $!;
     print M <<"EOF";
 all .DEFAULT:
