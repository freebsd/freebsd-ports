--- src/corelib/thread/qthread.h.orig	2022-08-20 09:18:52 UTC
+++ src/corelib/thread/qthread.h
@@ -191,12 +191,12 @@ inline Qt::HANDLE QThread::currentThreadId() noexcept
     Qt::HANDLE tid; // typedef to void*
     static_assert(sizeof(tid) == sizeof(void*));
     // See https://akkadia.org/drepper/tls.pdf for x86 ABI
-#if defined(Q_PROCESSOR_X86_32) && defined(Q_OS_LINUX) && defined(__GLIBC__) // x86 32-bit always uses GS
+#if defined(Q_PROCESSOR_X86_32) && ((defined(Q_OS_LINUX) && defined(__GLIBC__)) || defined(Q_OS_FREEBSD)) // x86 32-bit always uses GS
     __asm__("movl %%gs:%c1, %0" : "=r" (tid) : "i" (2 * sizeof(void*)) : );
 #elif defined(Q_PROCESSOR_X86_64) && defined(Q_OS_DARWIN64)
     // 64bit macOS uses GS, see https://github.com/apple/darwin-xnu/blob/master/libsyscall/os/tsd.h
     __asm__("movq %%gs:0, %0" : "=r" (tid) : : );
-#elif defined(Q_PROCESSOR_X86_64) && (defined(Q_OS_LINUX) && defined(__GLIBC__)) || defined(Q_OS_FREEBSD)
+#elif defined(Q_PROCESSOR_X86_64) && ((defined(Q_OS_LINUX) && defined(__GLIBC__)) || defined(Q_OS_FREEBSD))
     // x86_64 Linux, BSD uses FS
     __asm__("movq %%fs:%c1, %0" : "=r" (tid) : "i" (2 * sizeof(void*)) : );
 #elif defined(Q_PROCESSOR_X86_64) && defined(Q_OS_WIN)
