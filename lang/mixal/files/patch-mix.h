--- mix.h.orig	Mon Jun  3 17:55:50 2002
+++ mix.h	Mon Jun  3 17:56:02 2002
@@ -16,6 +16,7 @@
 void warn(const char *message, ...);
 void error(const char *message, ...);
 void fatal_error(const char *message, ...);
+void initialize_io(void);
 
 #define memory_size 4000
 
