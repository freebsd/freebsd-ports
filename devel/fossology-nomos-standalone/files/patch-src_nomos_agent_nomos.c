--- src/nomos/agent/nomos.c.orig	2021-05-07 09:49:07 UTC
+++ src/nomos/agent/nomos.c
@@ -33,6 +33,12 @@
 #include "nomos.h"
 #include "nomos_utils.h"
 
+char debugStr[myBUFSIZ];
+char dbErrString[myBUFSIZ];
+char saveLics[myBUFSIZ];
+
+size_t hashEntries;
+
 extern licText_t licText[]; /* Defined in _autodata.c */
 struct globals gl;
 struct curScan cur;
