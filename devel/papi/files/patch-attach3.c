--- ctests/attach3.c.orig	2013-11-10 23:03:20.000000000 +0400
+++ ctests/attach3.c	2013-11-10 23:06:44.000000000 +0400
@@ -25,6 +25,7 @@
 #if defined(__FreeBSD__)
 # define PTRACE_ATTACH PT_ATTACH
 # define PTRACE_CONT PT_CONTINUE
+# define PTRACE_TRACEME PT_TRACE_ME
 #endif
 
 int
@@ -149,7 +150,7 @@
 		test_fail_exit( __FILE__, __LINE__, "PAPI_start", retval );
 
 	printf("Continuing\n");
-	if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+	if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 	  perror( "ptrace(PTRACE_CONT)" );
 	  return 1;
 	}
