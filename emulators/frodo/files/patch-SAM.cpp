--- SAM.cpp.orig	2002-01-02 21:20:16 UTC
+++ SAM.cpp
@@ -205,7 +205,7 @@ static const char adr_length[] = {1, 1, 
 
 // Prototypes
 static void error(char *s);
-static void handle_abort(...);
+static void handle_abort(int sig);
 static void init_abort(void);
 static void exit_abort(void);
 static bool aborted(void);
@@ -470,7 +470,7 @@ static bool WasAborted;
 struct sigaction my_sa;
 #endif
 
-static void handle_abort(...)
+static void handle_abort(int sig)
 {
 	WasAborted = true;
 #if !defined(HAVE_SIGACTION) && defined(HAVE_SIGNAL)
