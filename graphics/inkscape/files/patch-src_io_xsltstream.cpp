--- src/io/xsltstream.cpp.orig	2013-10-16 23:56:16.000000000 +0200
+++ src/io/xsltstream.cpp	2013-10-17 11:59:55.000000000 +0200
@@ -30,7 +30,6 @@
  *
  */
 XsltStyleSheet::XsltStyleSheet(InputStream &xsltSource)
-               throw (StreamException)
                    : stylesheet(NULL)
 {
     if (!read(xsltSource)) {
@@ -86,7 +85,6 @@
  *
  */ 
 XsltInputStream::XsltInputStream(InputStream &xmlSource, XsltStyleSheet &sheet)
-                        throw (StreamException)
                         : BasicInputStream(xmlSource), stylesheet(sheet)
 {
     //Load the data
@@ -110,7 +108,7 @@
 /**
  *
  */ 
-XsltInputStream::~XsltInputStream() throw (StreamException)
+XsltInputStream::~XsltInputStream()
 {
     xmlFree(outbuf);
 }
@@ -120,7 +118,7 @@
  * this input stream without blocking by the next caller of a method for
  * this input stream.
  */ 
-int XsltInputStream::available() throw (StreamException)
+int XsltInputStream::available()
 {
     return outsize - outpos;
 }
@@ -130,7 +128,7 @@
  *  Closes this input stream and releases any system resources
  *  associated with the stream.
  */ 
-void XsltInputStream::close() throw (StreamException)
+void XsltInputStream::close()
 {
     closed = true;
 }
@@ -138,7 +136,7 @@
 /**
  * Reads the next byte of data from the input stream.  -1 if EOF
  */ 
-int XsltInputStream::get() throw (StreamException)
+int XsltInputStream::get()
 {
     if (closed)
         return -1;
@@ -161,7 +159,6 @@
  *
  */ 
 XsltOutputStream::XsltOutputStream(OutputStream &dest, XsltStyleSheet &sheet)
-                     throw (StreamException)
                      : BasicOutputStream(dest), stylesheet(sheet)
 {
     flushed = false;
@@ -170,7 +167,7 @@
 /**
  *
  */ 
-XsltOutputStream::~XsltOutputStream() throw (StreamException)
+XsltOutputStream::~XsltOutputStream()
 {
     //do not automatically close
 }
@@ -179,7 +176,7 @@
  * Closes this output stream and releases any system resources
  * associated with this stream.
  */ 
-void XsltOutputStream::close() throw (StreamException)
+void XsltOutputStream::close()
 {
     flush();
     destination.close();
@@ -189,7 +186,7 @@
  *  Flushes this output stream and forces any buffered output
  *  bytes to be written out.
  */ 
-void XsltOutputStream::flush() throw (StreamException)
+void XsltOutputStream::flush()
 {
     if (flushed)
         {
@@ -230,7 +227,7 @@
 /**
  * Writes the specified byte to this output stream.
  */ 
-void XsltOutputStream::put(int ch) throw (StreamException)
+void XsltOutputStream::put(int ch)
 {
     gunichar uch = (gunichar) ch;
     outbuf.push_back(uch);
