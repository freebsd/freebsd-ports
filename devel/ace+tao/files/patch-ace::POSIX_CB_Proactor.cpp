--- ace/POSIX_CB_Proactor.cpp.orig	Sat Apr  3 18:21:13 2004
+++ ace/POSIX_CB_Proactor.cpp	Sat Apr  3 18:34:56 2004
@@ -89,14 +89,14 @@
   result->aio_sigevent.sigev_notify = SIGEV_CALLBACK;
   result->aio_sigevent.sigev_func   = aio_completion_func ;
 #else
-  result->aio_sigevent.sigev_notify = SIGEV_THREAD;
+//  result->aio_sigevent.sigev_notify = SIGEV_THREAD;
 #  if defined (ACE_HAS_SIG_C_FUNC)
   result->aio_sigevent.sigev_notify_function =
     ACE_POSIX_CB_Proactor_aio_completion;
 #  else
-  result->aio_sigevent.sigev_notify_function = aio_completion_func;
+//  result->aio_sigevent.sigev_notify_function = aio_completion_func;
 #  endif /* ACE_HAS_SIG_C_FUNC */
-  result->aio_sigevent.sigev_notify_attributes = 0;
+//  result->aio_sigevent.sigev_notify_attributes = 0;
 #endif /* __sgi */
 
 #if defined (__FreeBSD__)
