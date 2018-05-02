--- fdbserver/worker.actor.cpp.orig	2018-04-26 12:45:22 UTC
+++ fdbserver/worker.actor.cpp
@@ -39,7 +39,7 @@
 #include "fdbclient/ClientWorkerInterface.h"
 #include "flow/Profiler.h"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #ifdef USE_GPERFTOOLS
 #include "gperftools/profiler.h"
 #endif
@@ -267,7 +267,7 @@ ACTOR Future<Void> registrationClient( R
 	}
 }
 
-#if defined(__linux__) && defined(USE_GPERFTOOLS)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(USE_GPERFTOOLS)
 //A set of threads that should be profiled
 std::set<std::thread::id> profiledThreads;
 
@@ -279,7 +279,7 @@ int filter_in_thread(void *arg) {
 
 //Enables the calling thread to be profiled
 void registerThreadForProfiling() {
-#if defined(__linux__) && defined(USE_GPERFTOOLS)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(USE_GPERFTOOLS)
 	//Not sure if this is actually needed, but a call to backtrace was advised here:
 	//http://groups.google.com/group/google-perftools/browse_thread/thread/0dfd74532e038eb8/2686d9f24ac4365f?pli=1
 	profiledThreads.insert(std::this_thread::get_id());
@@ -293,7 +293,7 @@ void registerThreadForProfiling() {
 void updateCpuProfiler(ProfilerRequest req) {
 	switch (req.type) {
 	case ProfilerRequest::Type::GPROF:
-#if defined(__linux__) && defined(USE_GPERFTOOLS) && !defined(VALGRIND)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(USE_GPERFTOOLS) && !defined(VALGRIND)
 		switch (req.action) {
 		case ProfilerRequest::Action::ENABLE: {
 			const char *path = (const char*)req.outputFile.begin();
