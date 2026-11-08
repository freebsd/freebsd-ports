--- fdbserver/QuietDatabase.actor.cpp.orig	2025-07-02 21:14:39 UTC
+++ fdbserver/QuietDatabase.actor.cpp
@@ -22,6 +22,9 @@
 #include <vector>
 #include <map>
 
+#include <boost/lexical_cast.hpp>
+#include <fmt/ranges.h>
+
 #include "fdbclient/FDBOptions.g.h"
 #include "fdbclient/SystemData.h"
 #include "fdbrpc/simulator.h"
@@ -35,7 +38,7 @@
 #include "fdbserver/Knobs.h"
 #include "fdbserver/WorkerInterface.actor.h"
 #include "fdbclient/ManagementAPI.actor.h"
-#include <boost/lexical_cast.hpp>
+
 #include "flow/actorcompiler.h" // This must be the last #include.
 
 ACTOR Future<std::vector<WorkerDetails>> getWorkers(Reference<AsyncVar<ServerDBInfo> const> dbInfo, int flags = 0) {
