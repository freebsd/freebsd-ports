
$FreeBSD$

--- mono/metadata/threads.c.orig
+++ mono/metadata/threads.c
@@ -785,7 +785,16 @@
 void
 mono_thread_get_stack_bounds (guint8 **staddr, size_t *stsize)
 {
-#if defined(HAVE_PTHREAD_GET_STACKSIZE_NP) && defined(HAVE_PTHREAD_GET_STACKADDR_NP)
+#if defined(HOST_WIN32)
+	/* FIXME: 	If this function won't (or shouldn't) ever be called when running on
+			Windows, use the error preprocessor declaration here instead of this
+			default code (to _ensure_ we don't call this function on Windows). */
+	*staddr = NULL;
+	*stsize = (size_t)-1;
+	return;
+
+#elif defined(HAVE_PTHREAD_GET_STACKSIZE_NP) && defined(HAVE_PTHREAD_GET_STACKADDR_NP)
+	/* Mac OS X */
 	*staddr = (guint8*)pthread_get_stackaddr_np (pthread_self ());
 	*stsize = pthread_get_stacksize_np (pthread_self ());
 
@@ -793,52 +802,54 @@
 	*staddr -= *stsize;
 	*staddr = (guint8*)((gssize)*staddr & ~(mono_pagesize () - 1));
 	return;
-	/* FIXME: simplify the mess below */
-#elif !defined(HOST_WIN32)
+
+#elif (defined(HAVE_PTHREAD_GETATTR_NP) || defined(HAVE_PTHREAD_ATTR_GET_NP)) && defined(HAVE_PTHREAD_ATTR_GETSTACK)
+	/* Linux, BSD */
+
 	pthread_attr_t attr;
 	guint8 *current = (guint8*)&attr;
 
-	pthread_attr_init (&attr);
-#  ifdef HAVE_PTHREAD_GETATTR_NP
-	pthread_getattr_np (pthread_self(), &attr);
-#  else
-#    ifdef HAVE_PTHREAD_ATTR_GET_NP
-	pthread_attr_get_np (pthread_self(), &attr);
-#    elif defined(sun)
-	*staddr = NULL;
-	pthread_attr_getstacksize (&attr, &stsize);
-#    elif defined(__OpenBSD__)
-	stack_t ss;
-	int rslt;
-
-	rslt = pthread_stackseg_np(pthread_self(), &ss);
-	g_assert (rslt == 0);
+	#if defined(HAVE_PTHREAD_GETATTR_NP)
+	/* Linux */
+	pthread_getattr_np (pthread_self (), &attr);
 
-	*staddr = (guint8*)((size_t)ss.ss_sp - ss.ss_size);
-	*stsize = ss.ss_size;
-#    else
-	*staddr = NULL;
-	*stsize = 0;
-	return;
-#    endif
-#  endif
+	#elif defined(HAVE_PTHREAD_ATTR_GET_NP)
+	/* BSD */
+	pthread_attr_init (&attr);
+	pthread_attr_get_np (pthread_self (), &attr);
+	
+	#else
+	#error Cannot determine which API is needed to retrieve pthread attributes.
+	#endif
 
-#  if !defined(sun)
-#    if !defined(__OpenBSD__)
 	pthread_attr_getstack (&attr, (void**)staddr, stsize);
-#    endif
+	pthread_attr_destroy (&attr);
+
 	if (*staddr)
 		g_assert ((current > *staddr) && (current < *staddr + *stsize));
-#  endif
 
+	/* When running under emacs, sometimes staddr is not aligned to a page size */
+	*staddr = (guint8*)((gssize)*staddr & ~(mono_pagesize () - 1));
+
+#elif defined(sun)
+	/* What OS / architecture is this for? */
+	pthread_attr_t attr;
+	pthread_attr_init (&attr);
+	pthread_attr_getstacksize (&attr, &stsize);
 	pthread_attr_destroy (&attr);
-#else
 	*staddr = NULL;
-	*stsize = (size_t)-1;
-#endif
 
 	/* When running under emacs, sometimes staddr is not aligned to a page size */
 	*staddr = (guint8*)((gssize)*staddr & ~(mono_pagesize () - 1));
+	return;
+
+#else
+	/* FIXME:	It'd be better to use the 'error' preprocessor macro here so we know
+			at compile-time if the target platform isn't supported. */
+	*staddr = NULL;
+	*stsize = 0;
+	return;
+#endif
 }	
 
 MonoThread *
