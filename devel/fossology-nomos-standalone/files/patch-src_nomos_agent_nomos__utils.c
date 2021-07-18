--- src/nomos/agent/nomos_utils.c.orig	2021-05-07 09:49:07 UTC
+++ src/nomos/agent/nomos_utils.c
@@ -23,6 +23,9 @@
 #include "nomos_utils.h"
 #include "nomos.h"
 
+sem_t* mutexJson;           ///< Mutex to handle JSON writes
+gboolean* printcomma;       ///< True to print comma while printing JSON object
+
 #define FUNCTION
 
 /**
