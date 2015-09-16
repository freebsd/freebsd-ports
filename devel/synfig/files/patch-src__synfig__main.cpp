--- src/synfig/main.cpp.orig	2015-08-21 15:38:05.415768235 +0800
+++ src/synfig/main.cpp	2015-08-21 15:42:18.215824597 +0800
@@ -198,7 +198,7 @@
 
 	unsigned int i;
 #ifdef _DEBUG
-#ifndef __APPLE__
+#ifndef __clang__
 	std::set_terminate(__gnu_cxx::__verbose_terminate_handler);
 #endif
 #endif
@@ -490,7 +490,11 @@
 
 	/* Read from /proc/self/exe (symlink) */
 	char* path2 = (char*)malloc(buf_size);
+#if defined(__FreeBSD__) || defined (__DragonFly__)
+        strncpy(path2, "/proc/curproc/file", buf_size - 1);
+#else
 	strncpy(path2, "/proc/self/exe", buf_size - 1);
+#endif
 
 	while (1) {
 		int i;
@@ -524,9 +528,10 @@
 		/* path is a symlink. Continue loop and resolve this. */
 		strncpy(path, path2, buf_size - 1);
 	}
-	
+
 	free(path2);
 
+#if ! (defined(__FreeBSD__) || defined(__DragonFly__))
 	if (result == "")
 	{
 		/* readlink() or stat() failed; this can happen when the program is
@@ -568,6 +573,7 @@
 		free(line);
 		fclose(f);
 	}
+#endif
 	
 	free(path);
 
