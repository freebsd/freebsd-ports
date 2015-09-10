--- sal/osl/unx/backtrace.c.orig	2015-08-22 06:41:35 UTC
+++ sal/osl/unx/backtrace.c
@@ -177,15 +177,15 @@ void backtrace_symbols_fd( void **buffer
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
