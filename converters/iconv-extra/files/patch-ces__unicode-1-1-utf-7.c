Index: ces/unicode-1-1-utf-7.c
===================================================================
RCS file: /home/bbcvs/iconv/ces/unicode-1-1-utf-7.c,v
retrieving revision 1.2
--- ces/unicode-1-1-utf-7.c.orig	2024-06-07 14:57:13 UTC
+++ ces/unicode-1-1-utf-7.c
@@ -33,7 +33,7 @@
 #include <stdlib.h>
 
 #define ICONV_INTERNAL
-#include <iconv.h>
+#include <biconv.h>
 
 static inline int
 lackofbytes(int bytes, size_t *bytesleft)
@@ -230,7 +230,7 @@ static ucs_t convert_to_ucs(struct iconv_ces *module,
             if (*inbytesleft < 2)
                 return UCS_CHAR_NONE;
             needbytes = 1;
-            ch = char_type(*(++((unsigned char *)*inbuf)));
+            ch = char_type(*(++*inbuf));
             (*inbytesleft) --;
         case utf7_printable:
             utf7_state[0] = 0;
@@ -246,7 +246,7 @@ static ucs_t convert_to_ucs(struct iconv_ces *module,
             (*inbytesleft) += needbytes;
             return UCS_CHAR_NONE;
         }
-        switch (char_type(*(++(unsigned char *)*inbuf))) {
+        switch (char_type(*(++*inbuf))) {
         case utf7_shift_out:
             (*inbuf) ++;
             (*inbytesleft) -= 2;
@@ -264,7 +264,7 @@ static ucs_t convert_to_ucs(struct iconv_ces *module,
         return UCS_CHAR_INVALID;
     }
     (*inbytesleft) --;
-    return *((unsigned char *)*inbuf) ++;
+    return *(*inbuf)++;
 #undef utf7_state
 }
 
