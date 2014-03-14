--- src/tlStream.cc.orig	2014-03-14 22:31:20.000000000 +0900
+++ src/tlStream.cc	2014-03-14 22:33:08.000000000 +0900
@@ -31,6 +31,7 @@
 #ifdef _WIN32 
 #  include <io.h>
 #endif
+#include <unistd.h>
 
 #include "tlStream.h"
 #include "tlHttpStream.h"
@@ -624,7 +625,7 @@
 #if defined(_WIN32)
     _close (m_fd);
 #else
-    close (m_fd);
+    ::close (m_fd);
 #endif
     m_fd = -1;
   }  
@@ -654,7 +655,7 @@
 #elif defined(_WIN64)
     _lseek (m_fd, 0, SEEK_SET);
 #else
-    lseek (m_fd, 0, SEEK_SET);
+    ::lseek (m_fd, 0, SEEK_SET);
 #endif
   }
 }
@@ -1068,7 +1069,7 @@
 #elif defined(_WIN32)
   _lseek (m_fd, s, SEEK_SET);
 #else
-  lseek (m_fd, s, SEEK_SET);
+  ::lseek (m_fd, s, SEEK_SET);
 #endif
 }
 
