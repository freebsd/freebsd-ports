--- Coro/Makefile.PL.orig	Fri Dec 22 05:06:26 2006
+++ Coro/Makefile.PL	Fri Jan  5 15:12:19 2007
@@ -20,9 +20,7 @@
 
 EOF
 
-if (prompt ("Skip further questions and use defaults (y/n)?", "y") =~ /[yY]/) {
    $ENV{PERL_MM_USE_DEFAULT} = 1;
-}
 
 
 $DEFINE .= " -DHAVE_MMAP" if $Config{d_mmap} eq "define" && $Config{d_munmap} eq "define";
@@ -88,9 +86,7 @@
 
 retry:
 
-my $r = prompt "Use which implementation,\n" .
-               "<s>etjmp/longjump, <u>context, <i>rix, <l>inux or <w>indows?",
-               $iface;
+my $r = 'u';
 $iface = lc $1 if $r =~ /(\S)/;
 
 if ($iface eq "u") {
@@ -145,7 +141,7 @@
 
 EOF
 
-my $stacksize = prompt ("C stack size factor?", "16384");
+my $stacksize = 65536;
 $DEFINE .= " -DSTACKSIZE=$stacksize";
 
 print "using a stacksize of $stacksize * sizeof(long)\n";
@@ -172,7 +168,7 @@
 
 EOF
 
-my $stackguard = prompt ("Number of guard pages (0 disables)?", "4");
+my $stackguard = 4;
 $DEFINE .= " -DSTACKGUARD=$stackguard";
 
 print <<EOF;
@@ -190,8 +186,7 @@
 
 EOF
 
-my $valgrind = prompt ("Enable valgrind support (y/n)?",
-                       -r "/usr/include/valgrind/valgrind.h" ?  "y" : "n");
+my $valgrind = 'n';
 $DEFINE .= " -DUSE_VALGRIND=1" if $valgrind =~ /[yY]/;
 
 
@@ -208,7 +203,7 @@
 
 EOF
 
-my $use_internals = prompt ("Prefer perl functions over coro functions (y/n)?", "n");
+my $use_internals = 'n';
 $DEFINE .= " -DPREFER_PERL_FUNCTIONS=1" if $use_internals =~ /[yY]/;
 
 print <<EOF;
