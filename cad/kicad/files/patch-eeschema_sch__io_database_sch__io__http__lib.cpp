commit 1cf39d12672b1363b75f9ddbcf14b5f429d2c875
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    set_os_thread_name needs BS_THREAD_POOL_NATIVE_EXTENSIONS
    
    which we do not have here

diff --git eeschema/sch_io/http_lib/sch_io_http_lib.cpp eeschema/sch_io/http_lib/sch_io_http_lib.cpp
index d99dad346f..a636113cbe 100644
--- eeschema/sch_io/http_lib/sch_io_http_lib.cpp
+++ eeschema/sch_io/http_lib/sch_io_http_lib.cpp
@@ -96,7 +96,9 @@ void SCH_IO_HTTP_LIB::startBackgroundRefresh()
 
 void SCH_IO_HTTP_LIB::backgroundRefreshWorker()
 {
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
     BS::this_thread::set_os_thread_name( "httplib bg" );
+#endif
 
     while( m_refreshRunning.load() )
     {
