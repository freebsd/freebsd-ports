--- sysutil.c~	Tue Nov 11 02:37:16 2003
+++ sysutil.c	Fri Nov 21 13:47:12 2003
@@ -1403,7 +1403,7 @@
    * more recent dates appear later in the alphabet! Most notably, we must
    * make sure we pad to the same length with 0's 
    */
-  snprintf(intbuf, sizeof(intbuf), "%030ld", p_stat->st_mtime);
+  snprintf(intbuf, sizeof(intbuf), "%030ld", (long)p_stat->st_mtime);
   return intbuf;
 }
 
