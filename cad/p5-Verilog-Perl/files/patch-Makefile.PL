--- Makefile.PL.orig	2016-02-02 23:36:13 UTC
+++ Makefile.PL
@@ -11,7 +11,7 @@ use Config;
 
 sub MY::postamble {
     my $out="";
-    # Note OPTIMIZE is passed from upper makefile, so this code needed there too.
+    # Note OPTIMIZE is passed from upper gmakefile, so this code needed there too.
     # -O2 optimization seems unreasonably slow on nearly every platform.  I give up.
     my $optimize = $Config{optimize};  $optimize =~ s/(^| )-O2( |$)/\1-O\2/g;
     # pass hardening flags
@@ -86,6 +86,8 @@ cppcheck: $(CPPCHECK_DEP)
     return $out;
 }
 
+$CXX = $ENV{CXX};
+
 my $fail;
 local $! = undef;
 my $have_gen = -d "Preproc/gen";
@@ -97,7 +99,7 @@ my $have_gen = -d "Preproc/gen";
     if ($have_gen) { warn "\n-Note: 'bison' must be installed to build from sources\n"; }
     else { $fail=1; warn "\n%Error: 'bison' must be installed to build\n\n"; }
 }
-`g++ --version`; if ($?) { $fail=1; warn "\n%Error: 'gcc/g++' must be installed to build\n"; }
+system("$CXX --version"); if ($?) { $fail=1; warn "\n%Error: 'gcc/g++' must be installed to build\n"; }
 if ($fail) {
     if ($ENV{AUTOMATED_TESTING}) {
 	exit(0);
@@ -139,7 +141,7 @@ WriteMakefile(
 			},
 	      );
 
-my $mkv = `make --version`;
+my $mkv = `gmake --version`;
 if ($? || $mkv !~ /GNU Make/i) {
     warn "-Important: Now type 'gmake MAKE=gmake' as this package requires GNU Make\n";
 }
