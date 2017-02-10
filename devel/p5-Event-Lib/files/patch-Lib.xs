--- Lib.xs.orig	2007-07-29 11:02:37 UTC
+++ Lib.xs
@@ -125,6 +125,11 @@ void free_args (struct event_args *args)
     Safefree(args);
 }
 
+#if LIBEVENT_VERSION_NUMBER > 0x02010101
+// From event-internal.h
+#define ev_arg ev_evcallback.evcb_arg
+#endif
+
 void refresh_event (struct event_args *args, char *class) {
     SV *sv = newSV(0);
     sv_setref_pv(sv, class, (void*)args);
