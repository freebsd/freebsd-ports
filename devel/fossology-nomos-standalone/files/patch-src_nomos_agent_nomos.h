--- src/nomos/agent/nomos.h.orig	2021-05-07 09:49:07 UTC
+++ src/nomos/agent/nomos.h
@@ -156,11 +156,11 @@
 #define OPTS_JSON_OUTPUT 0x20
 #define OPTS_SCANNING_DIRECTORY 0x40
 
-char debugStr[myBUFSIZ];        ///< Debug string
-char dbErrString[myBUFSIZ];     ///< DB error string
-char saveLics[myBUFSIZ];        ///< License string
+extern char debugStr[myBUFSIZ];        ///< Debug string
+extern char dbErrString[myBUFSIZ];     ///< DB error string
+extern char saveLics[myBUFSIZ];        ///< License string
 
-size_t hashEntries;             ///< Hash entries
+extern size_t hashEntries;             ///< Hash entries
 
 /**
   Flags for program control
