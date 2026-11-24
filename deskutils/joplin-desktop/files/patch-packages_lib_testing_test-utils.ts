--- packages/lib/testing/test-utils.ts.orig	2026-11-19 16:09:35 UTC
+++ packages/lib/testing/test-utils.ts
@@ -345,7 +345,7 @@ async function clearDatabase(id: number = null) {
 	const queries = [];
 	for (const n of tableNames) {
 		queries.push(`DELETE FROM ${n}`);
-		queries.push(`DELETE FROM sqlite_sequence WHERE name="${n}"`); // Reset autoincremented IDs
+		queries.push(`DELETE FROM sqlite_sequence WHERE name='${n}'`); // Reset autoincremented IDs
 	}
 	await databases_[id].transactionExecBatch(queries);
 }
