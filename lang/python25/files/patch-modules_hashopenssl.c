--- Modules/_hashopenssl.c.orig	2006-05-29 22:04:52.000000000 +0100
+++ Modules/_hashopenssl.c	2008-08-30 10:43:27.000000000 +0100
@@ -19,6 +19,8 @@
 /* EVP is the preferred interface to hashing in OpenSSL */
 #include <openssl/evp.h>
 
+#define MUNCH_SIZE INT_MAX
+
 
 #ifndef HASH_OBJ_CONSTRUCTOR
 #define HASH_OBJ_CONSTRUCTOR 0
@@ -164,9 +166,18 @@
     if (!PyArg_ParseTuple(args, "s#:update", &cp, &len))
         return NULL;
 
+    if (len > 0 && len <= MUNCH_SIZE) {
     EVP_DigestUpdate(&self->ctx, cp, Py_SAFE_DOWNCAST(len, Py_ssize_t,
                                                       unsigned int));
-
+    } else {
+        Py_ssize_t offset = 0;
+        while (len) {
+            unsigned int process = len > MUNCH_SIZE ? MUNCH_SIZE : len;
+            EVP_DigestUpdate(&self->ctx, cp + offset, process);
+            len -= process;
+            offset += process;
+        }
+    }
     Py_INCREF(Py_None);
     return Py_None;
 }
@@ -255,9 +266,20 @@
     self->name = name_obj;
     Py_INCREF(self->name);
 
-    if (cp && len)
+    if (cp && len) {
+        if (len > 0 && len <= MUNCH_SIZE) {
         EVP_DigestUpdate(&self->ctx, cp, Py_SAFE_DOWNCAST(len, Py_ssize_t,
                                                           unsigned int));
+        } else {
+            Py_ssize_t offset = 0;
+            while (len) {
+                unsigned int process = len > MUNCH_SIZE ? MUNCH_SIZE : len;
+                EVP_DigestUpdate(&self->ctx, cp + offset, process);
+                len -= process;
+                offset += process;
+            }
+        }
+    }
 
     return 0;
 }
@@ -328,7 +350,7 @@
 static PyObject *
 EVPnew(PyObject *name_obj,
        const EVP_MD *digest, const EVP_MD_CTX *initial_ctx,
-       const unsigned char *cp, unsigned int len)
+       const unsigned char *cp, Py_ssize_t len)
 {
     EVPobject *self;
 
@@ -346,8 +368,20 @@
         EVP_DigestInit(&self->ctx, digest);
     }
 
-    if (cp && len)
-        EVP_DigestUpdate(&self->ctx, cp, len);
+    if (cp && len) {
+        if (len > 0 && len <= MUNCH_SIZE) {
+            EVP_DigestUpdate(&self->ctx, cp, Py_SAFE_DOWNCAST(len, Py_ssize_t,
+                                                              unsigned int));
+        } else {
+            Py_ssize_t offset = 0;
+            while (len) {
+                unsigned int process = len > MUNCH_SIZE ? MUNCH_SIZE : len;
+                EVP_DigestUpdate(&self->ctx, cp + offset, process);
+                len -= process;
+                offset += process;
+            }
+        }
+    }
 
     return (PyObject *)self;
 }
@@ -384,8 +418,7 @@
 
     digest = EVP_get_digestbyname(name);
 
-    return EVPnew(name_obj, digest, NULL, cp, Py_SAFE_DOWNCAST(len, Py_ssize_t,
-                                                               unsigned int));
+    return EVPnew(name_obj, digest, NULL, cp, len);
 }
 
 /*
@@ -410,7 +443,7 @@
                 CONST_ ## NAME ## _name_obj, \
                 NULL, \
                 CONST_new_ ## NAME ## _ctx_p, \
-                cp, Py_SAFE_DOWNCAST(len, Py_ssize_t, unsigned int)); \
+                cp, len); \
     }
 
 /* a PyMethodDef structure for the constructor */
