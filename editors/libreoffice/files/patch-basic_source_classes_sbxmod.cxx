--- basic/source/classes/sbxmod.cxx.orig
+++ basic/source/classes/sbxmod.cxx
@@ -1059,7 +1059,7 @@ void SbModule::Run( SbMethod* pMeth )
           struct rlimit rl;
           getrlimit ( RLIMIT_STACK, &rl );
 #endif
-#if defined LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
           // Empiric value, 900 = needed bytes/Basic call level
           // for Linux including 10% safety margin
           nMaxCallLevel = rl.rlim_cur / 900;
