
$FreeBSD$

--- src/omonad.c.orig
+++ src/omonad.c
@@ -526,7 +526,7 @@
 
 static int maxfd = -1;
 
-static local void setReader            Args((Int,Cell));
+/* static local void setReader            Args((Int,Cell)); */
 static local void addSocket            Args((Int, Int, Cell));
 static local void closeSocket          Args((Int, Cell));
 static local void closeDeleteSocket    Args((Int));
