--- axel.c.orig	Sun Aug  5 23:40:26 2001
+++ axel.c	Sun Aug  5 23:41:19 2001
@@ -797,10 +797,11 @@
 void *setup_thread( void *c )
 {
 	conn_t *conn = c;
+	int		oldstate;
 	
 	/* Allow this thread to be killed at any time. */
-	pthread_setcancelstate( PTHREAD_CANCEL_ENABLE, NULL );
-	pthread_setcanceltype( PTHREAD_CANCEL_ASYNCHRONOUS, NULL );
+	pthread_setcancelstate( PTHREAD_CANCEL_ENABLE, &oldstate );
+	pthread_setcanceltype( PTHREAD_CANCEL_ASYNCHRONOUS, &oldstate );
 	
 	if( conn_setup( conn ) )
 	{
