--- inc/position.h.orig	2020-05-23 06:13:27 UTC
+++ inc/position.h
@@ -52,8 +52,6 @@ typedef union _position
     guint32 val;
 } position;
 
-const position pos_invalid;
-
 typedef struct _rectangle
 {
     guint64 x1: 16;
