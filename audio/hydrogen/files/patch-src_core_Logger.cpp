--- src/core/Logger.cpp.orig	2022-10-17 00:49:12 UTC
+++ src/core/Logger.cpp
@@ -65,6 +65,7 @@ void* loggerThread_func( void* param ) {
 	Logger::queue_t::iterator it, last;
 
 	while ( logger->__running ) {
+		pthread_mutex_lock( &logger->__mutex );
 		pthread_cond_wait( &logger->__messages_available, &logger->__mutex );
 		pthread_mutex_unlock( &logger->__mutex );
 		if( !queue->empty() ) {
