--- racket/src/mzrt.c.orig
+++ racket/src/mzrt.c
@@ -267,7 +267,7 @@
       stacksize = UNIX_STACK_MAXIMUM;
 #  endif
   }
-#elif defined(OS_X) || defined(linux)
+#elif defined(OS_X) || defined(linux) || defined(__FreeBSD__)
   stacksize = 8*1024*1024;
 #else
   stacksize = 0;
