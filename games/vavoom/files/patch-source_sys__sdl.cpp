--- source/sys_sdl.cpp.orig
+++ source/sys_sdl.cpp
@@ -61,8 +61,8 @@
 
 // PUBLIC DATA DEFINITIONS -------------------------------------------------
 
-jmp_buf __Context::Env;
-const char* __Context::ErrToThrow;
+//jmp_buf __Context::Env;
+//const char* __Context::ErrToThrow;
 
 // PRIVATE DATA DEFINITIONS ------------------------------------------------
 
@@ -733,33 +733,33 @@
 	switch (s)
 	{
 	case SIGABRT:
-		__Context::ErrToThrow = "Aborted";
+		throw VavoomError("Aborted");
 		break;
 	case SIGFPE:
-		__Context::ErrToThrow = "Floating Point Exception";
+		throw VavoomError("Floating Point Exception");
 		break;
 	case SIGILL:
-		__Context::ErrToThrow = "Illegal Instruction";
+		throw VavoomError("Illegal Instruction");
 		break;
 	case SIGSEGV:
-		__Context::ErrToThrow = "Segmentation Violation";
+		throw VavoomError("Segmentation Violation");
 		break;
 	case SIGTERM:
-		__Context::ErrToThrow = "Terminated";
+		throw VavoomError("Terminated");
 		break;
 	case SIGINT:
-		__Context::ErrToThrow = "Interrupted by User";
+		throw VavoomError("Interrupted by User");
 		break;
 	case SIGKILL:
-		__Context::ErrToThrow = "Killed";
+		throw VavoomError("Killed");
 		break;
 	case SIGQUIT:
-		__Context::ErrToThrow = "Quited";
+		throw VavoomError("Quited");
 		break;
 	default:
-		__Context::ErrToThrow = "Terminated by signal";
+		throw VavoomError("Terminated by signal");
 	}
-	longjmp(__Context::Env, 1);
+//	longjmp(__Context::Env, 1);
 }
 
 //==========================================================================
