--- source/log.c.orig	Wed Nov 14 04:49:45 2001
+++ source/log.c	Fri Apr 25 04:02:23 2003
@@ -214,9 +214,8 @@
   va_end(args);
 
   /* log the command */
-  stripformatsymbols( buffer );
-  putlog(LOG2, buffer);
+  putlog(LOG2, "%s", buffer);
 
   /* send it to opers with usermode +s */
-  SendUmode(OPERUMODE_S, buffer);
+  SendUmode(OPERUMODE_S, "%s", buffer);
 } /* RecordCommand() */
