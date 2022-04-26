--- ext/io/event/selector/kqueue.c.orig	2022-02-17 10:31:43 UTC
+++ ext/io/event/selector/kqueue.c
@@ -190,7 +190,7 @@ int process_add_filters(int descriptor, int ident, VAL
 	
 	event.ident = ident;
 	event.filter = EVFILT_PROC;
-	event.flags = EV_ADD | EV_ENABLE | EV_ONESHOT | EV_UDATA_SPECIFIC;
+	event.flags = EV_ADD | EV_ENABLE | EV_ONESHOT;
 	event.fflags = NOTE_EXIT;
 	event.udata = (void*)fiber;
 	
@@ -214,7 +214,7 @@ void process_remove_filters(int descriptor, int ident)
 	
 	event.ident = ident;
 	event.filter = EVFILT_PROC;
-	event.flags = EV_DELETE | EV_UDATA_SPECIFIC;
+	event.flags = EV_DELETE;
 	event.fflags = NOTE_EXIT;
 	
 	// Ignore the result.
@@ -273,7 +273,7 @@ int io_add_filters(int descriptor, int ident, int even
 	if (events & IO_EVENT_READABLE) {
 		kevents[count].ident = ident;
 		kevents[count].filter = EVFILT_READ;
-		kevents[count].flags = EV_ADD | EV_ENABLE | EV_ONESHOT | EV_UDATA_SPECIFIC;
+		kevents[count].flags = EV_ADD | EV_ENABLE | EV_ONESHOT;
 		kevents[count].udata = (void*)fiber;
 		
 // #ifdef EV_OOBAND
@@ -288,7 +288,7 @@ int io_add_filters(int descriptor, int ident, int even
 	if (events & IO_EVENT_WRITABLE) {
 		kevents[count].ident = ident;
 		kevents[count].filter = EVFILT_WRITE;
-		kevents[count].flags = EV_ADD | EV_ENABLE | EV_ONESHOT | EV_UDATA_SPECIFIC;
+		kevents[count].flags = EV_ADD | EV_ENABLE | EV_ONESHOT;
 		kevents[count].udata = (void*)fiber;
 		count++;
 	}
@@ -310,7 +310,7 @@ void io_remove_filters(int descriptor, int ident, int 
 	if (events & IO_EVENT_READABLE) {
 		kevents[count].ident = ident;
 		kevents[count].filter = EVFILT_READ;
-		kevents[count].flags = EV_DELETE | EV_UDATA_SPECIFIC;
+		kevents[count].flags = EV_DELETE;
 		
 		count++;
 	}
@@ -318,7 +318,7 @@ void io_remove_filters(int descriptor, int ident, int 
 	if (events & IO_EVENT_WRITABLE) {
 		kevents[count].ident = ident;
 		kevents[count].filter = EVFILT_WRITE;
-		kevents[count].flags = EV_DELETE | EV_UDATA_SPECIFIC;
+		kevents[count].flags = EV_DELETE;
 		count++;
 	}
 	
@@ -695,7 +695,7 @@ VALUE IO_Event_Selector_KQueue_wakeup(VALUE self) {
 		struct kevent trigger = {0};
 		
 		trigger.filter = EVFILT_USER;
-		trigger.flags = EV_ADD | EV_CLEAR | EV_UDATA_SPECIFIC;
+		trigger.flags = EV_ADD | EV_CLEAR;
 		trigger.fflags = NOTE_TRIGGER;
 		
 		int result = kevent(data->descriptor, &trigger, 1, NULL, 0, NULL);
