--- client/ServerRunner.cpp.orig	2024-08-25 21:27:47 UTC
+++ client/ServerRunner.cpp
@@ -9,16 +9,17 @@
  */
 #include "StdInc.h"
 
+#ifndef VCMI_MOBILE
+#include <boost/process/v1/child.hpp>
+#include <boost/process/v1/io.hpp>
+#endif
+
 #include "ServerRunner.h"
 
 #include "../lib/VCMIDirs.h"
 #include "../lib/CThreadHelper.h"
 #include "../server/CVCMIServer.h"
 
-#ifndef VCMI_MOBILE
-#include <boost/process/child.hpp>
-#include <boost/process/io.hpp>
-#endif
 
 ServerThreadRunner::ServerThreadRunner() = default;
 ServerThreadRunner::~ServerThreadRunner() = default;
@@ -84,7 +85,7 @@ void ServerProcessRunner::start(uint16_t port, bool co
 		args.push_back("--lobby");
 
 	std::error_code ec;
-	child = std::make_unique<boost::process::child>(serverPath, args, ec, boost::process::std_out > logPath);
+	child = std::make_unique<boost::process::v1::child>(serverPath, args, ec, boost::process::v1::std_out > logPath);
 
 	if (ec)
 		throw std::runtime_error("Failed to start server! Reason: " + ec.message());
