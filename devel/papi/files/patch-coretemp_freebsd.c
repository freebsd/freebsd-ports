--- components/coretemp_freebsd/coretemp_freebsd.c.orig	2013-08-06 20:12:19.000000000 +0400
+++ components/coretemp_freebsd/coretemp_freebsd.c	2013-11-11 01:15:20.000000000 +0400
@@ -140,6 +140,9 @@
 		ret = sysctlnametomib (tmp, mib, &len);
 	}
 
+	if (CORETEMP_NUM_EVENTS == 0)
+		return PAPI_OK;
+
 	/* Allocate memory for the our event table */
 	coretemp_native_table = (coretemp_native_event_entry_t *)
 		papi_malloc (sizeof (coretemp_native_event_entry_t) * CORETEMP_NUM_EVENTS);
@@ -377,7 +380,7 @@
 int coretemp_shutdown_component (void)
 {
 
-	SUBDBG( "coretemp_shutdown_component... %p\n", ctx );
+	SUBDBG( "coretemp_shutdown_component...\n");
 
 	/* Last chance to clean up */
 	papi_free (coretemp_native_table);
