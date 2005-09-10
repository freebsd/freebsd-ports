--- src/sdb.h.orig	Sat Sep 10 18:02:32 2005
+++ src/sdb.h	Sat Sep 10 18:05:50 2005
@@ -82,7 +82,7 @@
 #define PLAYER_DATA_FILE "player.dat"
 
 #define NEXT_TOK  nextToken(line, start, end)
-#define S2F(x)    strtof(x.c_str(), NULL)
+#define S2F(x)    ((float) strtod(x.c_str(), NULL))
 #define S2I(x)    strtol(x.c_str(), NULL, 10)
 
 #define X  0
