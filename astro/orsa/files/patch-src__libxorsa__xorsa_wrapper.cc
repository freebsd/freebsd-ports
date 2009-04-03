--- src/libxorsa/xorsa_wrapper.cc.orig	2005-01-06 07:07:56.000000000 +0900
+++ src/libxorsa/xorsa_wrapper.cc	2009-04-02 13:48:37.000000000 +0900
@@ -148,9 +148,9 @@
 {
   if (doDefaultOutput) inherited::vtrace(fmt, ap);
   char str[1024];
-  std::vsnprintf(str, sizeof(str) - 1, fmt, ap);
+  vsnprintf(str, sizeof(str) - 1, fmt, ap);
   char msg[1024];
-  std::snprintf(msg, sizeof(msg) - 1, "[%s][%s:%i] %s %s\n", 
+  snprintf(msg, sizeof(msg) - 1, "[%s][%s:%i] %s %s\n", 
     QTime::currentTime(Qt::LocalTime).toString("hh:mm:ss").latin1(),d->file,d->line, d->msg.c_str(), str);
   QString s = msg;
   XOrsaDebugEvent *de = new XOrsaDebugEvent(s);
