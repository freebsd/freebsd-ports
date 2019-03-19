--- src/tl/tl/tlStream.cc.orig	2019-02-23 17:34:47 UTC
+++ src/tl/tl/tlStream.cc
@@ -30,6 +30,8 @@
 #include <errno.h>
 #ifdef _WIN32 
 #  include <io.h>
+#else
+#  include <unistd.h>
 #endif
 
 #include "tlStream.h"
@@ -1089,7 +1091,7 @@ OutputFile::~OutputFile ()
 #if defined(_WIN32)
     _close (m_fd);
 #else
-    close (m_fd);
+    ::close (m_fd);
 #endif
     m_fd = -1;
   }  
