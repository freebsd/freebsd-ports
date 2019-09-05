--- getc_putc.cpp.orig	2018-09-15 09:00:31.000000000 +0200
+++ getc_putc.cpp	2019-09-05 12:09:25.705704000 +0200
@@ -206,7 +206,7 @@
     return 1;
   }
   fflush(NULL);
-  TEST_FUNC_READ("getc()", if( (c = getc(fp)) == EOF), res[Getc]);
+  TEST_FUNC_READ("getc()", int tmp = getc(fp); c = (char)tmp; if (tmp == EOF), res[Getc]);
   if(fseek(fp, 0, SEEK_SET) != 0)
   {
     fprintf(stderr, "Can't seek.\n");
@@ -221,7 +221,7 @@
     return 1;
   }
   fflush(NULL);
-  TEST_FUNC_READ("getc_unlocked()", if( (c = getc_unlocked(fp)) == EOF), res[GetcUnlocked]);
+  TEST_FUNC_READ("getc_unlocked()", int tmp = getc_unlocked(fp); c = (char)tmp; if (tmp == EOF), res[GetcUnlocked]);
 
   if(!quiet)
     printf("done\n");
