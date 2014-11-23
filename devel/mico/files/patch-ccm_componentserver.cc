--- ccm/componentserver.cc.orig	2014-10-17 20:39:04.000000000 -0500
+++ ccm/componentserver.cc	2014-10-17 20:40:17.000000000 -0500
@@ -37,8 +37,8 @@
 CORBA::ORB_var orb;
 PortableServer::POA_var poa;
 #ifdef HAVE_THREADS
-MICOMT::Mutex mutex;
-MICOMT::CondVar cond(&mutex);
+MICOMT::Mutex mico_mutex;
+MICOMT::CondVar cond(&mico_mutex);
 #else // HAVE_THREADS
 bool finished;
 #endif // HAVE_THREADS
@@ -575,7 +575,7 @@
 public:
     void _run(void*)
     {
-	MICOMT::AutoLock t_lock(mutex);
+	MICOMT::AutoLock t_lock(mico_mutex);
 	cond.wait();
 	csimpl->remove();
 	poa->destroy (1, 1);
