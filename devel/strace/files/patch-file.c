--- file.c.orig	2008-08-01 09:13:10.000000000 +0800
+++ file.c	2008-11-21 00:16:35.000000000 +0800
@@ -1656,7 +1656,7 @@
 		statbuf.f_bsize, statbuf.f_blocks, statbuf.f_bfree);
 	tprintf("f_bavail=%u, f_files=%u, f_ffree=%u, f_fsid={%d, %d}, f_namelen=%u",
 		statbuf.f_bavail,statbuf.f_files, statbuf.f_ffree,
-		statbuf.f_fsid.__val[0], statbuf.f_fsid.__val[1],
+		statbuf.f_fsid.val[0], statbuf.f_fsid.val[1],
 		statbuf.f_namelen);
 #else /* !ALPHA */
 	tprintf("{f_type=%s, f_bsize=%lu, f_blocks=%lu, f_bfree=%lu, ",
@@ -1668,7 +1668,7 @@
 		(unsigned long)statbuf.f_bavail,
 		(unsigned long)statbuf.f_files,
 		(unsigned long)statbuf.f_ffree,
-		statbuf.f_fsid.__val[0], statbuf.f_fsid.__val[1]);
+		statbuf.f_fsid.val[0], statbuf.f_fsid.val[1]);
 #ifdef LINUX
 	tprintf(", f_namelen=%lu", (unsigned long)statbuf.f_namelen);
 #endif /* LINUX */
@@ -2856,6 +2856,7 @@
 }
 
 
+#ifdef LINUX
 static const struct xlat advise[] = {
   { POSIX_FADV_NORMAL,		"POSIX_FADV_NORMAL"	},
   { POSIX_FADV_RANDOM,		"POSIX_FADV_RANDOM"	},
@@ -2865,6 +2866,7 @@
   { POSIX_FADV_NOREUSE,		"POSIX_FADV_NOREUSE"	},
   { 0,				NULL			}
 };
+#endif
 
 
 #ifdef LINUX
@@ -2888,6 +2890,7 @@
 #endif
 
 
+#ifdef LINUX
 int
 sys_fadvise64_64(tcp)
 struct tcb *tcp;
@@ -2909,6 +2912,7 @@
     }
     return 0;
 }
+#endif
 
 #ifdef LINUX
 static const struct xlat inotify_modes[] = {
