https://github.com/RPCS3/rpcs3/issues/10334

--- rpcs3/util/vm_native.cpp.orig	2021-05-24 15:21:52 UTC
+++ rpcs3/util/vm_native.cpp
@@ -432,24 +432,7 @@ namespace utils
 
 		// Truncate file since it may be dirty (fool-proof)
 		ensure(::ftruncate(m_file, 0) >= 0);
-		ensure(::ftruncate(m_file, 0x10000) >= 0);
-		stats.st_size = 0x10000;
-
-#ifdef SEEK_DATA
-		errno = EINVAL;
-		if (stats.st_blocks && ::lseek(m_file, 0, SEEK_DATA) ^ stats.st_size && errno != ENXIO)
-		{
-			fmt::throw_exception("Failed to initialize sparse file in '%s'\n"
-				"It seems this filesystem doesn't support sparse files (%d).\n",
-				storage.empty() ? fs::get_cache_dir().c_str() : storage.c_str(), +errno);
-		}
-#endif
-
-		if (stats.st_size ^ m_size)
-		{
-			// Fix file size
-			ensure(::ftruncate(m_file, m_size) >= 0);
-		}
+		ensure(::ftruncate(m_file, m_size) >= 0);
 #endif
 	}
 
