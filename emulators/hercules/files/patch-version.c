--- version.c.orig	Mon Sep  2 11:15:53 2002
+++ version.c	Mon Sep  2 11:17:51 2002
@@ -106,6 +106,14 @@
     "No HET BZIP2 support",
 #endif
 
+#if defined(GNU_MTIO_SUPPORT)
+	 "Using GNU tape handling",
+#elif defined(HAVE_MTIO_H)
+	 "Using generic Unix tape handling",
+#else
+	 "No SCSI tape support",
+#endif
+
   " "
 
 };
