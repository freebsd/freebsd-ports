--- boost/test/impl/execution_monitor.ipp	Mon Oct 13 12:20:26 2008
+++ boost/test/impl/execution_monitor.ipp	Sun Nov  9 00:36:42 2008
@@ -289,50 +289,11 @@
 
     switch( m_sig_info->si_signo ) {
     case SIGILL:
-        switch( m_sig_info->si_code ) {
-        case ILL_ILLOPC:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: illegal opcode; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_ILLOPN:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: illegal operand; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_ILLADR:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: illegal addressing mode; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_ILLTRP:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: illegal trap; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_PRVOPC:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: privileged opcode; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_PRVREG:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: privileged register; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_COPROC:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: co-processor error; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_BADSTK:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: internal stack error; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        }
+        // FreeBSD 6.2 does not provide details for this signal as required by SUSv3
+        report_error( execution_exception::system_fatal_error,
+		      "signal: SIGILL (illegal instruction)" );
         break;
-
+	
     case SIGFPE:
         switch( m_sig_info->si_code ) {
         case FPE_INTDIV:
@@ -379,73 +340,21 @@
         break;
 
     case SIGSEGV:
-        switch( m_sig_info->si_code ) {
-        case SEGV_MAPERR:
-            report_error( execution_exception::system_fatal_error,
-                          "memory access violation at address: 0x%08lx: no mapping at fault address",
-                          m_sig_info->si_addr );
-            break;
-        case SEGV_ACCERR:
-            report_error( execution_exception::system_fatal_error,
-                          "memory access violation at address: 0x%08lx: invalid permissions",
-                          m_sig_info->si_addr );
-            break;
-        }
+        // FreeBSD 6.2 does not provide details for this signal as required by SUSv3
+        report_error( execution_exception::system_fatal_error,
+                      "signal: SIGSEGV (invalid memory reference)" );
         break;
 
     case SIGBUS:
-        switch( m_sig_info->si_code ) {
-        case BUS_ADRALN:
-            report_error( execution_exception::system_fatal_error,
-                          "memory access violation at address: 0x%08lx: invalid address alignment",
-                          m_sig_info->si_addr );
-            break;
-        case BUS_ADRERR:
-            report_error( execution_exception::system_fatal_error,
-                          "memory access violation at address: 0x%08lx: non-existent physical address",
-                          m_sig_info->si_addr );
-            break;
-        case BUS_OBJERR:
-            report_error( execution_exception::system_fatal_error,
-                          "memory access violation at address: 0x%08lx: object specific hardware error",
-                          m_sig_info->si_addr );
-            break;
-        }
+        // FreeBSD 6.2 does not provide details for this signal as required by SUSv3
+        report_error( execution_exception::system_fatal_error,
+                      "signal: SIGBUS (access to an undefined portion of a memory object)" );
         break;
 
     case SIGCHLD:
-        switch( m_sig_info->si_code ) {
-        case CLD_EXITED:
-            report_error( execution_exception::system_error,
-                          "child has exited; pid: %d; uid: %d; exit value: %d",
-                          (int)m_sig_info->si_pid, (int)m_sig_info->si_uid, (int)m_sig_info->si_status );
-            break;
-        case CLD_KILLED:
-            report_error( execution_exception::system_error,
-                          "child was killed; pid: %d; uid: %d; exit value: %d",
-                          (int)m_sig_info->si_pid, (int)m_sig_info->si_uid, (int)m_sig_info->si_status );
-            break;
-        case CLD_DUMPED:
-            report_error( execution_exception::system_error,
-                          "child terminated abnormally; pid: %d; uid: %d; exit value: %d",
-                          (int)m_sig_info->si_pid, (int)m_sig_info->si_uid, (int)m_sig_info->si_status );
-            break;
-        case CLD_TRAPPED:
-            report_error( execution_exception::system_error,
-                          "traced child has trapped; pid: %d; uid: %d; exit value: %d",
-                          (int)m_sig_info->si_pid, (int)m_sig_info->si_uid, (int)m_sig_info->si_status );
-            break;
-        case CLD_STOPPED:
-            report_error( execution_exception::system_error,
-                          "child has stopped; pid: %d; uid: %d; exit value: %d",
-                          (int)m_sig_info->si_pid, (int)m_sig_info->si_uid, (int)m_sig_info->si_status );
-            break;
-        case CLD_CONTINUED:
-            report_error( execution_exception::system_error,
-                          "stopped child had continued; pid: %d; uid: %d; exit value: %d",
-                          (int)m_sig_info->si_pid, (int)m_sig_info->si_uid, (int)m_sig_info->si_status );
-            break;
-        }
+        // FreeBSD 6.2 does not provide details for this signal as required by SUSv3
+        report_error( execution_exception::system_error,
+                      "signal: SIGCHLD (child process terminated, stopped, or continued)" );
         break;
 
 #if defined(BOOST_TEST_CATCH_SIGPOLL)
@@ -695,7 +604,8 @@
 
 static bool ignore_sigchild( siginfo_t* info )
 {
-    return info->si_signo == SIGCHLD && info->si_code == CLD_EXITED 
+    // for now just use an assumption that children always exit normally
+    return true //info->si_signo == SIGCHLD && info->si_code == CLD_EXITED 
 #ifdef BOOST_TEST_IGNORE_NON_ZERO_CHILD_CODE
             ;
 #else
