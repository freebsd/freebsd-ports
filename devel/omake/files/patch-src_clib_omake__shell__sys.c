$NetBSD: patch-ae,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/clib/omake_shell_sys.c.orig	2007-12-01 21:32:13.000000000 +0000
+++ src/clib/omake_shell_sys.c
@@ -551,7 +551,7 @@ value omake_shell_sys_suspend(value v_pg
     fflush(stderr);
 #endif
     if(process_group_map(suspend_process, Int_val(v_pgrp)) < 0)
-        failwith("omake_shell_sys_suspend");
+        caml_failwith("omake_shell_sys_suspend");
     CAMLreturn(Val_unit);
 }
 
@@ -563,7 +563,7 @@ value omake_shell_sys_resume(value v_pgr
     fflush(stderr);
 #endif
     if(process_group_map(resume_process, Int_val(v_pgrp)) < 0)
-        failwith("omake_shell_sys_resume");
+        caml_failwith("omake_shell_sys_resume");
     CAMLreturn(Val_unit);
 }
 
@@ -575,7 +575,7 @@ value omake_shell_sys_kill(value v_pgrp)
     fflush(stderr);
 #endif
     if(process_group_map(kill_process, Int_val(v_pgrp)) < 0)
-        failwith("omake_shell_sys_kill");
+        caml_failwith("omake_shell_sys_kill");
     CAMLreturn(Val_unit);
 }
 
@@ -600,14 +600,14 @@ value omake_shell_sys_create_thread_pid(
     /* Allocate the process data */
     processp = (Process *) malloc(sizeof(Process));
     if(processp == 0)
-        failwith("omake_shell_sys_create_thread_pid: out of memory");
+        caml_failwith("omake_shell_sys_create_thread_pid: out of memory");
     memset(processp, 0, sizeof(Process));
 
     /* Create an event for waiting on the thread */
     event = CreateEvent(NULL, FALSE, FALSE, NULL);
     if(event == NULL) {
         free(processp);
-        failwith("omake_shell_sys_create_thread_pid: can't create event");
+        caml_failwith("omake_shell_sys_create_thread_pid: can't create event");
     }
 
     pgrp = Int_val(v_pgrp);
@@ -645,7 +645,7 @@ value omake_shell_sys_init_thread_pid(va
             break;
     }
     if(processp == 0)
-        raise_not_found();
+        caml_raise_not_found();
 
     /* Process has terminated */
     processp->thread = GetCurrentThreadId();
@@ -679,7 +679,7 @@ value omake_shell_sys_release_thread_pid
             break;
     }
     if(processp == 0)
-        raise_not_found();
+        caml_raise_not_found();
 
     /* Process has terminated */
     processp->changed = 1;
@@ -771,7 +771,7 @@ value omake_shell_sys_wait(value v_pgrp,
             goto done;
         else {
             if(ncount == MAXIMUM_WAIT_OBJECTS)
-                invalid_argument("omake_shell_sys_wait: too many processes");
+                caml_invalid_argument("omake_shell_sys_wait: too many processes");
             processes[ncount] = processp->pid;
             handles[ncount] = processp->handle;
             ncount++;
@@ -787,11 +787,11 @@ value omake_shell_sys_wait(value v_pgrp,
     /* Wait for an event */
     while(1) {
         /* Perform the wait */
-        enter_blocking_section();
+        caml_enter_blocking_section();
         index = WaitForMultipleObjects(ncount, handles, FALSE, timeout);
         if(index == WAIT_FAILED)
             code = GetLastError();
-        leave_blocking_section();
+        caml_leave_blocking_section();
 
         /* See if something has changed */
         if(index == WAIT_OBJECT_0) {
@@ -810,7 +810,7 @@ value omake_shell_sys_wait(value v_pgrp,
     else if(index >= WAIT_ABANDONED_0 + 1 && index < WAIT_ABANDONED_0 + ncount)
         index -= WAIT_ABANDONED_0;
     else
-        raise_not_found();
+        caml_raise_not_found();
 
     /* Adjust process */
     pid = processes[index];
@@ -863,7 +863,7 @@ value omake_shell_sys_wait(value v_pgrp,
         break;
     case STATUS_RUNNING:
     default:
-        invalid_argument("wait_process: process is running");
+        caml_invalid_argument("wait_process: process is running");
         break;
     }
 
@@ -908,7 +908,7 @@ value omake_shell_sys_create_process(val
         strp = String_val(Field(v_envp, i));
         length = strlen(strp);
         if(index + length + 2 > SIZEOF_ENVIRONMENT)
-            failwith("omake_shell_sys_create_process: environment is too big");
+            caml_failwith("omake_shell_sys_create_process: environment is too big");
         strcpy(env + index, strp);
         index += length + 1;
     }
@@ -919,7 +919,7 @@ value omake_shell_sys_create_process(val
     v_argvp = Field(v_info, CREATE_PROCESS_ARGV);
     count = Wosize_val(v_argvp);
     if(count == 0)
-        invalid_argument("omake_shell_sys_create_process: command line is empty");
+        caml_invalid_argument("omake_shell_sys_create_process: command line is empty");
     index = 0;
     for(i = 0; i != count; i++) {
         /* Win32 doesn't deal well when the command name differs from the executable */
@@ -930,7 +930,7 @@ value omake_shell_sys_create_process(val
         length = strlen(argp);
         white = string_escape_length(argp);
         if(index + length + white + 4 >= SIZEOF_COMMAND)
-            failwith("omake_shell_sys_create_process: command line is too long");
+            caml_failwith("omake_shell_sys_create_process: command line is too long");
         if(index)
             argv[index++] = ' ';
         if(white)
@@ -1019,13 +1019,13 @@ value omake_shell_sys_create_process(val
         if ((bufLen < 1) || (bufLen > 1024)) {
             if (lpMsgBuf != NULL) 
                 LocalFree( lpMsgBuf );
-            failwith("omake_shell_sys_create_process: process creation failed");
+            caml_failwith("omake_shell_sys_create_process: process creation failed");
         } else {
             char err[2048];
             sprintf(err, "omake_shell_sys_create_process: process creation failed: %s", (char *)lpMsgBuf);
             if (lpMsgBuf != NULL) 
                 LocalFree( lpMsgBuf );
-            failwith(err);
+            caml_failwith(err);
         }
     }
     CloseHandle(process.hThread);
@@ -1034,7 +1034,7 @@ value omake_shell_sys_create_process(val
     processp = (Process *) malloc(sizeof(Process));
     if(processp == 0) {
         CloseHandle(process.hProcess);
-        failwith("omake_shell_sys_create_process: out of memory");
+        caml_failwith("omake_shell_sys_create_process: out of memory");
     }
     memset(processp, 0, sizeof(Process));
     processp->pid = pid;
@@ -1129,13 +1129,13 @@ value omake_shell_sys_init(value v_unit)
     /* Allocate a struct for the current process */
     processp = (Process *) malloc(sizeof(Process));
     if(processp == 0)
-        failwith("Omake_shell_csys.create_state: out of memory");
+        caml_failwith("Omake_shell_csys.create_state: out of memory");
     memset(processp, 0, sizeof(Process));
 
     /* Allocate the state */
     state = (ShellState *) malloc(sizeof(ShellState));
     if(state == 0)
-        failwith("Omake_shell_csys.create_state: out of memory");
+        caml_failwith("Omake_shell_csys.create_state: out of memory");
     memset(state, 0, sizeof(ShellState));
     state->pid_counter = INIT_PID;
     state->changed = CreateEvent(NULL, FALSE, FALSE, NULL);
