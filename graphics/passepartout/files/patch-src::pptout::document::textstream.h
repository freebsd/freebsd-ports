--- src/pptout/document/textstream.h.orig	Thu Dec  4 10:27:38 2003
+++ src/pptout/document/textstream.h	Thu Dec  4 10:46:07 2003
@@ -90,6 +90,7 @@
   std::map<const TextFrame*, unsigned int> pageno_map;
   
   class WorkerThread;
+  friend class WorkerThread;
   Glib::RefPtr<WorkerThread> typesetter_thread;
   
   // Undefined ctors, avoid defaults
