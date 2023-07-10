--- getc_putc_helper.cpp.orig	2009-07-03 02:26:05 UTC
+++ getc_putc_helper.cpp
@@ -45,7 +45,7 @@ int main(int argc, char *argv[])
     return 1;
   }
   fflush(NULL);
-  TEST_FUNC_READ("getc() no thread", if( (c = getc(fp)) == EOF), res[1]);
+  TEST_FUNC_READ("getc() no thread", int tmp = getc(fp); c = (char)tmp; if (tmp == EOF), res[1]);
   if(fseek(fp, 0, SEEK_SET) != 0)
   {
     fprintf(stderr, "Can't seek.\n");
