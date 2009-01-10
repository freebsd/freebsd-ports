--- sysdeps/freebsd/procopenfiles.c.orig	2008-08-18 11:23:36.000000000 -0400
+++ sysdeps/freebsd/procopenfiles.c	2008-12-07 00:17:26.000000000 -0500
@@ -35,6 +35,9 @@
 #include <sys/user.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#ifdef HAVE_KINFO_PROC
+#include <libutil.h>
+#endif
 #include <string.h>
 #include <stdlib.h>
 
@@ -263,8 +266,12 @@ glibtop_get_proc_open_files_s (glibtop *
 {
 #if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
 	struct kinfo_file *freep, *kif;
+#ifndef HAVE_KINFO_GETFILE
 	int name[4];
 	size_t len;
+#else
+	int cnt;
+#endif
 	size_t i;
 #else
 	char *output;
@@ -274,6 +281,7 @@ glibtop_get_proc_open_files_s (glibtop *
 	memset(buf, 0, sizeof (glibtop_proc_open_files));
 
 #if __FreeBSD_version > 800018 || (__FreeBSD_version < 800000 && __FreeBSD_version >= 700104)
+#ifndef HAVE_KINFO_GETFILE
 	name[0] = CTL_KERN;
 	name[1] = KERN_PROC;
 	name[2] = KERN_PROC_FILEDESC;
@@ -287,12 +295,25 @@ glibtop_get_proc_open_files_s (glibtop *
 		g_free(freep);
 		return NULL;
 	}
+#else
+	freep = kinfo_getfile(pid, &cnt);
+#endif
 
 	entries = g_array_new(FALSE, FALSE, sizeof(glibtop_open_files_entry));
 
+#ifndef HAVE_KINFO_GETFILE
 	for (i = 0; i < len / sizeof(*kif); i++, kif++) {
 		glibtop_open_files_entry entry = {0};
 
+		if (kif->kf_structsize != sizeof(*kif))
+			continue;
+#else
+	for (i = 0; i < cnt; i++) {
+		glibtop_open_files_entry entry = {0};
+
+		kif = &freep[i];
+#endif
+
 		if (kif->kf_fd < 0)
 			continue;
 
