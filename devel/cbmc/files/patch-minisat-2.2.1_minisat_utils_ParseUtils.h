--- minisat-2.2.1/minisat/utils/ParseUtils.h.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/utils/ParseUtils.h
@@ -24,7 +24,7 @@ OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OT
 #include <stdlib.h>
 #include <stdio.h>
 
-#include <zlib.h>
+//#include <zlib.h>
 
 namespace Minisat {
 
@@ -35,7 +35,7 @@ class StreamBuffer {
 
 
 class StreamBuffer {
-    gzFile        in;
+    //gzFile        in;
     unsigned char buf[buffer_size];
     int           pos;
     int           size;
@@ -43,10 +43,10 @@ class StreamBuffer {
     void assureLookahead() {
         if (pos >= size) {
             pos  = 0;
-            size = gzread(in, buf, sizeof(buf)); } }
+            /*size = gzread(in, buf, sizeof(buf));*/ } }
 
 public:
-    explicit StreamBuffer(gzFile i) : in(i), pos(0), size(0) { assureLookahead(); }
+    //explicit StreamBuffer(gzFile i) : in(i), pos(0), size(0) { assureLookahead(); }
 
     int  operator *  () const { return (pos >= size) ? EOF : buf[pos]; }
     void operator ++ ()       { pos++; assureLookahead(); }
