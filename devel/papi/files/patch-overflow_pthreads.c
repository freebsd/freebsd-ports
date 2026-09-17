--- ctests/overflow_pthreads.c.orig	2024-08-30 16:22:20.000000000 -0400
+++ ctests/overflow_pthreads.c	2025-02-04 05:49:18.455323000 -0500
@@ -73,7 +73,7 @@
 	/* Wait, we're indexing a per-thread array with the EventSet number? */
 	/* does that make any sense at all???? -- vmw                        */
 	expected[EventSet1] = *( int * ) arg / mythreshold;
-	myid[EventSet1] = PAPI_thread_id(  );
+	myid[EventSet1] = (pthread_t)PAPI_thread_id(  );
 
 	values = allocate_test_space( num_tests, num_events1 );
 
