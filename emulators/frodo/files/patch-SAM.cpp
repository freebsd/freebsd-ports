
$FreeBSD$

--- SAM.cpp.orig	Sat Nov 30 01:25:40 2002
+++ SAM.cpp	Sat Nov 30 01:26:38 2002
@@ -205,7 +205,7 @@
 
 // Prototypes
 static void error(char *s);
-static void handle_abort(...);
+static void handle_abort(int sig);
 static void init_abort(void);
 static void exit_abort(void);
 static bool aborted(void);
@@ -470,7 +470,7 @@
 struct sigaction my_sa;
 #endif
 
-static void handle_abort(...)
+static void handle_abort(int sig)
 {
 	WasAborted = true;
 #if !defined(HAVE_SIGACTION) && defined(HAVE_SIGNAL)
