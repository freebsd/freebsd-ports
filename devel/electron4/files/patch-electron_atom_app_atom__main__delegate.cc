--- electron/atom/app/atom_main_delegate.cc.orig	2019-03-16 12:34:08 UTC
+++ electron/atom/app/atom_main_delegate.cc
@@ -102,7 +102,7 @@ bool AtomMainDelegate::BasicStartupComplete(int* exit_
   logging::SetLogItems(true, false, true, false);
 
   // Enable convient stack printing.
-#if defined(DEBUG) && defined(OS_LINUX)
+#if defined(DEBUG) && (defined(OS_LINUX) || defined(OS_BSD))
   bool enable_stack_dumping = true;
 #else
   bool enable_stack_dumping = env->HasVar("ELECTRON_ENABLE_STACK_DUMPING");
