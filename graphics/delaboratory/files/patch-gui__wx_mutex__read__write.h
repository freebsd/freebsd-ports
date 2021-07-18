--- gui_wx/mutex_read_write.h.orig	2012-06-08 22:38:01 UTC
+++ gui_wx/mutex_read_write.h
@@ -20,7 +20,7 @@
 #define _DE_MUTEX_READ_WRITE_H
 
 #include "mutex.h"
-#include "semaphore.h"
+#include "desemaphore.h"
 
 class deMutexReadWrite
 {
