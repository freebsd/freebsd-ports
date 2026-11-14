--- eeschema/sch_io/http_lib/sch_io_http_lib.cpp.orig	2026-11-14 05:57:13 UTC
+++ eeschema/sch_io/http_lib/sch_io_http_lib.cpp
@@ -101,7 +101,10 @@ void SCH_IO_HTTP_LIB::backgroundRefreshWorker()
 
 void SCH_IO_HTTP_LIB::backgroundRefreshWorker()
 {
+
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
     BS::this_thread::set_os_thread_name( "httplib bg" );
+#endif
 
     while( m_refreshRunning.load() )
     {
