--- source/sys_sdl.cpp.orig	Wed Jan 21 15:22:13 2004
+++ source/sys_sdl.cpp	Wed Jan 21 15:29:23 2004
@@ -45,7 +45,7 @@
 
 // EXTERNAL FUNCTION PROTOTYPES --------------------------------------------
 
-#ifdef __i386__
+#if defined(__i386__)
 extern "C" {
 
   void Sys_SetFPCW(void);
@@ -61,8 +61,10 @@
 
 // PUBLIC DATA DEFINITIONS -------------------------------------------------
 
+#ifndef __FreeBSD__
 jmp_buf __Context::Env;
 const char* __Context::ErrToThrow;
+#endif
 
 // PRIVATE DATA DEFINITIONS ------------------------------------------------
 
@@ -256,6 +258,7 @@
 
 void Sys_MakeCodeWriteable(unsigned long startaddr, unsigned long length)
 {
+#ifndef __FreeBSD__
 	int r;
 	unsigned long addr;
 	int psize = getpagesize();
@@ -268,6 +271,7 @@
 	{
 		Sys_Error("Protection change failed\n");
 	}
+#endif
 }
 
 //**************************************************************************
@@ -726,6 +730,7 @@
 {
 	signal(s, SIG_IGN);	// Ignore future instances of this signal.
 
+#ifndef __FreeBSD__
 	switch (s)
 	{
 	case SIGABRT:
@@ -756,6 +761,27 @@
 		__Context::ErrToThrow = "Terminated by signal";
 	}
 	longjmp(__Context::Env, 1);
+#else
+        switch (s)
+        {
+         case SIGABRT:  throw VavoomError("Abnormal termination triggered by abort call");
+         case SIGFPE:   throw VavoomError("Floating Point Exception");
+         case SIGILL:   throw VavoomError("Illegal Instruction");
+         case SIGINT:   throw VavoomError("Interrupted by User");
+         case SIGSEGV:  throw VavoomError("Segmentation Violation");
+         case SIGTERM:  throw VavoomError("Software termination signal from kill");
+#ifdef SIGKILL
+         case SIGKILL:  throw VavoomError("Killed");
+#endif
+#ifdef SIGQUIT
+         case SIGQUIT:  throw VavoomError("Quited");
+#endif
+#ifdef SIGNOFP
+         case SIGNOFP:  throw VavoomError("VAVOOM requires a floating-point processor");
+#endif
+     default:           throw VavoomError("Terminated by signal");
+        }
+#endif
 }
 
 //==========================================================================
