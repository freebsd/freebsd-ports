--- src/nomos/agent/nomos_utils.h.orig	2021-05-07 09:49:07 UTC
+++ src/nomos/agent/nomos_utils.h
@@ -35,8 +35,8 @@
 #define LICENSE_REF_TABLE "ONLY license_ref"
 #define SEM_DEFAULT_VALUE 4
 
-sem_t* mutexJson;           ///< Mutex to handle JSON writes
-gboolean* printcomma;       ///< True to print comma while printing JSON object
+extern sem_t* mutexJson;           ///< Mutex to handle JSON writes
+extern gboolean* printcomma;       ///< True to print comma while printing JSON object
 
 
 /** shortname cache very simple nonresizing hash table */
