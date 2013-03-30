
$FreeBSD$

$NetBSD: patch-ag,v 1.13 2010/05/15 10:00:57 roy Exp $
 
When running terminfo but compiled for termcap, we cannot assume
that we actually have anything useable in termcap_term_buffer so just
use the terminfo fixed size defined ealier.

--- src/term.c.orig
+++ src/term.c
@@ -3111,11 +3111,6 @@
                    terminal_type);
     }
 
-#ifndef TERMINFO
-  if (strlen (tty->termcap_term_buffer) >= buffer_size)
-    emacs_abort ();
-  buffer_size = strlen (tty->termcap_term_buffer);
-#endif
   tty->termcap_strings_buffer = area = xmalloc (buffer_size);
   tty->TS_ins_line = tgetstr ("al", address);
   tty->TS_ins_multi_lines = tgetstr ("AL", address);
