--- generate.c.orig	2025-10-20 22:42:33 UTC
+++ generate.c
@@ -422,7 +422,7 @@ expand(const char *src, STACK *pre_param)
                 {
                     char           workbuf[48];
 
-                    sprintf(workbuf, "%zu", (unsigned long) strlen(ptr));
+                    sprintf(workbuf, "%zu", strlen(ptr));
                     dst = MEM_extend(dst, workbuf);
                     break;
                 }
@@ -758,7 +758,7 @@ get_input(void)
 
         if (!*xbuf) continue;
         p = (*xbuf == '!') ? xbuf + 1 : xbuf;
-        sprintf(cur_line_str, "%zu", (unsigned long) infile->xline);
+        sprintf(cur_line_str, "%zu", infile->xline);
 
         if (*p != '@')
         {
