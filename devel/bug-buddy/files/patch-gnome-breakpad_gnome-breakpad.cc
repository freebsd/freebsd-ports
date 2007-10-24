--- gnome-breakpad/gnome-breakpad.cc.orig	2007-08-16 13:55:38.000000000 -0400
+++ gnome-breakpad/gnome-breakpad.cc	2007-09-02 19:21:10.000000000 -0400
@@ -6,8 +6,14 @@
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
@@ -114,6 +120,7 @@ find_in_debug_path (const char *filename
 }
 	
 
+#if !defined(__FreeBSD__) || __FreeBSD_version > 700024
 static gboolean
 elf_has_debug_symbols (const char *filename)
 {
@@ -166,7 +173,7 @@ elf_has_debug_symbols (const char *filen
        elf_end (elf);
        return false;
 }
-
+#endif
 
 
 
@@ -269,9 +276,17 @@ check_if_gdb (void *callback_context)
 		_exit(0);
 	}
 	
+#if !defined(__FreeBSD__) || __FreeBSD_version > 700024
 	memset(mypath, 0, sizeof(mypath));
+#ifndef __FreeBSD__
 	readlink ("/proc/self/exe", mypath, sizeof(mypath));
+#else
+	readlink ("/proc/curproc/file", mypath, sizeof(mypath));
+#endif
 	has_debug_symbols = elf_has_debug_symbols (mypath);
+#else
+	has_debug_symbols = TRUE;
+#endif
 
 
 	if (bugbuddy && gdb && has_debug_symbols) {
