--- Makefile.PL	2014-03-11 19:59:40.000000000 -0300
+++ Makefile.PL	2014-06-25 11:18:59.000000000 -0300
@@ -11,7 +11,7 @@
 
 sub MY::postamble {
     my $out="";
-    # Note OPTIMIZE is passed from upper makefile, so this code needed there too.
+    # Note OPTIMIZE is passed from upper gmakefile, so this code needed there too.
     # -O2 optimization seems unreasonably slow on nearly every platform.  I give up.
     my $optimize = $Config{optimize};  $optimize =~ s/(^| )-O2( |$)/\1-O\2/g;
     $out .= "OPTIMIZE = $optimize\n";
@@ -82,6 +82,8 @@
     return $out;
 }
 
+$CXX = $ENV{CXX};
+
 my $fail;
 local $! = undef;
 my $have_gen = -d "Preproc/gen";
@@ -93,7 +95,7 @@
     if ($have_gen) { warn "\n-Note: 'bison' must be installed to build from sources\n"; }
     else { $fail=1; warn "\n%Error: 'bison' must be installed to build\n\n"; }
 }
-`g++ --version`; if ($?) { $fail=1; warn "\n%Error: 'gcc/g++' must be installed to build\n"; }
+system("$CXX --version"); if ($?) { $fail=1; warn "\n%Error: 'gcc/g++' must be installed to build\n"; }
 if ($fail) {
     if ($ENV{AUTOMATED_TESTING}) {
 	exit(0);
@@ -135,8 +137,8 @@
 			},
 	      );
 
-my $mkv = `make --version`;
+my $mkv = `gmake --version`;
 if ($? || $mkv !~ /GNU Make/i) {
     warn "-Important: Now type 'gmake MAKE=gmake' as this package requires GNU Make\n";
 }
 1;
