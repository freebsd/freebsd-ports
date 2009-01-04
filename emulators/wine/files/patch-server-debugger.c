diff --git a/server/debugger.c b/server/debugger.c
index a865ebb..d8d425d 100644
--- server/debugger.c
+++ server/debugger.c
@@ -129,7 +129,7 @@ static int fill_create_thread_event( struct debug_event *event, const void *arg
     if (!(handle = alloc_handle( debugger, thread, THREAD_ALL_ACCESS, 0 ))) return 0;
     event->data.info.create_thread.handle = handle;
     event->data.info.create_thread.teb    = thread->teb;
-    event->data.info.create_thread.start  = *entry;
+    if (entry) event->data.info.create_thread.start = *entry;
     return 1;
 }
 
@@ -389,6 +389,7 @@ static struct debug_event *alloc_debug_event( struct thread *thread, int code,
     event->state     = EVENT_QUEUED;
     event->sender    = (struct thread *)grab_object( thread );
     event->debugger  = (struct thread *)grab_object( debugger );
+    memset( &event->data, 0, sizeof(event->data) );
     event->data.code = code;
 
     if (!fill_debug_event[code-1]( event, arg ))
