--- src/codec.c.orig	2013-07-17 08:09:12 UTC
+++ src/codec.c
@@ -28,7 +28,7 @@ typedef struct {
     char fmt[7];
 } Fmt;
 
-inline int fmt_size(Fmt *fmt) {
+static inline int fmt_size(Fmt *fmt) {
     return sizeof(Fmt) + strlen(fmt->fmt) - 7 + 1;
 }
 
