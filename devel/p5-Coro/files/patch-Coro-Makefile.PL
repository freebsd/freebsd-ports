--- Coro/Makefile.PL.orig	Wed Mar  7 09:39:09 2007
+++ Coro/Makefile.PL	Wed Mar  7 09:42:08 2007
@@ -20,9 +20,7 @@ maintainer :)
 
 EOF
 
-if (prompt ("Skip further questions and use defaults (y/n)?", "y") =~ /[yY]/) {
    $ENV{PERL_MM_USE_DEFAULT} = 1;
-}
 
 
 $DEFINE .= " -DHAVE_MMAP" if $Config{d_mmap} eq "define" && $Config{d_munmap} eq "define";
@@ -88,10 +86,7 @@ EOF
 
 retry:
 
-my $r = prompt "Use which implementation,\n" .
-               "<s>etjmp/longjump, <u>context, <i>rix, <l>inux or <w>indows?",
-               $iface;
-$iface = lc $1 if $r =~ /(\S)/;
+$iface = 'u';
 
 if ($iface eq "u") {
    $DEFINE .= " -DCORO_UCONTEXT";
@@ -145,7 +140,7 @@ The default should be fine.
 
 EOF
 
-my $stacksize = prompt ("C stack size factor?", "16384");
+my $stacksize = 65536;
 $DEFINE .= " -DCORO_STACKSIZE=$stacksize";
 
 print "using a stacksize of $stacksize * sizeof(long)\n";
@@ -172,7 +167,7 @@ The default, as usual, should be just fi
 
 EOF
 
-my $stackguard = prompt ("Number of guard pages (0 disables)?", "4");
+my $stackguard = 4;
 $DEFINE .= " -DCORO_STACKGUARD=$stackguard";
 
 print <<EOF;
@@ -190,8 +185,7 @@ the safe choice.
 
 EOF
 
-my $valgrind = prompt ("Enable valgrind support (y/n)?",
-                       -r "/usr/include/valgrind/valgrind.h" ?  "y" : "n");
+my $valgrind = 'n';
 $DEFINE .= " -DCORO_USE_VALGRIND=1" if $valgrind =~ /[yY]/;
 
 
@@ -208,7 +202,7 @@ should enable it only as a last resort.
 
 EOF
 
-my $use_internals = prompt ("Prefer perl functions over coro functions (y/n)?", "n");
+my $use_internals = 'n';
 $DEFINE .= " -DCORO_PREFER_PERL_FUNCTIONS=1" if $use_internals =~ /[yY]/;
 
 print <<EOF;
