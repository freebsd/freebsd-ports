--- Modules/_ssl.c.orig	2014-12-10 16:59:53.000000000 +0100
+++ Modules/_ssl.c	2015-01-27 21:24:47.877731754 +0100
@@ -3301,6 +3301,7 @@
 It is necessary to seed the PRNG with RAND_add() on some platforms before\n\
 using the ssl() function.");
 
+#ifdef HAVE_RAND_EGD
 static PyObject *
 PySSL_RAND_egd(PyObject *self, PyObject *arg)
 {
@@ -3326,6 +3327,7 @@
 Queries the entropy gather daemon (EGD) on the socket named by 'path'.\n\
 Returns number of bytes read.  Raises SSLError if connection to EGD\n\
 fails or if it does not provide enough data to seed PRNG.");
+#endif /* HAVE_RAND_EGD */
 
 #endif /* HAVE_OPENSSL_RAND */
 
@@ -3720,8 +3722,10 @@
 #ifdef HAVE_OPENSSL_RAND
     {"RAND_add",            PySSL_RAND_add, METH_VARARGS,
      PySSL_RAND_add_doc},
+#ifdef HAVE_RAND_EGD
     {"RAND_egd",            PySSL_RAND_egd, METH_VARARGS,
      PySSL_RAND_egd_doc},
+#endif /* HAVE_RAND_EGD */
     {"RAND_status",         (PyCFunction)PySSL_RAND_status, METH_NOARGS,
      PySSL_RAND_status_doc},
 #endif
