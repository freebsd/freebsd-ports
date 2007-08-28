$FreeBSD$

--- ../../j2se/src/solaris/native/java/lang/UNIXProcess_md.c	13 Aug 2007 21:37:38 -0000	1.4
+++ ../../j2se/src/solaris/native/java/lang/UNIXProcess_md.c	28 Aug 2007 06:36:09 -0000
@@ -264,7 +264,7 @@
 static int
 closeDescriptors(void)
 {
-	return _thread_sys_closefrom(3);
+	return _thread_sys_closefrom(FAIL_FILENO + 1);
 }
 
 #elif defined(_ALLBSD_SOURCE)
@@ -282,7 +282,7 @@
     /*
      * BSDNOTE: There's no known way to find list of all open file descriptors
      * associated with process in FreeBSD.  Therefore we have to pass from
-     * fd == 3 to maximum fd per process number.  It's possible to retrive
+     * fd == FAIL_FILENO + 1 to maximum fd per process number.  It's possible to retrive
      * max number of fd's with three ways: sysctl(kern.maxfilesperproc),
      * getrlimit(RLIMIT_NOFILE) and getdtablesize().  In current implementation
      * getdtablesize() returns MIN() of first two ways.
@@ -297,7 +297,7 @@
     max_fd = getdtablesize();
     ebadf = 0;
 
-    for (i = 3; i < max_fd; i++) {
+    for (i = FAIL_FILENO + 1; i < max_fd; i++) {
 	if (close(i) < 0) { ebadf++; } else { ebadf = 0; }
 	/*
          * GUESS_FINISHED subsequent calls to close() returned EBADF, assume
