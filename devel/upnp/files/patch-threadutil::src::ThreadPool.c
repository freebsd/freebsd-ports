--- threadutil/src/ThreadPool.c.orig	Sat Apr  5 23:20:04 2003
+++ threadutil/src/ThreadPool.c	Sat Apr  5 23:20:47 2003
@@ -341,7 +341,7 @@
     struct timeb t;
 
     ftime( &t );
-    srand( ( unsigned int )t.millitm + ithread_get_current_thread_id(  ) );
+    srand( ( unsigned int )t.millitm + ( unsigned int )ithread_get_current_thread_id(  ) );
     }
 
 /****************************************************************************
@@ -1455,7 +1455,7 @@
                assert( stats != NULL ); if( stats == NULL ) {
                return;}
 
-               printf( "ThreadPoolStats at Time: %ld\n", time( NULL ) );
+               printf( "ThreadPoolStats at Time: %lf\n", time( NULL ) );
                printf
                ( "Average Wait in High Priority Q in milliseconds: %lf\n",
                  stats->avgWaitHQ );
