$FreeBSD$

--- Coro/Makefile.PL.orig	Tue Aug 10 03:53:02 2004
+++ Coro/Makefile.PL	Tue Aug 10 16:14:57 2004
@@ -31,62 +31,15 @@
    $iface = "s";
 }
 
-print <<EOF;
-
-Version 0.12 introduced C context sharing. This makes it possible to share
-the C stack and context between many coroutines, resulting in memory
-savings and slight speed gains, at the cost of potential (but mostly
-theoretical) segfaults. On my Linux/x86 machine this decreased the size
-of a new coroutine from 9k to 5k, but the savings are much more apparent
-on machines without mmap or good memory management. This algorithm relies
-on the non-fact that the same machine stack pointer indicates the same
-function call nesting level, which usually works good enough but might
-fail...
-
-The default (enabled) has been in-use on productions servers for some time
-now, without any problem reports so far.
-
-EOF
-
-if (prompt ("Do you want to enable C context sharing (y/n)", "y") !~ /^\s*n/i) {
+if (1 || prompt ("Do you want to enable C context sharing (y/n)", "y") !~ /^\s*n/i) {
    print "\nExperimental context sharing enabled.\n\n";
    $DEFINE .= " -DCORO_LAZY_STACK";
 }
 
 if ($iface) {
-   print <<EOF;
-
-Coro can use various ways to implement coroutines at the C level:
-
-u  The unix ucontext functions are newer and not implemented in older
-   unices (or broken libc's like glibc-2.2.2 and below). They allow very
-   fast coroutine creation and fast switching, and, most importantly, are
-   very stable.
-
-s  If the ucontext functions are not working or you don't want
-   to use them for other reasons you can try a workaround using
-   setjmp/longjmp/sigaltstack (also standard unix functions).  Coroutine
-   creation is rather slow, but switching is very fast as well (often much
-   faster than with the ucontext functions). Unfortunately, glibc-2.1 and
-   below don't even feature a working sigaltstack.
-
-l  Older GNU/Linux systems (glibc-2.1 and below) need this hack. Since it is
-   very linux-specific it is also quite fast for newer versions; when it
-   works, that is (currently x86 only)...
-
-i  IRIX. For some reason, SGI really does not like to follow the unix
-   standard (does that surprise you?), so this workaround might be needed
-   (it's fast), although s and u should also work now.
-
-For most systems, the default chosen should be OK. If you experience
-problems then you should experiment with this setting and/or turn off
-optimizations (make OPTIMIZE=-O0).
-
-EOF
-
 retry:
 
-   my $r = prompt "Use which implementation,\n" .
+   my $r = 's' || prompt "Use which implementation,\n" .
                   "<s>etjmp/longjump, <u>context, <i>rix or <l>inux?",
                   $iface;
    $iface = lc $1 if $r =~ /(\S)/;
