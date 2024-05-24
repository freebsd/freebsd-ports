--- bindings/c/test/apitester/TesterWorkload.cpp.orig	2023-11-07 15:13:56 UTC
+++ bindings/c/test/apitester/TesterWorkload.cpp
@@ -172,7 +172,7 @@ void WorkloadBase::error(const std::string& msg) {
 	fmt::print(stderr, "[{}] ERROR: {}\n", workloadId, msg);
 	numErrors++;
 	if (numErrors > maxErrors && !failed) {
-		fmt::print(stderr, "[{}] ERROR: Stopping workload after {} errors\n", workloadId, numErrors);
+		fmt::print(stderr, "[{}] ERROR: Stopping workload after {} errors\n", workloadId, numErrors.load());
 		failed = true;
 	}
 }
