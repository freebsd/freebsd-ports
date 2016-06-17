--- src/omonad.c.orig	2001-01-31 00:18:40 UTC
+++ src/omonad.c
@@ -526,7 +526,7 @@ typedef int socklen_t;
 
 static int maxfd = -1;
 
-static local void setReader            Args((Int,Cell));
+/* static local void setReader            Args((Int,Cell)); */
 static local void addSocket            Args((Int, Int, Cell));
 static local void closeSocket          Args((Int, Cell));
 static local void closeDeleteSocket    Args((Int));
