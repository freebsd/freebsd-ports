--- gnome-breakpad/gnome-breakpad.cc.orig	2009-02-16 15:24:48.000000000 +0100
+++ gnome-breakpad/gnome-breakpad.cc	2009-02-22 16:25:50.000000000 +0100
@@ -25,8 +25,14 @@
 #include <cassert>
 #include <cstring>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
+#if !defined(__FreeBSD__) || __FreeBSD_version > 700024
 #include <libelf.h>
 #include <gelf.h>
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -264,6 +270,7 @@ find_in_debug_path (const char *filename
 }
 
 
+#if !defined(__FreeBSD__) || __FreeBSD_version > 700024
 static gboolean
 elf_has_debug_symbols (const char *filename)
 {
@@ -316,7 +323,7 @@ elf_has_debug_symbols (const char *filen
        elf_end (elf);
        return false;
 }
-
+#endif
 
 
 
@@ -429,11 +436,18 @@ check_if_gdb ()
 			_exit (1);
 		_exit(0);
 	}
-	
+
+#if !defined(__FreeBSD__)
 	mypath = g_file_read_link ("/proc/self/exe", NULL);
+#else
+	mypath = g_file_read_link ("/proc/curproc/file", NULL);
+#endif
 	if (mypath)
+#if !defined(__FreeBSD__) || __FreeBSD_version > 700024
 		has_debug_symbols = elf_has_debug_symbols (mypath);
-
+#else	
+		has_debug_symbols = TRUE;
+#endif
 	g_free (mypath);
 
 	if (bugbuddy && gdb && has_debug_symbols) {
