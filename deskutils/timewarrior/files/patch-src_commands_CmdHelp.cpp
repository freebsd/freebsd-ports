--- src/commands/CmdHelp.cpp.orig	2020-07-28 19:41:05 UTC
+++ src/commands/CmdHelp.cpp
@@ -30,6 +30,7 @@
 #include <FS.h>
 #include <shared.h>
 #include <additional-help.h>
+#include <sys/wait.h>
 
 ////////////////////////////////////////////////////////////////////////////////
 int CmdHelpUsage (const Extensions& extensions)
