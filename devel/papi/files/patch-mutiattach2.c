--- ctests/multiattach2.c.orig	2024-08-30 16:22:20.000000000 -0400
+++ ctests/multiattach2.c	2025-02-04 05:47:08.643897000 -0500
@@ -98,7 +98,7 @@
 	EventSet2 = add_two_events( &num_events2, &PAPI_event2, &mask2 );
 
 	if ( cmpinfo->attach_must_ptrace ) {
-	   if ( ptrace( PTRACE_ATTACH, pid, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_ATTACH, pid, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_ATTACH)" );
 	      return 1;
 	   }
@@ -132,7 +132,7 @@
 
 	/* Wait for the SIGSTOP. */
 	if ( cmpinfo->attach_must_ptrace ) {
-	   if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_CONT)" );
 	      return 1;
 	   }
@@ -162,7 +162,7 @@
 
 	/* Wait for the SIGSTOP. */
 	if ( cmpinfo->attach_must_ptrace ) {
-	   if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_ATTACH)" );
 	      return 1;
 	   }
@@ -201,7 +201,7 @@
 	remove_test_events( &EventSet2, mask2 );
 
 	if ( cmpinfo->attach_must_ptrace ) {
-	   if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_CONT)" );
 	      return 1;
 	   }
