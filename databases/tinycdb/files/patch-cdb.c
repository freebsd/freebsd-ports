--- cdb.c.orig	Tue May 17 17:42:12 2005
+++ cdb.c	Tue May 17 17:42:28 2005
@@ -143,7 +143,7 @@
       if (printf(mode == 'd' ? "+%u,%u:" : "+%u:", klen, vlen) < 0) return -1;
     if (fcpy(f, stdout, klen, &pos, eod) != 0) return -1;
     if (mode == 'd')
-      if (!fputs(flags & F_MAP ? " " : "->", stdout))
+      if (fputs(flags & F_MAP ? " " : "->", stdout) == EOF)
         return -1;
     if (fcpy(f, mode == 'd' ? stdout : NULL, vlen, &pos, eod) != 0)
       return -1;
