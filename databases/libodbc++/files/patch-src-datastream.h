--- src/datastream.h.orig	Wed Jun  2 12:44:31 2004
+++ src/datastream.h	Wed Jun  2 12:51:48 2004
@@ -63,7 +63,13 @@
       return 0;
     }
     
-    virtual int showmanyc() {
+    virtual
+#if !defined(ODBCXX_HAVE_ISO_CXXLIB) 
+    int
+#else
+    std::streamsize
+#endif
+    showmanyc() {
       if(this->gptr() < this->egptr()) {
 	return this->egptr() - this->gptr();
       }
