
$FreeBSD$

--- pkg.c	2001/04/29 11:38:41	1.1
+++ pkg.c	2001/04/29 11:39:06
@@ -97,6 +97,8 @@
       
       g_slist_foreach (search_dirs, (GFunc)scan_dir, NULL);
       scan_dir (PKGLIBDIR);
+      scan_dir (XPKGLIBDIR);
+      scan_dir (LPKGLIBDIR);
     }
 }
 
