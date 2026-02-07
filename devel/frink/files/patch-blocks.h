--- blocks.h.orig	2002-12-11 22:22:09 UTC
+++ blocks.h
@@ -33,7 +33,7 @@ typedef struct block_s
 extern Blox *pushBlock(Token *, int, int, int);
 extern void delBlock(Blox *);
 extern void popBlock(int);
-extern int isUnreachable();
+extern int isUnreachable(void);
 extern void setUnreachable(int);
 
 #endif
