--- ctests/zero_attach.c.orig	2024-08-30 16:22:20.000000000 -0400
+++ ctests/zero_attach.c	2025-02-04 05:34:33.463688000 -0500
@@ -89,7 +89,7 @@
 	EventSet1 = add_two_events( &num_events1, &PAPI_event, &mask1 );
 
 	if ( cmpinfo->attach_must_ptrace ) {
-		if ( ptrace( PTRACE_ATTACH, pid, NULL, NULL ) == -1 ) {
+		if ( ptrace( PTRACE_ATTACH, pid, NULL, 0 ) == -1 ) {
 			perror( "ptrace(PTRACE_ATTACH)" );
 			return 1;
 		}
@@ -122,7 +122,7 @@
 
 	/* Wait for the SIGSTOP. */
 	if ( cmpinfo->attach_must_ptrace ) {
-		if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+		if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 			perror( "ptrace(PTRACE_CONT)" );
 			return 1;
 		}
@@ -147,7 +147,7 @@
 
 	/* Wait for the SIGSTOP. */
 	if ( cmpinfo->attach_must_ptrace ) {
-		if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+		if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 			perror( "ptrace(PTRACE_CONT)" );
 			return 1;
 		}
@@ -178,7 +178,7 @@
 	remove_test_events( &EventSet1, mask1 );
 
 	if ( cmpinfo->attach_must_ptrace ) {
-		if ( ptrace( PTRACE_CONT, pid, NULL, NULL ) == -1 ) {
+		if ( ptrace( PTRACE_CONT, pid, NULL, 0 ) == -1 ) {
 			perror( "ptrace(PTRACE_CONT)" );
 			return 1;
 		}
