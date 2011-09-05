--- src/common/global/process.cpp.orig	2010-07-06 01:16:49.000000000 +0900
+++ src/common/global/process.cpp	2011-08-22 00:40:39.000000000 +0900
@@ -20,6 +20,8 @@
 #include "purl.h"
 #include "common/common/synchronous.h"
 
+extern char **environ;
+
 //----------------------------------------------------------------------------
 Process::State Process::runSynchronously(Base &process, RunActions actions, uint timeout)
 {
