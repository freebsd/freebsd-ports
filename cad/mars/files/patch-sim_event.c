--- sim/event.c.orig	2007-11-23 21:54:37.000000000 +0100
+++ sim/event.c	2007-11-23 21:55:23.000000000 +0100
@@ -433,14 +433,13 @@
    I'm just using the stack to store a list of events that must be
    deleted, rather than creating my own list/array/whatever.
 */
-
+static void ev_dequeue_by_comp_and_type1();
 void
 ev_dequeue_by_comp_and_type(src, dest, type)
 
 Component	*src, *dest;
 Evtype		type;
 {
-    static void ev_dequeue_by_comp_and_type1();
     ev_dequeue_by_comp_and_type1(src, dest, type,
 				 (Event *)heap_iter_init(event_queue));
 }
@@ -476,13 +475,11 @@
    I'm just using the stack to store a list of events that must be
    deleted, rather than creating my own list/array/whatever.
 */
-
+static void ev_dequeue_by_time1();
 void
 ev_dequeue_by_time(t)
      tick_t t;
 {
-    static void ev_dequeue_by_time1();
-
     ev_dequeue_by_time1(t, (Event *)heap_iter_init(event_queue));
 }
 
