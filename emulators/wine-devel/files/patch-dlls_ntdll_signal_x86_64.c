--- UTC
commit 52cb060f41e96dfd2140a32b4ef70b1098f4b449
Author: Gerald Pfeifer <gerald@pfeifer.com>
Date:   Sun Apr 6 23:19:45 2025 +0200

    ntdll: Fix build on platforms without getauxval.
    
    Commit b1b5105ceb moved the following block
    
        #ifdef AT_HWCAP2
                 if (getauxval( AT_HWCAP2 ) & 2) syscall_flags |= SYSCALL_HAVE_WRFSGSBASE;
        #endif
    
    out of an #ifdef __linux__ block and it now causes failures on FreeBSD
    and others which do not have getauxval.

--- dlls/ntdll/unix/signal_x86_64.c
+++ dlls/ntdll/unix/signal_x86_64.c
@@ -2504,11 +2504,11 @@ void signal_init_process(void)
 
     if (cpu_info.ProcessorFeatureBits & CPU_FEATURE_XSAVE) syscall_flags |= SYSCALL_HAVE_XSAVE;
     if (xstate_compaction_enabled) syscall_flags |= SYSCALL_HAVE_XSAVEC;
+
+#ifdef __linux__
 #ifdef AT_HWCAP2
     if (getauxval( AT_HWCAP2 ) & 2) syscall_flags |= SYSCALL_HAVE_WRFSGSBASE;
 #endif
-
-#ifdef __linux__
     if (wow_teb)
     {
         int sel;
