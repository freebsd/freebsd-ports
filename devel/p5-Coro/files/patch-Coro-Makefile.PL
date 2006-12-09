--- Coro/Makefile.PL.orig	Sat Dec  9 19:48:35 2006
+++ Coro/Makefile.PL	Sat Dec  9 19:51:08 2006
@@ -72,9 +72,7 @@
 
 retry:
 
-   my $r = prompt "Use which implementation,\n" .
-                  "<s>etjmp/longjump, <u>context, <i>rix, <l>inux or <w>indows?",
-                  $iface;
+   my $r = 'u';
    $iface = lc $1 if $r =~ /(\S)/;
 
    if ($iface eq "u") {
@@ -132,7 +130,7 @@
 
 EOF
 
-my $stacksize = prompt ("C stack size factor", "16384");
+my $stacksize = 65536;
 $DEFINE .= " -DSTACKSIZE=$stacksize";
 
 print "using a stacksize of $stacksize * sizeof(long)\n";
@@ -159,7 +157,7 @@
 
 EOF
 
-my $stackguard = prompt ("Number of guard pages (0 disables)", "4");
+my $stackguard = 4;
 $DEFINE .= " -DSTACKGUARD=$stackguard";
 
 print <<EOF;
@@ -177,7 +175,7 @@
 
 EOF
 
-my $valgrind = prompt ("Enable valgrind support (y/n)", "n");
+my $valgrind = 'n';
 $DEFINE .= " -DUSE_VALGRIND=1" if $valgrind =~ /[yY]/;
 
 print <<EOF;
