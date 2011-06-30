--- src/debug.cpp.orig	2011-06-18 23:31:24.000000000 +0400
+++ src/debug.cpp	2011-06-23 19:58:10.000000000 +0400
@@ -70,7 +70,7 @@
 {
 	DEBUGPRINT("\nIn thread %x:\n"
 			"%s:%d: %s: Assertion '%s' failed.\n",
-			(unsigned int)get_current_thread_id(),
+			(unsigned int)(intptr_t)get_current_thread_id(),
 			file, line, function, assertion);
 	
 	debug_stacks_print();
@@ -96,7 +96,7 @@
 void DebugStack::print(FILE *file, bool everything)
 {
 	fprintf(file, "DEBUG STACK FOR THREAD %x:\n",
-			(unsigned int)threadid);
+			(unsigned int)(intptr_t)threadid);
 
 	for(int i=0; i<stack_max_i; i++)
 	{
