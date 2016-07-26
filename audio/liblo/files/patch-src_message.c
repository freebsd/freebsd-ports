--- src/message.c.orig	2014-01-20 11:49:42 UTC
+++ src/message.c
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
 
