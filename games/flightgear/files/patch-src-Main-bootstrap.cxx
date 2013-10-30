Backport of patch 78f2f2f,
fixes issue #1231

--- src/Main/bootstrap.cxx.orig
+++ src/Main/bootstrap.cxx
@@ -236,6 +236,11 @@ int main ( int argc, char **argv )
     // FIXME: add other, more specific
     // exceptions.
     try {
+        // http://code.google.com/p/flightgear-bugs/issues/detail?id=1231
+        // ensure sglog is inited before atexit() is registered, so logging
+        // is possible inside fgExitCleanup
+        sglog();
+        
         std::set_terminate(fg_terminate);
         atexit(fgExitCleanup);
         if (fgviewer)
@@ -277,6 +282,8 @@ void fgExitCleanup() {
     if (_bootstrap_OSInit != 0)
         fgSetMouseCursor(MOUSE_CURSOR_POINTER);
 
+    // on the common exit path globals is already deleted, and NULL,
+    // so this only happens on error paths.
     delete globals;
 }
 
