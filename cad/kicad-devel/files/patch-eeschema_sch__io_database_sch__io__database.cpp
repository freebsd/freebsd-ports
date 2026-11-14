--- eeschema/sch_io/database/sch_io_database.cpp.orig	2026-11-14 11:19:11 UTC
+++ eeschema/sch_io/database/sch_io_database.cpp
@@ -644,7 +644,9 @@ void SCH_IO_DATABASE::backgroundRefreshWorker()
 
 void SCH_IO_DATABASE::backgroundRefreshWorker()
 {
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
     BS::this_thread::set_os_thread_name( "dblib bg" );
+#endif
 
     std::minstd_rand jitter( std::random_device{}() );
     int              busyRetries = 0;
