--- fdbserver/fdbserver.actor.cpp.orig	2019-01-09 22:28:32 UTC
+++ fdbserver/fdbserver.actor.cpp
@@ -60,7 +60,7 @@
 #define BOOST_DATE_TIME_NO_LIB
 #include <boost/interprocess/managed_shared_memory.hpp>
 
-#ifdef  __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <execinfo.h>
 #include <signal.h>
 #ifdef ALLOC_INSTRUMENTATION
@@ -73,6 +73,7 @@
 #endif
 
 #include "flow/SimpleOpt.h"
+#include <fstream>
 
 enum {
 	OPT_CONNFILE, OPT_SEEDCONNFILE, OPT_SEEDCONNSTRING, OPT_ROLE, OPT_LISTEN, OPT_PUBLICADDR, OPT_DATAFOLDER, OPT_LOGFOLDER, OPT_PARENTPID, OPT_NEWCONSOLE, OPT_NOBOX, OPT_TESTFILE, OPT_RESTARTING, OPT_RANDOMSEED, OPT_KEY, OPT_MEMLIMIT, OPT_STORAGEMEMLIMIT, OPT_MACHINEID, OPT_DCID, OPT_MACHINE_CLASS, OPT_BUGGIFY, OPT_VERSION, OPT_CRASHONERROR, OPT_HELP, OPT_NETWORKIMPL, OPT_NOBUFSTDOUT, OPT_BUFSTDOUTERR, OPT_TRACECLOCK, OPT_NUMTESTERS, OPT_DEVHELP, OPT_ROLLSIZE, OPT_MAXLOGS, OPT_MAXLOGSSIZE, OPT_KNOB, OPT_TESTSERVERS, OPT_TEST_ON_SERVERS, OPT_METRICSCONNFILE, OPT_METRICSPREFIX,
@@ -353,7 +354,7 @@ class WorldReadablePermissions { (public)
 			throw platform_error();
 		}
 		permission.set_permissions( &sa );
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__))
 		// There is nothing to do here, since the default permissions are fine
 #else
 		#error Port me!
@@ -363,7 +364,7 @@ class WorldReadablePermissions { (public)
 	virtual ~WorldReadablePermissions() {
 #ifdef _WIN32
 		LocalFree( sa.lpSecurityDescriptor );
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__))
 		// There is nothing to do here, since the default permissions are fine
 #else
 		#error Port me!
