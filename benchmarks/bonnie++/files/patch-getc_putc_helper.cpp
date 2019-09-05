--- getc_putc_helper.cpp.orig	2009-07-03 04:26:05.000000000 +0200
+++ getc_putc_helper.cpp	2019-09-05 12:09:25.707876000 +0200
@@ -45,7 +45,7 @@
     return 1;
   }
   fflush(NULL);
-  TEST_FUNC_READ("getc() no thread", if( (c = getc(fp)) == EOF), res[1]);
+  TEST_FUNC_READ("getc() no thread", int tmp = getc(fp); c = (char)tmp; if (tmp == EOF), res[1]);
   if(fseek(fp, 0, SEEK_SET) != 0)
   {
     fprintf(stderr, "Can't seek.\n");
