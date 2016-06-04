--- Makefile.PL.orig	2015-03-27 19:07:42 UTC
+++ Makefile.PL
@@ -51,7 +51,7 @@ print $is_gcc_34 ? "yes\n" : "no\n";
 
 # Threads, Windows and 5.8.x don't seem to be best friends
 if ($^O eq 'MSWin32' && "$]" < 5.009) {
- push @DEFINES, '-DSU_MULTIPLICITY=0';
+ push @DEFINES, '-DXSH_MULTIPLICITY=0';
 }
 
 @DEFINES = (DEFINE => join ' ', @DEFINES) if @DEFINES;
