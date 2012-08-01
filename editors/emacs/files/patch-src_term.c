$FreeBSD$

$NetBSD: patch-ag,v 1.13 2010/05/15 10:00:57 roy Exp $

When running terminfo but compiled for termcap, we cannot assume
that we actually have anything useable in termcap_term_buffer so just
use the terminfo fixed size defined ealier.

--- src/term.c	2010-01-06 10:11:04.000000000 +0000
+++ src/term.c	2010-01-06 10:11:53.000000000 +0000
@@ -3590,11 +3590,6 @@
 #endif
     }
 
-#ifndef TERMINFO
-  if (strlen (tty->termcap_term_buffer) >= buffer_size)
-    abort ();
-  buffer_size = strlen (tty->termcap_term_buffer);
-#endif
   tty->termcap_strings_buffer = area = (char *) xmalloc (buffer_size);
   tty->TS_ins_line = tgetstr ("al", address);
   tty->TS_ins_multi_lines = tgetstr ("AL", address);
