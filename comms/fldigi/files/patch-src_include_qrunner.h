--- src/include/qrunner.h.orig	2013-11-17 20:26:40.966731568 -0500
+++ src/include/qrunner.h	2013-11-18 18:52:20.902610641 -0500
@@ -64,9 +64,10 @@
         qexception(const char *msg_) : msg(msg_) { }
         qexception(int e) : msg(strerror(e)) { }
         ~qexception() throw() { }
-        const char *what(void) const throw() { return msg.c_str(); }
+        const char *what(void) const throw() { return msg; }
 private:
-        std::string msg;
+//        std::string msg;
+	const char *msg;
 };
 
 struct fsignal
