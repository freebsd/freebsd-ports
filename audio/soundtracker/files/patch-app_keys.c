- bugfix, patch reported to the author via e-mail.

--- app/keys.c.orig	2021-02-01 20:01:20 UTC
+++ app/keys.c
@@ -893,7 +893,7 @@ keys_make_xkeys(void)
             keyname[k++] = xkeymap[i].xname;
     }
 
-    qsort(keyname, k, sizeof(char*), keys_qsort_compare_func);
+    qsort(keyname+1, k-1, sizeof(char*), keys_qsort_compare_func);
 
     keyname[0] = NONE_TEXT;
 }
