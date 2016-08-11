--- lib/direct/trace.c.orig	2012-05-23 13:43:12 UTC
+++ lib/direct/trace.c
@@ -90,7 +90,7 @@ struct __D_DirectTraceBuffer {
 
 static DirectTraceBuffer *buffers[MAX_BUFFERS];
 static int                buffers_num  = 0;
-#ifdef HAVE_DECL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
+#if HAVE_DECL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
 static pthread_mutex_t    buffers_lock = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
 #else
 static pthread_mutex_t    buffers_lock = PTHREAD_MUTEX_INITIALIZER;
@@ -176,7 +176,7 @@ typedef struct {
 } SymbolTable;
 
 static DirectLink      *tables      = NULL;
-#ifdef HAVE_DECL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
+#if HAVE_DECL_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
 static pthread_mutex_t  tables_lock = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
 #else
 static pthread_mutex_t  tables_lock = PTHREAD_MUTEX_INITIALIZER;
