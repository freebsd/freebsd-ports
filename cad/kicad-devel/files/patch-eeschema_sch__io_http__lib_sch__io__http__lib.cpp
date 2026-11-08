--- eeschema/sch_io/http_lib/sch_io_http_lib.cpp.orig	2026-10-01 19:47:08 UTC
+++ eeschema/sch_io/http_lib/sch_io_http_lib.cpp
@@ -96,7 +96,10 @@ void SCH_IO_HTTP_LIB::backgroundRefreshWorker()
 
 void SCH_IO_HTTP_LIB::backgroundRefreshWorker()
 {
+
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
     BS::this_thread::set_os_thread_name( "httplib bg" );
+#endif
 
     while( m_refreshRunning.load() )
     {
