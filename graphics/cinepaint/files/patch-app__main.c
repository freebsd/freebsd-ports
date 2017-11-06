--- app/main.c.orig
+++ app/main.c
@@ -55,7 +55,6 @@
 
 #ifdef HAVE_OY
 #include <oyranos/oyranos.h>
-#include <oyranos/oyranos_config.h>
 #include <oyranos/oyranos_version.h>
 char *oyranos_temp_path = NULL;
 void *myAlloc(size_t n) { return calloc(sizeof(char), n); }
@@ -448,7 +448,8 @@
 #ifdef WIN32
 
 #else
-# ifndef DEBUG_
+  if (use_debug_handler)
+  {
   /* Handle some signals */
   signal (SIGHUP, on_signal);
   signal (SIGINT, on_signal);
@@ -466,7 +467,7 @@
   /* Handle shmem reload */
   signal( SIGUSR2, on_sig_refresh);
 # endif
-# endif /* DEBUG */
+  }
 #endif
   /* Keep the command line arguments--for use in gimp_init */
   gimp_argc = argc - 1;
