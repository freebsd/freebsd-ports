
$FreeBSD$

--- fdstream.cc	2002/02/05 13:27:38	1.1
+++ fdstream.cc	2002/02/05 13:35:40
@@ -19,6 +19,8 @@
 #include "fdstream.h"
 
 #include <sys/types.h>
+#include <errno.h>
+#include <string.h>
 #include <unistd.h>
 
 namespace {
@@ -96,7 +98,7 @@
     return (num_written == count) ? 0 : -1;
 }
 
-fdstreambuf::int_type fdstreambuf::underflow()
+int fdstreambuf::underflow()
 {
     // Is the buffer already empty yet?
     char *tmp_gptr = gptr();
@@ -104,7 +106,8 @@
 
         char *tmp_eback = eback();
         const std::size_t num_putback =
-            std::min <std::size_t> (tmp_gptr - tmp_eback, pback_end_ - buf);
+            (tmp_gptr - tmp_eback >  pback_end_ - buf) ? pback_end_ - buf :
+	    tmp_gptr - tmp_eback;
 
         // Fill putback area.
         tmp_eback = pback_end_ - num_putback;
@@ -132,7 +135,7 @@
 
     // First, empty the current buffer.
     const std::size_t buf_avail = tmp_egptr - tmp_gptr;
-    std::streamsize   idx       = std::min <std::size_t> (buf_avail, count);
+    std::streamsize   idx       = (buf_avail > count) ? count : buf_avail;
 
     std::memcpy (dest, tmp_gptr, idx);
 
@@ -149,7 +152,7 @@
     if (tmp_gptr >= pback_end_) {
 
         const std::size_t num_putback =
-	    std::min <std::size_t> (idx, pback_end_ - buf);
+	    (idx > pback_end_ - buf) ? pback_end_ - buf : idx;
 
         tmp_eback = pback_end_ - num_putback;
         std::memcpy (tmp_eback, dest + idx - num_putback, num_putback);
@@ -185,7 +188,7 @@
     return (fd >= 0) ? flush() : -1;
 }
 
-fdstreambuf::int_type fdstreambuf::overflow (fdstreambuf::int_type c)
+int fdstreambuf::overflow (int c)
 {
     if (c != EOF) {
         *pptr() = int_to_char (c);
