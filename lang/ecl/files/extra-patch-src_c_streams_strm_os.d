--- src/c/streams/strm_os.d.orig
+++ src/c/streams/strm_os.d
@@ -784,7 +784,9 @@
   ecl_disable_interrupts();
   do {
     out = fwrite(c, sizeof(char), n, IO_STREAM_FILE(strm));
-  } while (out < n && restartable_io_error(strm, "fwrite"));
+    /* Ignore write errors to stderr to avoid an infinite loop - patch from SageMath */
+  } while (out < n && (IO_STREAM_FILE(strm) != stderr) &&
+           restartable_io_error(strm, "fwrite"));
   ecl_enable_interrupts();
   return out;
 }
