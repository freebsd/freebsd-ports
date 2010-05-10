--- sysdeps/freebsd/procwd.c.orig	2009-04-19 19:51:00.000000000 +0200
+++ sysdeps/freebsd/procwd.c	2010-05-07 13:17:54.000000000 +0200
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
@@ -97,24 +100,39 @@ parse_output(const char *output, glibtop
 char**
 glibtop_get_proc_wd_s(glibtop *server, glibtop_proc_wd *buf, pid_t pid)
 {
-	char path[MAXPATHLEN];
+	int exe_mib[4];
+	size_t len;
 #if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
 	struct kinfo_file *freep, *kif;
 	GPtrArray *dirs;
-	size_t len;
-	int i;
+#ifndef HAVE_KINFO_GETFILE
 	int name[4];
 #else
+	int cnt;
+#endif
+	int i;
+#else
 	char *output;
 #endif
 
 	memset (buf, 0, sizeof (glibtop_proc_wd));
+	len = 0;
 
-	g_snprintf(path, sizeof(path), "/proc/%u/file", pid);
-	if (safe_readlink(path, buf->exe, sizeof(buf->exe)))
-		buf->flags |= (1 << GLIBTOP_PROC_WD_EXE);
+	exe_mib[0] = CTL_KERN;
+	exe_mib[1] = KERN_PROC;
+	exe_mib[2] = KERN_PROC_PATHNAME;
+	exe_mib[3] = pid;
+
+	if (sysctl(exe_mib, 4, NULL, &len, NULL, 0) == 0) {
+		if (len > sizeof(buf->exe))
+			len = sizeof(buf->exe);
+		if (sysctl(exe_mib, 4, buf->exe, &len, NULL, 0) == 0)
+			buf->flags |= (1 << GLIBTOP_PROC_WD_EXE);
+	}
 
 #if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+#ifndef HAVE_KINFO_GETFILE
+	len = 0;
 	name[0] = CTL_KERN;
 	name[1] = KERN_PROC;
 	name[2] = KERN_PROC_FILEDESC;
@@ -127,10 +145,21 @@ glibtop_get_proc_wd_s(glibtop *server, g
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
