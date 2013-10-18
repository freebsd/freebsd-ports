--- src/io/xsltstream.h.orig	2011-07-08 20:25:09.468790000 +0200
+++ src/io/xsltstream.h	2013-10-17 13:10:26.000000000 +0200
@@ -38,7 +38,7 @@
     /**
      * Constructor with loading
      */
-    XsltStyleSheet(InputStream &source)  throw (StreamException);
+    XsltStyleSheet(InputStream &source);
 
     /**
      * Simple constructor, no loading
@@ -73,16 +73,15 @@
 
 public:
 
-    XsltInputStream(InputStream &xmlSource, XsltStyleSheet &stylesheet)
-                        throw (StreamException);
+    XsltInputStream(InputStream &xmlSource, XsltStyleSheet &stylesheet);
     
-    virtual ~XsltInputStream() throw (StreamException);
+    virtual ~XsltInputStream();
     
-    virtual int available() throw (StreamException);
+    virtual int available();
     
-    virtual void close() throw (StreamException);
+    virtual void close();
     
-    virtual int get() throw (StreamException);
+    virtual int get();
     
 
 private:
@@ -110,16 +109,15 @@
 
 public:
 
-    XsltOutputStream(OutputStream &destination, XsltStyleSheet &stylesheet)
-                             throw (StreamException);
+    XsltOutputStream(OutputStream &destination, XsltStyleSheet &stylesheet);
     
-    virtual ~XsltOutputStream() throw (StreamException);
+    virtual ~XsltOutputStream();
     
-    virtual void close() throw (StreamException);
+    virtual void close();
     
-    virtual void flush() throw (StreamException);
+    virtual void flush();
     
-    virtual void put(int ch) throw (StreamException);
+    virtual void put(int ch);
 
 private:
 
