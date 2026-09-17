--- ctests/multiattach.c.orig	2024-08-30 16:22:20.000000000 -0400
+++ ctests/multiattach.c	2025-02-04 05:33:20.641592000 -0500
@@ -106,7 +106,7 @@
 	EventSet2 = add_two_events( &num_events2, &PAPI_event2, &mask2 );
 
 	if ( cmpinfo->attach_must_ptrace ) {
-	   if ( ptrace( PTRACE_ATTACH, pid, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_ATTACH, pid, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_ATTACH)" );
 	      return 1 ;
 	   }
@@ -119,7 +119,7 @@
 			"Child process didnt return true to WIFSTOPPED", 0 );
 	   }
 
-	   if ( ptrace( PTRACE_ATTACH, pid2, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_ATTACH, pid2, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_ATTACH)" );
 	      return 1;
 	   }
@@ -158,7 +158,7 @@
 
 	/* Wait for the SIGSTOP. */
 	if ( cmpinfo->attach_must_ptrace ) {
-	   if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_CONT)" );
 	      return 1;
 	   }
@@ -175,7 +175,7 @@
 			"Child process didn't stop on SIGSTOP", 0 );
 	   }
 
-	   if ( ptrace( PTRACE_CONT, pid2, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid2, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_CONT)" );
 	      return 1;
 	   }
@@ -207,7 +207,7 @@
 
 		/* Start first child and Wait for the SIGSTOP. */
 	if ( cmpinfo->attach_must_ptrace ) {
-	   if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_ATTACH)" );
 	      return 1;
 	   }
@@ -225,7 +225,7 @@
 	   }
 
 		/* Start second child and Wait for the SIGSTOP. */
-	   if ( ptrace( PTRACE_CONT, pid2, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid2, NULL, 0 ) == -1 ) {
 	       perror( "ptrace(PTRACE_ATTACH)" );
 	       return 1;
 	   }
@@ -268,11 +268,11 @@
 
 	/* restart events so they can end */
 	if ( cmpinfo->attach_must_ptrace ) {
-	   if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_CONT)" );
 	      return 1;
 	   }
-	   if ( ptrace( PTRACE_CONT, pid2, NULL, NULL ) == -1 ) {
+	   if ( ptrace( PTRACE_CONT, pid2, NULL, 0 ) == -1 ) {
 	      perror( "ptrace(PTRACE_CONT)" );
 	      return 1;
 	   }
