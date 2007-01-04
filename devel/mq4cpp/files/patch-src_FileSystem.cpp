--- src/FileSystem.cpp.orig	Wed Jan  3 21:57:08 2007
+++ src/FileSystem.cpp	Thu Jan  4 16:43:02 2007
@@ -28,7 +28,9 @@
 #ifndef WIN32
 #include <stdlib.h>
 #include <stdio.h>
-#include <sys/sendfile.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/uio.h>
 #include <fcntl.h>
 #include <regex.h>
 #include <errno.h>
@@ -258,7 +260,11 @@
 	int out_fd = ::open(theDestFullName, O_WRONLY|O_CREAT|O_TRUNC, statbuf.st_mode);
 	if(out_fd<0)
 		throw FileSystemException();
+#ifdef __FreeBSD__
+	sendfile(in_fd, out_fd, 0, statbuf.st_size, NULL, NULL, 0);
+#else
 	sendfile(out_fd, in_fd, 0, statbuf.st_size);
+#endif
 	::close(out_fd);
 	::close(in_fd);
 #endif	
@@ -321,7 +327,11 @@
 	Directory* ret=new Directory(path);
 	ret->search();
 #else
+#ifdef __FreeBSD__
+	char* ptr = getcwd (NULL, PATH_MAX);
+#else
 	char* ptr=get_current_dir_name();
+#endif
 	TRACE("Current directory=" << ptr)
 	Directory* ret=new Directory(ptr);
 	ret->search();
