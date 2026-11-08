commit f782f360bcd41d2a4282e40cf888e880a7fb08b6
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    set_os_thread_name needs BS_THREAD_POOL_NATIVE_EXTENSIONS
    
    which we do not have here

diff --git eeschema/sch_io/database/sch_io_database.cpp eeschema/sch_io/database/sch_io_database.cpp
index 4af8f06aa7..46befef89f 100644
--- eeschema/sch_io/database/sch_io_database.cpp
+++ eeschema/sch_io/database/sch_io_database.cpp
@@ -424,7 +424,9 @@ void SCH_IO_DATABASE::stopBackgroundRefresh()
 
 void SCH_IO_DATABASE::backgroundRefreshWorker()
 {
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
     BS::this_thread::set_os_thread_name( "dblib bg" );
+#endif
 
     while( m_refreshRunning.load() )
     {
