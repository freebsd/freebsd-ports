--- ext/libarchive_internal.h.orig	2022-03-08 07:22:32 UTC
+++ ext/libarchive_internal.h
@@ -28,7 +28,6 @@
 #include <archive_entry.h>
 
 #include <ruby.h>
-#include <rubysig.h>
 
 #ifdef _WIN32
 #include "libarchive_win32.h"
