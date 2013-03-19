
$FreeBSD$

--- mono/metadata/sgen-gc.c.orig
+++ mono/metadata/sgen-gc.c
@@ -179,6 +179,9 @@
 #ifdef HAVE_PTHREAD_H
 #include <pthread.h>
 #endif
+#ifdef HAVE_PTHREAD_ATTR_GET_NP
+#include <pthread_np.h>
+#endif
 #ifdef HAVE_SEMAPHORE_H
 #include <semaphore.h>
 #endif
@@ -3990,17 +3993,28 @@
 #endif
 
 	/* try to get it with attributes first */
-#if defined(HAVE_PTHREAD_GETATTR_NP) && defined(HAVE_PTHREAD_ATTR_GETSTACK)
-	{
-		size_t size;
-		void *sstart;
-		pthread_attr_t attr;
-		pthread_getattr_np (pthread_self (), &attr);
-		pthread_attr_getstack (&attr, &sstart, &size);
-		info->stack_start_limit = sstart;
-		info->stack_end = (char*)sstart + size;
-		pthread_attr_destroy (&attr);
-	}
+#if (defined(HAVE_PTHREAD_GETATTR_NP) || defined(HAVE_PTHREAD_ATTR_GET_NP)) && defined(HAVE_PTHREAD_ATTR_GETSTACK)
+  {
+	size_t size;
+	void *sstart;
+	pthread_attr_t attr;
+
+#if defined(HAVE_PTHREAD_GETATTR_NP)
+	/* Linux */
+	pthread_getattr_np (pthread_self (), &attr);
+#elif defined(HAVE_PTHREAD_ATTR_GET_NP)
+	/* BSD */
+	pthread_attr_init (&attr);
+	pthread_attr_get_np (pthread_self (), &attr);
+#else
+#error Cannot determine which API is needed to retrieve pthread attributes.
+#endif
+
+	pthread_attr_getstack (&attr, &sstart, &size);
+	info->stack_start_limit = sstart;
+	info->stack_end = (char*)sstart + size;
+	pthread_attr_destroy (&attr);
+  }
 #elif defined(HAVE_PTHREAD_GET_STACKSIZE_NP) && defined(HAVE_PTHREAD_GET_STACKADDR_NP)
 		 info->stack_end = (char*)pthread_get_stackaddr_np (pthread_self ());
 		 info->stack_start_limit = (char*)info->stack_end - pthread_get_stacksize_np (pthread_self ());
