--- cdb.c.orig	Mon Dec 10 06:18:02 2001
+++ cdb.c	Mon Mar  3 08:38:57 2003
@@ -144,7 +144,7 @@
       if (printf(mode == 'd' ? "+%u,%u:" : "+%u:", klen, vlen) < 0) return -1;
     if (fcpy(f, stdout, klen, &pos, eod) != 0) return -1;
     if (mode == 'd')
-      if (!fputs(flags & F_MAP ? " " : "->", stdout))
+      if (fputs(flags & F_MAP ? " " : "->", stdout) == EOF)
 	return -1;
     if (fcpy(f, mode == 'd' ? stdout : NULL, vlen, &pos, eod) != 0)
       return -1;
