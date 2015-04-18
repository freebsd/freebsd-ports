--- config.c.orig	2011-08-26 16:48:21 UTC
+++ config.c
@@ -213,14 +213,14 @@ init_hard:
                     quit(1);
                 }
                 errno = 0;
-                addr = (int)strtol(av[3], '\0', 0);
+                addr = (int)strtol(av[3], NULL, 0);
                 /* XXX DEBUG ISA-specific */
                 if ((errno != 0) || (addr > MAXPORT)) {
                     fprintf(stderr, "usage: assign com[1-4] path addr irq\n");
                     quit(1);
                 }
                 errno = 0;
-                irq = (unsigned char)strtol(av[4], '\0', 0);
+                irq = (unsigned char)strtol(av[4], NULL, 0);
                 /* XXX DEBUG ISA-specific */
                 if ((errno != 0) || (irq < 2) || (irq > 7)) {
                     fprintf(stderr, "usage: assign com[1-4] path addr irq[2-7]\n");
