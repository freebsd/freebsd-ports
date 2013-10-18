--- src/io/uristream.h.orig	2013-10-16 23:43:05.000000000 +0200
+++ src/io/uristream.h	2013-10-16 23:55:31.000000000 +0200
@@ -35,17 +35,17 @@
 {
 
 public:
-    UriInputStream(FILE *source, Inkscape::URI &uri) throw(StreamException);
+    UriInputStream(FILE *source, Inkscape::URI &uri);
 
-    UriInputStream(Inkscape::URI &source) throw(StreamException);
+    UriInputStream(Inkscape::URI &source);
 
-    virtual ~UriInputStream() throw(StreamException);
+    virtual ~UriInputStream();
 
-    virtual int available() throw(StreamException);
+    virtual int available();
 
-    virtual void close() throw(StreamException);
+    virtual void close();
 
-    virtual int get() throw(StreamException);
+    virtual int get();
 
 private:
 
@@ -74,15 +74,15 @@
 
 public:
 
-    UriReader(Inkscape::URI &source) throw(StreamException);
+    UriReader(Inkscape::URI &source);
 
-    virtual ~UriReader() throw(StreamException);
+    virtual ~UriReader();
 
-    virtual int available() throw(StreamException);
+    virtual int available();
 
-    virtual void close() throw(StreamException);
+    virtual void close();
 
-    virtual gunichar get() throw(StreamException);
+    virtual gunichar get();
 
 private:
 
@@ -106,17 +106,17 @@
 
 public:
 
-    UriOutputStream(FILE *fp, Inkscape::URI &destination) throw(StreamException);
+    UriOutputStream(FILE *fp, Inkscape::URI &destination);
 
-    UriOutputStream(Inkscape::URI &destination) throw(StreamException);
+    UriOutputStream(Inkscape::URI &destination);
 
-    virtual ~UriOutputStream() throw(StreamException);
+    virtual ~UriOutputStream();
 
-    virtual void close() throw(StreamException);
+    virtual void close();
 
-    virtual void flush() throw(StreamException);
+    virtual void flush();
 
-    virtual void put(int ch) throw(StreamException);
+    virtual void put(int ch);
 
 private:
 
@@ -145,15 +145,15 @@
 
 public:
 
-    UriWriter(Inkscape::URI &source) throw(StreamException);
+    UriWriter(Inkscape::URI &source);
 
-    virtual ~UriWriter() throw(StreamException);
+    virtual ~UriWriter();
 
-    virtual void close() throw(StreamException);
+    virtual void close();
 
-    virtual void flush() throw(StreamException);
+    virtual void flush();
 
-    virtual void put(gunichar ch) throw(StreamException);
+    virtual void put(gunichar ch);
 
 private:
 
