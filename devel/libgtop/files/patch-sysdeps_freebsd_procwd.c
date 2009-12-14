--- sysdeps/freebsd/procwd.c.orig	2009-12-13 18:53:02.827740000 -0500
+++ sysdeps/freebsd/procwd.c	2009-12-13 18:59:27.000000000 -0500
@@ -27,6 +27,9 @@
 #include <sys/sysctl.h>
 #include <sys/param.h>
 #include <sys/user.h>
+#ifdef HAVE_KINFO_GETFILE
+#include <libutil.h>
+#endif
 #include <string.h>
 
 static const unsigned long _glibtop_sysdeps_proc_wd =
@@ -40,7 +43,7 @@ _glibtop_init_proc_wd_s(glibtop *server)
 	server->sysdeps.proc_wd = _glibtop_sysdeps_proc_wd;
 }
 
-#if (__FreeBSD_version >= 800000 && __FreeBSD_version < 800019) || _FreeBSD_version < 700104
+#if (__FreeBSD_version >= 800000 && __FreeBSD_version < 800019) || __FreeBSD_version < 700104
 static GPtrArray *
 parse_output(const char *output, glibtop_proc_wd *buf)
 {
@@ -101,10 +104,14 @@ glibtop_get_proc_wd_s(glibtop *server, g
 #if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
 	struct kinfo_file *freep, *kif;
 	GPtrArray *dirs;
+#ifndef HAVE_KINFO_GETFILE
 	size_t len;
-	int i;
 	int name[4];
 #else
+	int cnt;
+#endif
+	int i;
+#else
 	char *output;
 #endif
 
@@ -115,6 +122,7 @@ glibtop_get_proc_wd_s(glibtop *server, g
 		buf->flags |= (1 << GLIBTOP_PROC_WD_EXE);
 
 #if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+#ifndef HAVE_KINFO_GETFILE
 	name[0] = CTL_KERN;
 	name[1] = KERN_PROC;
 	name[2] = KERN_PROC_FILEDESC;
@@ -127,10 +135,21 @@ glibtop_get_proc_wd_s(glibtop *server, g
 		g_free(freep);
 		return NULL;
 	}
+#else
+	freep = kinfo_getfile(pid, &cnt);
+#endif
 
 	dirs = g_ptr_array_sized_new(1);
 
+#ifndef HAVE_KINFO_GETFILE
 	for (i = 0; i < len / sizeof(*kif); i++, kif++) {
+		if (kif->kf_structsize != sizeof(*kif))
+			continue;
+#else
+	for (i = 0; i < cnt; i++) {
+		kif = &freep[i];
+#endif
+
 		switch (kif->kf_fd) {
 			case KF_FD_TYPE_ROOT:
 				g_strlcpy(buf->root, kif->kf_path,
