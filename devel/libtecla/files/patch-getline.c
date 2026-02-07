--- getline.c.orig	2013-09-12 07:04:00 UTC
+++ getline.c
@@ -9062,8 +9062,8 @@ static int gl_event_handler(GetLine *gl, int fd)
       return 1;
   };
   return 0;
-}
 #endif
+}
 
 #if defined(HAVE_SELECT)
 /*.......................................................................
