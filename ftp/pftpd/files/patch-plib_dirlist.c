--- plib/dirlist.c.orig	2013-07-04 11:10:49 UTC
+++ plib/dirlist.c
@@ -66,7 +66,11 @@ dirent_dup(const struct dirent *dep)
     n_dep = a_malloc(len, "struct dirent");
     memcpy(n_dep, dep, len);
 #else
+# ifdef __DragonFly__
+    n_dep = a_malloc(len = _DIRENT_RECLEN(dep->d_namlen), "struct dirent");
+# else
     n_dep = a_malloc(len = dep->d_reclen, "struct dirent");
+# endif
 #endif
     memcpy(n_dep, dep, len);
     
@@ -91,8 +95,12 @@ dirent_alloc(ino_t ino, const char *name
 	    
     dp = a_malloc(sizeof(*dp)+len, "struct dirent");
     dp->d_ino = ino;
+#ifdef		linux
     dp->d_off = 0;
+#endif		/* linux */
+#ifndef		__DragonFly__
     dp->d_reclen = len;
+#endif
     strcpy(dp->d_name, name);
 
     return dp;
