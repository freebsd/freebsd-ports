--- src/pptout/filewatcher.h.orig	Sun Nov  2 11:53:06 2003
+++ src/pptout/filewatcher.h	Sun Nov  2 11:53:23 2003
@@ -5,6 +5,7 @@
 ///
 #include <sigc++/sigc++.h>
 #include <string>
+#include <sys/time.h>
 
 class File_Watcher: public SigC::Object {
 public:
