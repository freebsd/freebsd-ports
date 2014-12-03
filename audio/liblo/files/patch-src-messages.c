--- src/message.c.orig	2014-01-20 12:49:42.000000000 +0100
+++ src/message.c	2014-12-03 23:02:28.000000000 +0100
@@ -996,8 +996,8 @@ void lo_message_pp(lo_message m)
     putchar('\n');
     if (d != end) {
         fprintf(stderr,
-                "liblo warning: type and data do not match (off by %d) in message %p\n",
-                abs((char *) d - (char *) end), m);
+                "liblo warning: type and data do not match (off by %td) in message %p\n",
+                d >= end ? (char *) d - (char *) end : (char *) end - (char *) d, m);
     }
 }
 
