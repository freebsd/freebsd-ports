--- src/elf.c.orig	2010-11-16 18:43:40.000000000 +0100
+++ src/elf.c	2010-11-16 18:59:11.000000000 +0100
@@ -16,8 +16,15 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
+#if !defined(__FreeBSD__) || __FreeBSD_version > 700024
 #include <libelf.h>
 #include <gelf.h>
+#endif
+
 #include <stdio.h>
 #include <fcntl.h>
 #include <string.h>
@@ -61,7 +68,9 @@
 gboolean
 elf_has_debug_symbols (gint pid)
 {
+#if !defined(__FreeBSD__)
 	gchar *proc_path;
+#endif
 	gchar *filename;
 	int fd;
 	Elf *elf;
@@ -76,9 +85,13 @@
 		return FALSE;
 	}
 
+#if defined(__FreeBSD__)
+	filename = g_file_read_link ("/proc/curproc/file", NULL);
+#else
 	proc_path = g_strdup_printf ("/proc/%d/exe", pid);
 	filename = g_file_read_link (proc_path, NULL);
 	g_free (proc_path);
+#endif
 	if (!filename)
 		return FALSE;
 
