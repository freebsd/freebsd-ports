--- scumm/debugger.cpp.orig	Tue Aug  3 15:55:47 2004
+++ scumm/debugger.cpp	Tue Aug  3 15:56:18 2004
@@ -57,7 +57,7 @@
 	va_end(va);
 
 	debug(buf);
-};
+}
 	
 ScummDebugger::ScummDebugger(ScummEngine *s)
 	: Common::Debugger<ScummDebugger>() {
@@ -592,7 +592,7 @@
 
 	DebugPrintf("Unknown flag. Type 'Debug ?' for syntax\n");
 	return true;
-};
+}
 
 bool ScummDebugger::Cmd_DebugLevel(int argc, const char **argv) {
 	if (argc == 1) {
