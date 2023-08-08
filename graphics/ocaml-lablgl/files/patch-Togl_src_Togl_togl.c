--- Togl/src/Togl/togl.c.orig	2013-09-20 10:50:36 UTC
+++ Togl/src/Togl/togl.c
@@ -96,7 +96,7 @@ static void (*SetClassProcsPtr)
 /* pointer to Tk_SetClassProcs function in the stub table */
 
 static void (*SetClassProcsPtr)
-        _ANSI_ARGS_((Tk_Window, Tk_ClassProcs *, ClientData));
+        _ANSI_ARGS_((Tk_Window, const Tk_ClassProcs *, ClientData));
 #endif
 
 /* 
