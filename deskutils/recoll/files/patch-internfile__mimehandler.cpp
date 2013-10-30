--- ./internfile/mimehandler.cpp.orig	2013-09-30 18:45:06.000000000 +0200
+++ ./internfile/mimehandler.cpp	2013-10-29 15:57:51.000000000 +0100
@@ -127,7 +127,7 @@
 {
     LOGDEB(("clearMimeHandlerCache()\n"));
     typedef multimap<string, RecollFilter*>::value_type value_type;
-    map<string, RecollFilter *>::iterator it;
+    multimap<string, RecollFilter *>::iterator it;
     PTMutexLocker locker(o_handlers_mutex);
     for (it = o_handlers.begin(); it != o_handlers.end(); it++) {
 	delete it->second;
