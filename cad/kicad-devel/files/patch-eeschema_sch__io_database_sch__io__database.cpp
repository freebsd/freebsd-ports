--- eeschema/sch_io/database/sch_io_database.cpp.orig	2026-10-01 19:47:08 UTC
+++ eeschema/sch_io/database/sch_io_database.cpp
@@ -431,8 +431,9 @@ void SCH_IO_DATABASE::backgroundRefreshWorker()
 
 void SCH_IO_DATABASE::backgroundRefreshWorker()
 {
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
     BS::this_thread::set_os_thread_name( "dblib bg" );
-
+#endif
     while( m_refreshRunning.load() )
     {
         long long maxAge = 0;
