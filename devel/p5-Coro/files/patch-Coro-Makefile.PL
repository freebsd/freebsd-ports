--- Coro/Makefile.PL.orig	Sun Jun 17 01:31:38 2007
+++ Coro/Makefile.PL	Sun Jun 17 01:35:46 2007
@@ -20,9 +20,7 @@
 
 EOF
 
-if (prompt ("Skip further questions and use defaults (y/n)?", "y") =~ /[yY]/) {
    $ENV{PERL_MM_USE_DEFAULT} = 1;
-}
 
 
 $DEFINE .= " -DHAVE_MMAP" if $Config{d_mmap} eq "define" && $Config{d_munmap} eq "define";
@@ -104,10 +102,7 @@
 
 retry:
 
-my $r = prompt "Use which implementation,\n" .
-               "<s>et/longjump, <u>context, <a>ssembly, <i>rix, <l>inux or <w>indows?",
-               $iface;
-$iface = lc $1 if $r =~ /(\S)/;
+$iface = 'u';
 
 if ($iface eq "u") {
    $DEFINE .= " -DCORO_UCONTEXT";
@@ -165,7 +160,7 @@
 
 EOF
 
-my $stacksize = prompt ("C stack size factor?", "16384");
+my $stacksize = 65536;
 $DEFINE .= " -DCORO_STACKSIZE=$stacksize";
 
 print "using a stacksize of $stacksize * sizeof(long)\n";
@@ -192,7 +187,7 @@
 
 EOF
 
-my $stackguard = prompt ("Number of guard pages (0 disables)?", "4");
+my $stackguard = 4;
 $DEFINE .= " -DCORO_STACKGUARD=$stackguard";
 
 print <<EOF;
@@ -210,8 +205,7 @@
 
 EOF
 
-my $valgrind = prompt ("Enable valgrind support (y/n)?",
-                       -r "/usr/include/valgrind/valgrind.h" ?  "y" : "n");
+my $valgrind = 'n';
 $DEFINE .= " -DCORO_USE_VALGRIND=1" if $valgrind =~ /[yY]/;
 
 
@@ -228,7 +222,7 @@
 
 EOF
 
-my $use_internals = prompt ("Prefer perl functions over coro functions (y/n)?", "n");
+my $use_internals = 'n';
 $DEFINE .= " -DCORO_PREFER_PERL_FUNCTIONS=1" if $use_internals =~ /[yY]/;
 
 print <<EOF;
