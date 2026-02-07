--- src/c/file.d.orig	2016-12-19 10:25:00 UTC
+++ src/c/file.d
@@ -3351,8 +3351,10 @@ output_stream_write_byte8(cl_object strm, unsigned cha
   ecl_disable_interrupts();
   do {
     out = fwrite(c, sizeof(char), n, IO_STREAM_FILE(strm));
-  } while (out < n && restartable_io_error(strm, "fwrite"));
-  ecl_enable_interrupts();
+        /* Ignore write errors to stderr to avoid an infinite loop - patch from SageMath */
+        } while (out < n && (IO_STREAM_FILE(strm) != stderr) && restartable_io_error(strm, "fwrite"));
+
+       ecl_enable_interrupts();
   return out;
 }
 
