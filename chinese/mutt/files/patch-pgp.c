--- pgp.c.orig	Sat Aug 12 11:03:44 2000
+++ pgp.c	Sat Aug 12 11:05:23 2000
@@ -1019,7 +1019,7 @@
 	mutt_message_to_7bit(a, NULL);
     }
     else if (a->encoding == ENC8BIT)
-      a->encoding = ENCQUOTEDPRINTABLE;
+      { /* Do nothing */ }
     else if (a->encoding == ENCBINARY)
       a->encoding = ENCBASE64;
     else if (a->content && a->encoding != ENCBASE64 &&
