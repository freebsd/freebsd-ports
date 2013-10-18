--- src/io/uristream.cpp.orig	2011-07-08 20:25:09.468790000 +0200
+++ src/io/uristream.cpp	2013-10-17 13:09:15.000000000 +0200
@@ -104,7 +104,7 @@
  *
  */
 UriInputStream::UriInputStream(Inkscape::URI &source)
-                    throw (StreamException): uri(source)
+                    : uri(source)
 {
     //get information from uri
     char const *schemestr = uri.getScheme();
@@ -146,7 +146,7 @@
  *
  */
 UriInputStream::UriInputStream(FILE *source, Inkscape::URI &uri)
-    throw (StreamException): inf(source),
+    : inf(source),
                              uri(uri)
 {
     scheme = SCHEME_FILE;
@@ -160,7 +160,7 @@
 /**
  *
  */
-UriInputStream::~UriInputStream() throw(StreamException)
+UriInputStream::~UriInputStream()
 {
     close();
 }
@@ -170,7 +170,7 @@
  * this input stream without blocking by the next caller of a method for
  * this input stream.
  */
-int UriInputStream::available() throw(StreamException)
+int UriInputStream::available()
 {
     return 0;
 }
@@ -180,7 +180,7 @@
  *  Closes this input stream and releases any system resources
  *  associated with the stream.
  */
-void UriInputStream::close() throw(StreamException)
+void UriInputStream::close()
 {
     if (closed)
         return;
@@ -207,7 +207,7 @@
 /**
  * Reads the next byte of data from the input stream.  -1 if EOF
  */
-int UriInputStream::get() throw(StreamException)
+int UriInputStream::get()
 {
     int retVal = -1;
     if (!closed)
@@ -249,7 +249,6 @@
  *
  */
 UriReader::UriReader(Inkscape::URI &uri)
-                    throw (StreamException)
 {
     inputStream = new UriInputStream(uri);
 }
@@ -257,7 +256,7 @@
 /**
  *
  */
-UriReader::~UriReader() throw (StreamException)
+UriReader::~UriReader()
 {
     delete inputStream;
 }
@@ -265,7 +264,7 @@
 /**
  *
  */
-int UriReader::available() throw(StreamException)
+int UriReader::available()
 {
     return inputStream->available();
 }
@@ -273,7 +272,7 @@
 /**
  *
  */
-void UriReader::close() throw(StreamException)
+void UriReader::close()
 {
     inputStream->close();
 }
@@ -281,8 +280,7 @@
 /**
  *
  */
-gunichar UriReader::get() throw(StreamException)
-{
+gunichar UriReader::get(){
     gunichar ch = (gunichar)inputStream->get();
     return ch;
 }
@@ -296,7 +294,7 @@
  * Temporary kludge
  */
 UriOutputStream::UriOutputStream(FILE* fp, Inkscape::URI &destination)
-                    throw (StreamException): closed(false),
+                    : closed(false),
                                              ownsFile(false),
                                              outf(fp),
                                              uri(destination),
@@ -312,7 +310,7 @@
  *
  */
 UriOutputStream::UriOutputStream(Inkscape::URI &destination)
-                    throw (StreamException): closed(false),
+                    : closed(false),
                                              ownsFile(true),
                                              outf(NULL),
                                              uri(destination),
@@ -353,7 +351,7 @@
 /**
  *
  */
-UriOutputStream::~UriOutputStream() throw(StreamException)
+UriOutputStream::~UriOutputStream()
 {
     close();
 }
@@ -362,7 +360,7 @@
  * Closes this output stream and releases any system resources
  * associated with this stream.
  */
-void UriOutputStream::close() throw(StreamException)
+void UriOutputStream::close()
 {
     if (closed)
         return;
@@ -391,7 +389,7 @@
  *  Flushes this output stream and forces any buffered output
  *  bytes to be written out.
  */
-void UriOutputStream::flush() throw(StreamException)
+void UriOutputStream::flush()
 {
     if (closed)
         return;
@@ -415,7 +413,7 @@
 /**
  * Writes the specified byte to this output stream.
  */
-void UriOutputStream::put(int ch) throw(StreamException)
+void UriOutputStream::put(int ch)
 {
     if (closed)
         return;
@@ -453,7 +451,6 @@
  *
  */
 UriWriter::UriWriter(Inkscape::URI &uri)
-                    throw (StreamException)
 {
     outputStream = new UriOutputStream(uri);
 }
@@ -461,7 +458,7 @@
 /**
  *
  */
-UriWriter::~UriWriter() throw (StreamException)
+UriWriter::~UriWriter()
 {
     delete outputStream;
 }
@@ -469,7 +466,7 @@
 /**
  *
  */
-void UriWriter::close() throw(StreamException)
+void UriWriter::close()
 {
     outputStream->close();
 }
@@ -477,7 +474,7 @@
 /**
  *
  */
-void UriWriter::flush() throw(StreamException)
+void UriWriter::flush()
 {
     outputStream->flush();
 }
@@ -485,7 +482,7 @@
 /**
  *
  */
-void UriWriter::put(gunichar ch) throw(StreamException)
+void UriWriter::put(gunichar ch)
 {
     int ich = (int)ch;
     outputStream->put(ich);
