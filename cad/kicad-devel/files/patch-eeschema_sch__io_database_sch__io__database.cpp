--- eeschema/sch_io/database/sch_io_database.cpp.orig	2026-08-22 14:36:37 UTC
+++ eeschema/sch_io/database/sch_io_database.cpp
@@ -417,8 +417,9 @@ void SCH_IO_DATABASE::backgroundRefreshWorker()
 
 void SCH_IO_DATABASE::backgroundRefreshWorker()
 {
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
     BS::this_thread::set_os_thread_name( "dblib bg" );
-
+#endif
     while( m_refreshRunning.load() )
     {
         long long maxAge = 0;
