$FreeBSD$

--- jmp.c	Tue May 13 23:17:03 2003
+++ jmp.c	Tue May 13 23:17:47 2003
@@ -1548,10 +1548,11 @@
     free (cf);
 }
 
-void enable_method_events () {
+void enable_method_events_and_stacks (int get_stacks) {
     /* Ok, the thread stacks are bogous, clear them all and try to get 
      * real stacks, timing will be a bit bogous, but not to much...
      */
+    if (get_stacks) {
     jmphash_lock (threads);
     jmphash_lock (methods);
     jvmpi->DisableGC ();
@@ -1559,6 +1560,7 @@
     jvmpi->EnableGC ();
     jmphash_unlock (methods);
     jmphash_unlock (threads);
+    }
 
     method_profiling = 1;
     /*
@@ -1572,6 +1574,10 @@
     jvmpi->EnableEvent (JVMPI_EVENT_METHOD_EXIT, NULL);
 }
 
+void enable_method_events () {
+    enable_method_events_and_stacks (1);
+}
+
 static void enable_dump_events () {
     dump_enabled = 1;
     jvmpi->EnableEvent (JVMPI_EVENT_DATA_DUMP_REQUEST, NULL);
@@ -1603,7 +1609,7 @@
 	enable_object_events ();
     enable_thread_events ();
     if (method_profiling)     
-	enable_method_events ();
+	enable_method_events_and_stacks (0);
     if (dump_enabled)
 	enable_dump_events ();
     if (monitor_profiling)
