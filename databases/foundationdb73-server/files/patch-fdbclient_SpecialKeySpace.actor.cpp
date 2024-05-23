--- fdbclient/SpecialKeySpace.actor.cpp.orig	2023-11-07 15:13:56 UTC
+++ fdbclient/SpecialKeySpace.actor.cpp
@@ -2996,7 +2996,7 @@ ACTOR Future<Void> validateSpecialSubrangeRead(ReadYou
 	// Test
 	RangeResult testResult = wait(ryw->getRange(testBegin, testEnd, limits, Snapshot::True, reverse));
 	if (testResult != expectedResult) {
-		fmt::print("Reverse: {}\n", reverse);
+		fmt::print("Reverse: {}\n", static_cast<bool>(reverse));
 		fmt::print("Original range: [{}, {})\n", begin.toString(), end.toString());
 		fmt::print("Original result:\n");
 		for (const auto& kr : result) {
