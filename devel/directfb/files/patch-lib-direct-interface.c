--- lib/direct/interface.c.orig	2016-06-08 05:59:40 UTC
+++ lib/direct/interface.c
@@ -71,7 +71,11 @@ typedef struct {
      int                   references;
 } DirectInterfaceImplementation;
 
+#if HAVE_DECL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
 static pthread_mutex_t  implementations_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+#else
+static pthread_mutex_t  implementations_mutex = PTHREAD_MUTEX_INITIALIZER;
+#endif
 static DirectLink      *implementations       = NULL;
 
 static inline int
