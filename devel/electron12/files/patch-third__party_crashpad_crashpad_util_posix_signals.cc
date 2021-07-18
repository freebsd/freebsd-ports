--- third_party/crashpad/crashpad/util/posix/signals.cc.orig	2021-01-07 00:37:22 UTC
+++ third_party/crashpad/crashpad/util/posix/signals.cc
@@ -228,8 +228,12 @@ bool Signals::WillSignalReraiseAutonomously(const sigi
          // remains. See 10.12.3 xnu-3789.41.3/bsd/kern/kern_sig.c
          // psignal_internal().
          (code > 0 &&
+#if defined(SI_ASYNCIO)
           code != SI_ASYNCIO &&
+#endif
+#if defined(SI_MESGQ)
           code != SI_MESGQ &&
+#endif
           code != SI_QUEUE &&
           code != SI_TIMER &&
           code != SI_USER &&
