--- ../../src/wrapper.c.orig	Thu Dec 18 22:43:08 2003
+++ ../../src/wrapper.c	Wed Feb 16 10:09:17 2005
@@ -44,13 +44,15 @@
         }
         if(!logstream)		/* secure: we have no open stream*/
                 flag = FALSE;
-        va_start(ap, format);
         if(flag)
 		{
+			va_start(ap, format);
 			vfprintf(stdout, format, ap);
+			va_end(ap);
+			va_start(ap, format);
 			vfprintf(logstream, format, ap);
+			va_end(ap);
 		}
-        va_end(ap);
         fflush(logstream);
 
 #endif
