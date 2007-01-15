--- t.c.orig	Tue Nov  7 18:56:35 2006
+++ t.c	Sat Jan 13 14:37:06 2007
@@ -41,8 +41,6 @@
 }
 
 int main(int argc,char* argv[]) {
-  (void)argc;
-  (void)argv;
 #if 0
   io_batch* b=iob_new(1234);
   int64 fd=open("t.c",0);
