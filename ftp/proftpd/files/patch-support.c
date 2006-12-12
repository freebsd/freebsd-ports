--- src/support.c	2005/09/28 02:06:26	1.78
+++ src/support.c	2006/11/27 14:49:47	1.80
@@ -27,7 +27,7 @@
 /* Various basic support routines for ProFTPD, used by all modules
  * and not specific to one or another.
  *
- * $Id: support.c,v 1.78 2005/09/28 02:06:26 castaglia Exp $
+ * $Id: support.c,v 1.80 2006/11/27 14:49:47 jwm Exp $
  */
 
 #include "conf.h"
@@ -632,7 +632,8 @@
   char **mptr,**rptr;
   char *marr[33],*rarr[33];
   char buf[PR_TUNABLE_PATH_MAX] = {'\0'}, *pbuf = NULL;
-  size_t mlen = 0, rlen = 0, blen;
+  size_t mlen = 0, rlen = 0;
+  int blen;
   int dyn = TRUE;
 
   cp = buf;
@@ -646,7 +647,7 @@
 
   while ((m = va_arg(args, char *)) != NULL && mlen < sizeof(marr)-1) {
     char *tmp = NULL;
-    size_t count = 0;
+    int count = 0;
 
     if ((r = va_arg(args, char *)) == NULL)
       break;
@@ -659,6 +660,12 @@
     while (tmp) {
       pr_signals_handle();
       count++;
+      if (count < 0) {
+        /* Integer overflow. In order to overflow integer range with a count
+         * of escapes, somebody must be doing something very strange.
+         */
+        return s;
+      }
 
       /* Be sure to increment the pointer returned by strstr(3), to
        * advance past the beginning of the substring for which we are
@@ -674,6 +681,12 @@
      */
     if (count) {
       blen += count * (strlen(r) - strlen(m));
+      if (blen < 0) {
+        /* Integer overflow. In order to overflow this, somebody must be
+         * doing something very strange.
+         */
+        return s;
+      }
       marr[mlen] = m;
       rarr[mlen++] = r;
     }
@@ -722,10 +735,11 @@
     }
 
     if (!*mptr) {
-      if ((cp - pbuf + 1) > blen) {
+      if ((cp - pbuf + 1) >= blen) {
 	pr_log_pri(PR_LOG_ERR,
 		"WARNING: attempt to overflow internal ProFTPD buffers");
 	cp = pbuf + blen - 1;
+	goto done;
       }
       *cp++ = *src++;
     }
@@ -768,6 +782,9 @@
 char *sstrcat(char *dest, const char *src, size_t n) {
   register char *d;
 
+  if (n == 0)
+    return NULL;
+
   for (d = dest; *d && n > 1; d++, n--) ;
 
   while (n-- > 1 && *src)
