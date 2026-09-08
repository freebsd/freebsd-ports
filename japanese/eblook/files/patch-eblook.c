--- eblook.c.orig	2026-09-07 23:53:53 UTC
+++ eblook.c
@@ -765,7 +765,7 @@ parse_command_line (command_line, argv)
 	argv[num++] = p;
 	reserved = 1;
       }
-      strcpy (p, p + 1);
+      memmove (p, p + 1, strlen (p));
       p--;
       in_quote = !in_quote;
       break;
@@ -779,7 +779,7 @@ parse_command_line (command_line, argv)
       break;
 
     case '\\':
-      strcpy (p, p + 1);
+      memmove (p, p + 1, strlen (p));
     default:
       if (!reserved) {
 	argv[num++] = p;
