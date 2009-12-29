--- boost/test/impl/execution_monitor.ipp.orig	2009-09-23 16:44:57.000000000 +0400
+++ boost/test/impl/execution_monitor.ipp	2009-09-23 16:59:44.000000000 +0400
@@ -319,48 +319,7 @@
     switch( m_sig_info->si_signo ) {
     case SIGILL:
         switch( m_sig_info->si_code ) {
-#ifndef BOOST_TEST_LIMITED_SIGNAL_DETAILS
-        case ILL_ILLOPC:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: illegal opcode; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_ILLTRP:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: illegal trap; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_PRVREG:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: privileged register; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_BADSTK:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: internal stack error; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-#endif
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
-        case ILL_PRVOPC:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: privileged opcode; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
-        case ILL_COPROC:
-            report_error( execution_exception::system_fatal_error,
-                          "signal: co-processor error; address of failing instruction: 0x%08lx",
-                          m_sig_info->si_addr );
-            break;
+	  // FreeBSD 6.x does not provide details for this signal as required by SUSv3
         default: 
             report_error( execution_exception::system_fatal_error, 
                           "signal: SIGILL, si_code: %d (illegal instruction; address of failing instruction: 0x%08lx)", 
@@ -421,18 +380,7 @@
 
     case SIGSEGV:
         switch( m_sig_info->si_code ) {
-#ifndef BOOST_TEST_LIMITED_SIGNAL_DETAILS
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
-#endif
+	  // FreeBSD 6.x does not provide details for this signal as required by SUSv3
         default:
             report_error( execution_exception::system_fatal_error,
                           "signal: SIGSEGV, si_code: %d (memory access violation at address: 0x%08lx)",
@@ -443,23 +391,7 @@
 
     case SIGBUS:
         switch( m_sig_info->si_code ) {
-#ifndef BOOST_TEST_LIMITED_SIGNAL_DETAILS
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
-#endif
+	  // FreeBSD 6.x does not provide details for this signal as required by SUSv3
         default:
             report_error( execution_exception::system_fatal_error,
                           "signal: SIGSEGV, si_code: %d (memory access violation at address: 0x%08lx)",
@@ -470,38 +402,7 @@
 
     case SIGCHLD:
         switch( m_sig_info->si_code ) {
-#ifndef BOOST_TEST_LIMITED_SIGNAL_DETAILS
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
-#endif
+	  // FreeBSD 6.x does not provide details for this signal as required by SUSv3
         default:
             report_error( execution_exception::system_error,
                           "signal: SIGCHLD, si_code: %d (child process has terminated; pid: %d; uid: %d; exit value: %d)",
@@ -771,15 +672,7 @@
 
 static bool ignore_sigchild( siginfo_t* info )
 {
-    return info->si_signo == SIGCHLD
-#ifndef BOOST_TEST_LIMITED_SIGNAL_DETAILS
-            && info->si_code == CLD_EXITED 
-#endif
-#ifdef BOOST_TEST_IGNORE_NON_ZERO_CHILD_CODE
-            ;
-#else
-            && (int)info->si_status == 0;
-#endif
+    return info->si_signo == SIGCHLD && (int)info->si_status == 0;
 }
 
 //____________________________________________________________________________//
