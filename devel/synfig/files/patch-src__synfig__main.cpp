--- src/synfig/main.cpp.orig
+++ src/synfig/main.cpp
@@ -193,8 +193,10 @@
 
 	unsigned int i;
 #ifdef _DEBUG
+#ifndef __clang__
 	std::set_terminate(__gnu_cxx::__verbose_terminate_handler);
 #endif
+#endif
 
 #if defined(HAVE_SIGNAL_H) && defined(SIGPIPE)
 	signal(SIGPIPE, broken_pipe_signal);
@@ -464,7 +466,11 @@
 
 	/* Read from /proc/self/exe (symlink) */
 	char* path2 = (char*)malloc(buf_size);
+#if defined(__FreeBSD__)
+	strncpy(path2, "/proc/curproc/file", buf_size - 1);
+#else
 	strncpy(path2, "/proc/self/exe", buf_size - 1);
+#endif
 
 	while (1) {
 		int i;
@@ -501,6 +507,7 @@
 	
 	free(path2);
 
+#if !defined(__FreeBSD__)
 	if (result == "")
 	{
 		/* readlink() or stat() failed; this can happen when the program is
@@ -542,6 +549,7 @@
 		free(line);
 		fclose(f);
 	}
+#endif
 	
 	free(path);
 
