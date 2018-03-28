--- execunix.c.orig	2017-12-13 23:56:50 UTC
+++ execunix.c
@@ -445,9 +445,7 @@ void exec_wait()
     while ( !finished )
     {
         int i;
-        struct timeval tv;
-        struct timeval * ptv = NULL;
-        int select_timeout = globs.timeout;
+        int poll_timeout = -1;
 
         /* Check for timeouts:
          *   - kill children that already timed out
@@ -457,6 +455,7 @@ void exec_wait()
         {
             struct tms buf;
             clock_t const current = times( &buf );
+            poll_timeout = globs.timeout;
             for ( i = 0; i < globs.jobs; ++i )
                 if ( cmdtab[ i ].pid )
                 {
@@ -467,28 +466,21 @@ void exec_wait()
                         killpg( cmdtab[ i ].pid, SIGKILL );
                         cmdtab[ i ].exit_reason = EXIT_TIMEOUT;
                     }
-                    else if ( globs.timeout - consumed < select_timeout )
-                        select_timeout = globs.timeout - consumed;
+                    else if ( globs.timeout - consumed < poll_timeout )
+                        poll_timeout = globs.timeout - consumed;
                 }
-
-            /* If nothing else causes our select() call to exit, force it after
-             * however long it takes for the next one of our child processes to
-             * crossed its alloted processing time so we can terminate it.
-             */
-            tv.tv_sec = select_timeout;
-            tv.tv_usec = 0;
-            ptv = &tv;
+            poll_timeout *= 1000;
         }
 
-        /* select() will wait for I/O on a descriptor, a signal, or timeout. */
+        /* poll() will wait for I/O on a descriptor, a signal, or timeout. */
         {
-            /* disable child termination signals while in select */
+            /* disable child termination signals while in poll */
             int ret;
             sigset_t sigmask;
             sigemptyset(&sigmask);
             sigaddset(&sigmask, SIGCHLD);
             sigprocmask(SIG_BLOCK, &sigmask, NULL);
-            while ( ( ret = poll( wait_fds, WAIT_FDS_SIZE, select_timeout * 1000 ) ) == -1 )
+            while ( ( ret = poll( wait_fds, WAIT_FDS_SIZE, poll_timeout ) ) == -1 )
                 if ( errno != EINTR )
                     break;
             /* restore original signal mask by unblocking sigchld */
