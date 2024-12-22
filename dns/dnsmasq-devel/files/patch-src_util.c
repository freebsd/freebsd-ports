--- src/util.c.orig	2024-12-20 21:57:21 UTC
+++ src/util.c
@@ -41,7 +41,7 @@ static int outleft = 0;
 static u32 out[8];
 static int outleft = 0;
 
-void rand_init()
+void rand_init(void)
 {
   int fd = open(RANDFILE, O_RDONLY);
   
