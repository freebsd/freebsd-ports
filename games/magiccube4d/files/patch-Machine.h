--- Machine.h.orig	Sat Dec 30 23:43:10 2006
+++ Machine.h	Sat Dec 30 23:43:24 2006
@@ -31,7 +31,7 @@
 {
 public:
     typedef void (EventHandler::*event_handler)(EventHandler::Event*,
-                                                void *arg = 0);
+                                                void *arg);
     virtual ~Machine() {};
 
     static Machine* createMachine(EventHandler*, int& argc, char *argv[],
