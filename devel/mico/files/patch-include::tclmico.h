--- tclmico.h.orig	Mon May 26 14:55:46 2003
+++ include/mico/tclmico.h	Sun Jun 29 02:25:42 2003
@@ -32,6 +32,10 @@
 #include <tcl.h>
 #endif
 
+using std::list;
+using std::set;
+using std::less;
+
 class TclDispatcher : public CORBA::Dispatcher {
 
     struct FileEvent {
