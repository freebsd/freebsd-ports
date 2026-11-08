--- src/undead/stream.d.orig	2026-09-29 12:09:09 UTC
+++ src/undead/stream.d
@@ -230,7 +230,9 @@ interface InputStream {
    * --------------------------
    */
   int vreadf(TypeInfo[] arguments, va_list args);
-  int readf(...); /// ditto
+  final int readf(...) { /// ditto
+    return vreadf(_arguments, _argptr);
+  }
 
   /// Retrieve the number of bytes available for immediate reading.
   @property size_t available();
@@ -333,7 +335,13 @@ interface OutputStream {
    * returning the number of bytes written.
    */
   size_t vprintf(const(char)[] format, va_list args);
-  size_t printf(const(char)[] format, ...);    /// ditto
+  final size_t printf(const(char)[] format, ...) {    /// ditto
+    va_list ap;
+    va_start(ap, format);
+    auto result = vprintf(format, ap);
+    va_end(ap);
+    return result;
+  }
 
   /***
    * Print a formatted string into the stream using writef-style syntax.
@@ -343,8 +351,12 @@ interface OutputStream {
    * NOTE: not supported in GDC, since it uses features unimplemented in that
    * compiler.
    */
-  OutputStream writef(...);
-  OutputStream writefln(...); /// ditto
+  final OutputStream writef(...) {
+    return writefx(_arguments,_argptr,0);
+  }
+  final OutputStream writefln(...) { /// ditto
+    return writefx(_arguments,_argptr,1);
+  }
   OutputStream writefx(TypeInfo[] arguments, va_list argptr, int newline = false);  /// ditto
 
   void flush(); /// Flush pending output if appropriate.
@@ -1051,10 +1063,6 @@ class Stream : InputStream, OutputStream {
     return count;
   }
 
-  int readf(...) {
-    return vreadf(_arguments, _argptr);
-  }
-
   // returns estimated number of bytes available for immediate reading
   @property size_t available() { return 0; }
 
@@ -1181,30 +1189,10 @@ class Stream : InputStream, OutputStream {
     return count;
   }
 
-  // writes data to stream using printf() syntax,
-  // returns number of bytes written
-  size_t printf(const(char)[] format, ...) {
-    va_list ap;
-    va_start(ap, format);
-    auto result = vprintf(format, ap);
-    va_end(ap);
-    return result;
-  }
-
   private void doFormatCallback(dchar c) {
     char[4] buf;
     auto b = undead.utf.toUTF8(buf, c);
     writeString(b);
-  }
-
-  // writes data to stream using writef() syntax,
-  OutputStream writef(...) {
-    return writefx(_arguments,_argptr,0);
-  }
-
-  // writes data with trailing newline
-  OutputStream writefln(...) {
-    return writefx(_arguments,_argptr,1);
   }
 
   // writes data with optional trailing newline
