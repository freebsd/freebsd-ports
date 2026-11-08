--- extension/spatial/src/spatial/modules/proj/proj_module.cpp.orig	2026-11-08 00:39:12 UTC
+++ extension/spatial/src/spatial/modules/proj/proj_module.cpp
@@ -60,18 +60,6 @@ PJ_CONTEXT *ProjModule::GetThreadProjContext() {
 
 	const auto ctx = proj_context_create();
 
-	// We set the default context proj.db path to the one in the binary here
-	// Otherwise GDAL will try to load the proj.db from the system
-	// Any PJ_CONTEXT we create after this will inherit these settings
-	auto path = StringUtil::Format("file:/proj.db?immutable=1&ptr=%llu&sz=%lu&max=%lu", static_cast<void *>(proj_db),
-	                               proj_db_len, proj_db_len);
-
-	proj_context_set_sqlite3_vfs_name(ctx, "memvfs");
-	const auto ok = proj_context_set_database_path(ctx, path.c_str(), nullptr, nullptr);
-	if (!ok) {
-		throw InternalException("Could not set proj.db path");
-	}
-
 	// Dont log errors to stderr
 	proj_log_level(ctx, PJ_LOG_NONE);
 
@@ -88,45 +76,7 @@ void ProjModule::RegisterVFS(ExtensionLoader &loader) 
 	// Make sure this is only loaded once per process
 	// So that multiple duckdb connections that `LOAD spatial` don't overwrite the default sqlite vfs again
 
-	static std::once_flag loaded;
-	std::call_once(loaded, [&]() {
-		// we use the sqlite "memvfs" to store the proj.db database in the extension binary itself
-		// this way we don't have to worry about the user having the proj.db database installed
-		// on their system. We therefore have to tell proj to use memvfs as the sqlite3 vfs and
-		// point it to the segment of the binary that contains the proj.db database
-
-		sqlite3_initialize();
-		sqlite3_memvfs_init(nullptr, nullptr, nullptr);
-		const auto vfs = sqlite3_vfs_find("memvfs");
-		if (!vfs) {
-			throw InternalException("Could not find sqlite memvfs extension");
-		}
-		sqlite3_vfs_register(vfs, 0);
-
-		// We set the default context proj.db path to the one in the binary here
-		// Otherwise GDAL will try to load the proj.db from the system
-		// Any PJ_CONTEXT we create after this will inherit these settings (on this thread?)
-		auto path = StringUtil::Format("file:/proj.db?immutable=1&ptr=%llu&sz=%lu&max=%lu",
-		                               static_cast<void *>(proj_db), proj_db_len, proj_db_len);
-
-		proj_context_set_sqlite3_vfs_name(nullptr, "memvfs");
-
-		// Try to open the database
-		sqlite3 *sdb = nullptr;
-		const auto sok = sqlite3_open_v2(path.c_str(), &sdb, SQLITE_OPEN_READONLY, "memvfs");
-		if (sok != SQLITE_OK) {
-			sqlite3_close_v2(sdb);
-			throw InternalException("Could not open sqlite3 memvfs database");
-		}
-
-		const auto ok = proj_context_set_database_path(nullptr, path.c_str(), nullptr, nullptr);
-		if (!ok) {
-			sqlite3_close_v2(sdb);
-			throw InternalException("Could not set proj.db path");
-		}
-
-		sqlite3_close_v2(sdb);
-	});
+	// nothing to do: PROJ and GDAL find the system proj.db themselves
 }
 
 //######################################################################################################################
