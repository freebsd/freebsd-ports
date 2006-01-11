--- Coro/Makefile.PL.orig	Wed Jan 11 13:20:06 2006
+++ Coro/Makefile.PL	Wed Jan 11 13:22:18 2006
@@ -31,77 +31,8 @@ if ($^O =~ /win32/i or $^O =~ /cygwin/ o
    $iface = "s";
 }
 
-print <<EOF;
-
-*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** 
-
-C context sharing: This option makes it possible to share the C stack and
-context between many coroutines, resulting in large memory savings and
-slight speed gains, at the cost of potential (but mostly theoretical)
-segfaults. On my Linux/x86 machine this decreased the size of a new
-coroutine from 9k to 5k, but the savings are much more apparent on
-machines without mmap or good memory management.
-
-The algorithm relies on the non-fact that the same machine stack pointer
-indicates the same function call nesting level, which usually works good
-enough (no known cases of it failing are known) but might fail in theory.
-
-The default (enabled) has been in use on productions servers for some
-time now, without any problem reports, so you are encouraged to use the
-default.
-
-EOF
-
-if (prompt ("Do you want to enable C context sharing (y/n)", "y") !~ /^\s*n/i) {
-   print "\nC context sharing enabled.\n\n";
+$iface = "u";
    $DEFINE .= " -DCORO_LAZY_STACK";
-}
-
-if ($iface) {
-   print <<EOF;
-
-*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** 
-
-Coro can use a number of methods to implement coroutines at the C
-level. The default chosen is based on your current confguration and is
-correct in most cases, but you still can chose between these alternatives:
-
-u  The unix 'ucontext.h' functions are relatively new and not implemented
-   or well-tested in older unices. They allow very fast coroutine creation
-   and reasonably fast switching, and, most importantly, are very stable.
-
-s  If the ucontext functions are not working or you don't want
-   to use them for other reasons you can try a workaround using
-   setjmp/longjmp/sigaltstack (also standard unix functions). Coroutine
-   creation is rather slow, but switching is very fast as well (often much
-   faster than with the ucontext functions). Unfortunately, glibc-2.1 and
-   below don't even feature a working sigaltstack.
-
-l  GNU/Linux. Very old GNU/Linux systems (glibc-2.1 and below) need
-   this hack. Since it is very linux-specific it is also quite fast and
-   recommended even for newer versions; when it works, that is (currently
-   x86 and a few others only. If it compiles, it's usually ok).
-
-i  IRIX. For some reason, SGI really does not like to follow the single
-   unix specification (does that surprise you?), so this workaround might
-   be needed (it's fast), although [s] and [u] should also work now.
-
-w  Microsoft Windows. Try this on Microsoft Windows, although, as there is
-   no standard on how to do this under windows, this might work only on
-   cygwin or specific versions of msvc. Your problem.
-
-For most systems, the default chosen should be OK. If you experience
-problems then you should experiment with this setting and/or turn off
-optimizations (make OPTIMIZE=-O0).
-
-EOF
-
-retry:
-
-   my $r = prompt "Use which implementation,\n" .
-                  "<s>etjmp/longjump, <u>context, <i>rix, <l>inux or <w>indows?",
-                  $iface;
-   $iface = lc $1 if $r =~ /(\S)/;
 
    if ($iface eq "u") {
       $DEFINE .= " -DCORO_UCONTEXT";
@@ -122,37 +53,9 @@ retry:
       print "\nUsing windows-specific implementation\n\n";
    } else {
       print "\nUnknown implementation \"$iface\"\n";
-      goto retry;
    }
-} else {
-   print "\nUsing microsoft compatible coroutines\n\n";
-}
-
-print <<EOF;
-
-*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** 
-
-Per-context stack size factor: Depending on your settings, Coro tries to
-share the C stack as much as possible, but sometimes it needs to allocate
-a new one. This setting controls the maximum size that gets allocated,
-and should not be set too high, as memory and address space still is
-wasted even if it's not fully used. The value entered will be multiplied
-by sizeof(long), which is usually 4 on 32-bit systems, and 8 on 64-bit
-systems.
-
-A setting of 16384 (the default) therefore corresponds to a 64k..128k
-stack, which usually is ample space (you might even want to try 8192 or
-lower if your program creates many coroutines).
-
-Some perls (mostly threaded ones and perl compiled under linux 2.6) and
-some programs (inefficient regexes can use a lot of stack space) may
-need much, much more: If Coro segfaults with weird backtraces (e.g. in a
-function prologue) or in t/10_bugs.t, you might want to increase this to
-65536 or more.
-
-EOF
 
-my $stacksize = prompt ("C stack size factor", "16384");
+my $stacksize = 65536;
 $DEFINE .= " -DSTACKSIZE=$stacksize";
 
 print "using a stacksize of $stacksize * sizeof(long)\n";
