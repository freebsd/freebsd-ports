--- src/misc/AThread.cpp.orig	2013-02-10 06:35:02 UTC
+++ src/misc/AThread.cpp
@@ -416,7 +416,7 @@ using namespace std;
 			abort();
 		} catch(...) { 
 			// linux will abort, Mac will not so it will crash with unhandled exception and generate a crash report
-			fprintf(stderr,"unhandled exception was thrown within thread -- ID: %s:(%x); aborting\n", getThreadName().c_str(), (unsigned)thread->mThreadID);fflush(stderr);
+			fprintf(stderr,"unhandled exception was thrown within thread -- ID: %s:(%x); aborting\n", getThreadName().c_str(), thread->mThreadID);fflush(stderr);
 			
 			// we only abort all the time with linux code
 			abort();
