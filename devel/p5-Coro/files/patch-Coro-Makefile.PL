--- Coro/Makefile.PL.orig	2009-03-11 22:39:55.000000000 +0800
+++ Coro/Makefile.PL	2009-03-11 22:48:31.000000000 +0800
@@ -23,9 +23,9 @@
 
 EOF
 
-if (prompt ("Skip further questions and use defaults (y/n)?", "y") =~ /[yY]/) {
+#if (prompt ("Skip further questions and use defaults (y/n)?", "y") =~ /[yY]/) {
    $ENV{PERL_MM_USE_DEFAULT} = 1;
-}
+#}
 
 
 $DEFINE .= " -DHAVE_MMAP" if $Config{d_mmap} eq "define" && $Config{d_munmap} eq "define";
@@ -164,10 +164,11 @@
 
 retry:
 
-my $r = prompt "Use which implementation,\n" .
-               "<s>et/longjump, <u>context, <a>ssembly, <i>rix, <l>inux or <w>indows?",
-               $iface;
-$iface = lc $1 if $r =~ /(\S)/;
+#my $r = prompt "Use which implementation,\n" .
+#               "<s>et/longjump, <u>context, <a>ssembly, <i>rix, <l>inux or <w>indows?",
+#               $iface;
+#$iface = lc $1 if $r =~ /(\S)/;
+$iface = 'u';
 
 if ($iface eq "u") {
    $DEFINE .= " -DCORO_UCONTEXT";
@@ -232,7 +233,8 @@
 
 my $stacksize = $^O eq "linux" && $] < 5.008008 ? 128 * 1024 : 16384;
 
-$stacksize = prompt ("C stack size factor?", $stacksize);
+#$stacksize = prompt ("C stack size factor?", $stacksize);
+my $stacksize = 65536;
 $DEFINE .= " -DCORO_STACKSIZE=$stacksize";
 
 print "using a stacksize of $stacksize * sizeof(long)\n";
@@ -259,7 +261,8 @@
 
 EOF
 
-my $stackguard = prompt ("Number of guard pages (0 disables)?", "4");
+#my $stackguard = prompt ("Number of guard pages (0 disables)?", "4");
+my $stackguard = 4;
 $DEFINE .= " -DCORO_STACKGUARD=$stackguard";
 
 print <<EOF;
@@ -277,8 +280,9 @@
 
 EOF
 
-my $valgrind = prompt ("Enable valgrind support (y/n)?",
-                       -r "/usr/include/valgrind/valgrind.h" ?  "y" : "n");
+#my $valgrind = prompt ("Enable valgrind support (y/n)?",
+#                       -r "/usr/include/valgrind/valgrind.h" ?  "y" : "n");
+my $valgrind='n';
 $DEFINE .= " -DCORO_USE_VALGRIND=1" if $valgrind =~ /[yY]/;
 
 
@@ -295,9 +299,9 @@
 
 EOF
 
-my $use_internals = prompt ("Prefer perl functions over coro functions (y/n)?", "n");
-$DEFINE .= " -DCORO_PREFER_PERL_FUNCTIONS=1" if $use_internals =~ /[yY]/;
-
+#my $use_internals = prompt ("Prefer perl functions over coro functions (y/n)?", "n");
+#$DEFINE .= " -DCORO_PREFER_PERL_FUNCTIONS=1" if $use_internals =~ /[yY]/;
+my $use_internals='n';
 print <<EOF;
 
 *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** 
