--- src/emc/rs274ngc/rs274ngc_pre.cc.orig	2017-07-25 12:21:19.816453000 +0100
+++ src/emc/rs274ngc/rs274ngc_pre.cc	2017-07-25 12:22:07.230714000 +0100
@@ -1924,7 +1924,12 @@ int Interp::save_parameters(const char *filename,     
   }
 
   fflush(outfile);
+#ifdef __FreeBSD__
+  /* No fdatasync(2) in FreeBSD 11.0. */
+  fsync(fileno(outfile));
+#else
   fdatasync(fileno(outfile));
+#endif
   fclose(outfile);
   std::string bakfile = std::string(filename)
                             + RS274NGC_PARAMETER_FILE_BACKUP_SUFFIX;
