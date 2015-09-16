# Since LibreSSL 2.2.0 there is a define OPENSSL_NO_EGD
# Upstreamed Issue http://bugs.python.org/24557

--- Modules/_ssl.c.orig	2015-05-23 16:09:19 UTC
+++ Modules/_ssl.c
@@ -3380,7 +3380,7 @@ using the ssl() function.");
 #endif /* HAVE_OPENSSL_RAND */
 
 
-#ifdef HAVE_RAND_EGD
+#ifndef OPENSSL_NO_EGD
 
 static PyObject *
 PySSL_RAND_egd(PyObject *self, PyObject *arg)
@@ -3804,7 +3804,7 @@ static PyMethodDef PySSL_methods[] = {
     {"RAND_status",         (PyCFunction)PySSL_RAND_status, METH_NOARGS,
      PySSL_RAND_status_doc},
 #endif
-#ifdef HAVE_RAND_EGD
+#ifndef OPENSSL_NO_EGD
     {"RAND_egd",            PySSL_RAND_egd, METH_VARARGS,
      PySSL_RAND_egd_doc},
 #endif
