--- sysdeps/freebsd/procwd.c.orig	2008-12-06 20:43:44.256309000 -0500
+++ sysdeps/freebsd/procwd.c	2008-12-06 20:44:32.000000000 -0500
@@ -24,7 +24,12 @@
 #include <glibtop_private.h>
 
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #include <sys/param.h>
+#include <sys/user.h>
+#ifdef HAVE_KINFO_GETFILE
+#include <libutil.h>
+#endif
 #include <string.h>
 
 static const unsigned long _glibtop_sysdeps_proc_wd =
@@ -38,6 +43,7 @@ _glibtop_init_proc_wd_s(glibtop *server)
 	server->sysdeps.proc_wd = _glibtop_sysdeps_proc_wd;
 }
 
+#if (__FreeBSD_version >= 800000 && __FreeBSD_version < 800019) || _FreeBSD_version < 700104
 static GPtrArray *
 parse_output(const char *output, glibtop_proc_wd *buf)
 {
@@ -89,12 +95,25 @@ parse_output(const char *output, glibtop
 
 	return dirs;
 }
+#endif
 
 char**
 glibtop_get_proc_wd_s(glibtop *server, glibtop_proc_wd *buf, pid_t pid)
 {
 	char path[MAXPATHLEN];
+#if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+	struct kinfo_file *freep, *kif;
+	GPtrArray *dirs;
+#ifndef HAVE_KINFO_GETFILE
+	size_t len;
+	int name[4];
+#else
+	int cnt;
+#endif
+	int i;
+#else
 	char *output;
+#endif
 
 	memset (buf, 0, sizeof (glibtop_proc_wd));
 
@@ -102,6 +121,54 @@ glibtop_get_proc_wd_s(glibtop *server, g
 	if (safe_readlink(path, buf->exe, sizeof(buf->exe)))
 		buf->flags |= (1 << GLIBTOP_PROC_WD_EXE);
 
+#if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+#ifndef HAVE_KINFO_GETFILE
+	name[0] = CTL_KERN;
+	name[1] = KERN_PROC;
+	name[2] = KERN_PROC_FILEDESC;
+	name[3] = pid;
+
+	if (sysctl(name, 4, NULL, &len, NULL, 0) < 0)
+		return NULL;
+	freep = kif = g_malloc(len);
+	if (sysctl(name, 4, kif, &len, NULL, 0) < 0) {
+		g_free(freep);
+		return NULL;
+	}
+#else
+	freep = kinfo_getfile(pid, &cnt);
+#endif
+
+	dirs = g_ptr_array_sized_new(1);
+
+#ifndef HAVE_KINFO_GETFILE
+	for (i = 0; i < len / sizeof(*kif); i++, kif++) {
+		if (kif->kf_structsize != sizeof(*kif))
+			continue;
+#else
+	for (i = 0; i < cnt; i++) {
+		kif = &freep[i];
+#endif
+		switch (kif->kf_fd) {
+			case KF_FD_TYPE_ROOT:
+				g_strlcpy(buf->root, kif->kf_path,
+					   sizeof(buf->root));
+				buf->flags |= (1 << GLIBTOP_PROC_WD_ROOT);
+				break;
+			case KF_FD_TYPE_CWD:
+				g_ptr_array_add(dirs, g_strdup (kif->kf_path));
+				break;
+		}
+	}
+	g_free(freep);
+
+	buf->number = dirs->len;
+	buf->flags |= (1 << GLIBTOP_PROC_WD_NUMBER);
+
+	g_ptr_array_add(dirs, NULL);
+
+	return (char **)g_ptr_array_free(dirs, FALSE);
+#else
 	output = execute_lsof(pid);
 	if (output != NULL) {
 		GPtrArray *dirs;
@@ -116,6 +183,7 @@ glibtop_get_proc_wd_s(glibtop *server, g
 
 		return (char **)g_ptr_array_free(dirs, FALSE);
 	}
+#endif
 
 	return NULL;
 }
