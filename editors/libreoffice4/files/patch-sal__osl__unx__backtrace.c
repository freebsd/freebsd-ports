--- sal/osl/unx/backtrace.c.orig	2014-09-16 16:10:41.000000000 -0400
+++ sal/osl/unx/backtrace.c	2014-10-14 15:52:40.000000000 -0400
@@ -177,15 +177,15 @@
                 if ( dli.dli_fname && dli.dli_fbase )
                 {
                     offset = (ptrdiff_t)*pFramePtr - (ptrdiff_t)dli.dli_fbase;
-                    fprintf( fp, "%s+0x%x", dli.dli_fname, offset );
+                    fprintf( fp, "%s+0x%tx", dli.dli_fname, offset );
                 }
                 if ( dli.dli_sname && dli.dli_saddr )
                 {
                     offset = (ptrdiff_t)*pFramePtr - (ptrdiff_t)dli.dli_saddr;
-                    fprintf( fp, "(%s+0x%x)", dli.dli_sname, offset );
+                    fprintf( fp, "(%s+0x%tx)", dli.dli_sname, offset );
                 }
             }
-            fprintf( fp, "[0x%x]\n", *pFramePtr );
+            fprintf( fp, "[%p]\n", *pFramePtr );
         }
         fflush( fp );
         fclose( fp );
