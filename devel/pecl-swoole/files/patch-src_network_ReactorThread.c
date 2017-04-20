--- src/network/ReactorThread.c.orig	2017-04-20 02:12:07 UTC
+++ src/network/ReactorThread.c
@@ -1263,7 +1263,6 @@ int swReactorThread_dispatch(swConnectio
 #ifdef SW_USE_RINGBUFFER
     swServer *serv = SwooleG.serv;
     swReactorThread *thread = swServer_get_thread(serv, SwooleTG.id);
-    int target_worker_id = swServer_worker_schedule(serv, conn->fd);
 
     swPackage package;
     package.length = length;
@@ -1271,11 +1270,11 @@ int swReactorThread_dispatch(swConnectio
 
     task.data.info.type = SW_EVENT_PACKAGE;
     task.data.info.len = sizeof(package);
-    task.target_worker_id = target_worker_id;
 
-    //swoole_dump_bin(package.data, 's', buffer->length);
     memcpy(package.data, data, package.length);
     memcpy(task.data.data, &package, sizeof(package));
+    
+    task.target_worker_id = swServer_worker_schedule(serv, conn->fd, &task.data);
 
     //dispatch failed, free the memory.
     if (factory->dispatch(factory, &task) < 0)
@@ -1335,92 +1334,6 @@ int swReactorThread_dispatch(swConnectio
     return SW_OK;
 }
 
-#if 0
-int swReactorThread_dispatch_array_buffer(swReactorThread *thread, swConnection *conn)
-{
-    swDispatchData task;
-    swFactory *factory = SwooleG.factory;
-
-    task.data.info.fd = conn->fd;
-    task.data.info.from_id = conn->from_id;
-
-    swBuffer *buffer = conn->in_buffer;
-    swBuffer_trunk *trunk = swBuffer_get_trunk(buffer);
-
-#ifdef SW_USE_RINGBUFFER
-    swServer *serv = SwooleG.serv;
-    uint16_t target_worker_id = swServer_worker_schedule(serv, conn->fd);
-    swPackage package;
-
-    package.length = 0;
-    package.data = swReactorThread_alloc(thread, buffer->length);
-
-    task.data.info.type = SW_EVENT_PACKAGE;
-
-    while (trunk != NULL)
-    {
-        task.data.info.len = trunk->length;
-        memcpy(package.data + package.length, trunk->store.ptr, trunk->length);
-        package.length += trunk->length;
-
-        swBuffer_pop_trunk(buffer, trunk);
-        trunk = swBuffer_get_trunk(buffer);
-    }
-    task.data.info.len = sizeof(package);
-    task.target_worker_id = target_worker_id;
-    memcpy(task.data.data, &package, sizeof(package));
-    //swWarn("[ReactorThread] copy_n=%d", package.length);
-    //dispatch failed, free the memory.
-    if (factory->dispatch(factory, &task) < 0)
-    {
-        thread->buffer_input->free(thread->buffer_input, package.data);
-    }
-    else
-    {
-        return SW_OK;
-    }
-#else
-    int ret;
-    task.data.info.type = SW_EVENT_PACKAGE_START;
-    task.target_worker_id = -1;
-
-    /**
-     * lock target
-     */
-    SwooleTG.factory_lock_target = 1;
-
-    while (trunk != NULL)
-    {
-        task.data.info.fd = conn->fd;
-        task.data.info.len = trunk->length;
-        memcpy(task.data.data, trunk->store.ptr, task.data.info.len);
-        //package end
-        if (trunk->next == NULL)
-        {
-            task.data.info.type = SW_EVENT_PACKAGE_END;
-        }
-        ret = factory->dispatch(factory, &task);
-        //TODO: 处理数据失败，数据将丢失
-        if (ret < 0)
-        {
-            swWarn("factory->dispatch() failed.");
-        }
-        swBuffer_pop_trunk(buffer, trunk);
-        trunk = swBuffer_get_trunk(buffer);
-
-        swTrace("send2worker[trunk_num=%d][type=%d]", buffer->trunk_num, task.data.info.type);
-    }
-    /**
-     * unlock
-     */
-    SwooleTG.factory_target_worker = -1;
-    SwooleTG.factory_lock_target = 0;
-
-#endif
-    return SW_OK;
-}
-#endif
-
 void swReactorThread_free(swServer *serv)
 {
     int i;
