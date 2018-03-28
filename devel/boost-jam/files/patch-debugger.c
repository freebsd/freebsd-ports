--- debugger.c.orig	2017-12-13 23:56:50 UTC
+++ debugger.c
@@ -1102,7 +1102,7 @@ static void debug_start_child( int argc, const char * 
     PROCESS_INFORMATION pi = { NULL, NULL, 0, 0 };
     STARTUPINFO si = { sizeof( STARTUPINFO ), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0 };
-    assert( DEBUG_STATE == DEBUG_NO_CHILD );
+    assert( debug_state == DEBUG_NO_CHILD );
     if ( ! CreatePipe( &pipe1[ 0 ], &pipe1[ 1 ], &sa, 0 ) )
     {
         printf("internal error\n");
@@ -1189,7 +1189,7 @@ static void debug_start_child( int argc, const char * 
     int read_fd;
     int pid;
     int i;
-    assert( DEBUG_STATE == DEBUG_NO_CHILD );
+    assert( debug_state == DEBUG_NO_CHILD );
     pipe(pipe1);
     pipe(pipe2);
     pid = fork();
