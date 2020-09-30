--- inc/position.h.orig	2018-09-08 19:56:33 UTC
+++ inc/position.h
@@ -52,7 +52,7 @@ typedef union _position
     guint32 val;
 } position;
 
-const position pos_invalid;
+extern const position pos_invalid;
 
 typedef struct _rectangle
 {
