--- server/ptrace.c.orig	2025-07-11 20:05:52 UTC
+++ server/ptrace.c
@@ -687,7 +687,7 @@ void init_thread_context( struct thread *thread )
         struct dbreg dbregs;
 
         memset( &dbregs, 0, sizeof(dbregs) );
-        ptrace( PTRACE_SETDBREGS, get_ptrace_tid( thread ), (caddr_t)&dbregs, 0 );
+        ptrace( PTRACE_SETDBREGS, thread->unix_tid , (caddr_t)&dbregs, 0 );
         resume_after_ptrace( thread );
     }
     thread->system_regs = 0;
