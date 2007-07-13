--- arpc/authuint.C.orig	2005-11-01 16:20:27.000000000 +0000
+++ arpc/authuint.C	2007-07-12 22:38:40.000000000 +0000
@@ -33,7 +33,7 @@
 u_int32_t
 authuint_getval (AUTH *auth)
 {
-  assert (auth->ah_ops == (AUTH::auth_ops *) &auth_uint_ops);
+  assert (auth->ah_ops == (AUTH::auth_ops *) ((void *)&auth_uint_ops));
   return auth->ah_key.key.low;
 }
 
@@ -43,7 +43,7 @@
   AUTH *auth = New AUTH;
   bzero (auth, sizeof (*auth));
   auth->ah_key.key.low = val;
-  auth->ah_ops = (AUTH::auth_ops *) &auth_uint_ops;
+  auth->ah_ops = (AUTH::auth_ops *) ((void *)&auth_uint_ops);
   return auth;
 }
 
