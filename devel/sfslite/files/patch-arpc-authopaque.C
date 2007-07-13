--- arpc/authopaque.C.orig	2005-11-01 16:20:27.000000000 +0000
+++ arpc/authopaque.C	2007-07-12 22:38:36.000000000 +0000
@@ -41,7 +41,7 @@
 {
   AUTH *auth = New AUTH;
   bzero (auth, sizeof (*auth));
-  auth->ah_ops = (AUTH::auth_ops *) &auth_opaque_ops;
+  auth->ah_ops = (AUTH::auth_ops *) ((void *)&auth_opaque_ops);
   auth->ah_cred.oa_base = static_cast<caddr_t> (xmalloc (MAX_AUTH_BYTES));
   auth->ah_verf.oa_base = static_cast<caddr_t> (xmalloc (MAX_AUTH_BYTES));
   authopaque_set (auth, NULL, NULL);
@@ -66,7 +66,7 @@
 void
 authopaque_set (AUTH *auth, const opaque_auth *cred, const opaque_auth *verf)
 {
-  assert (auth->ah_ops == (AUTH::auth_ops *) &auth_opaque_ops);
+  assert (auth->ah_ops == (AUTH::auth_ops *) ((void *)&auth_opaque_ops));
   authcopy (&auth->ah_cred, cred);
   authcopy (&auth->ah_verf, verf);
 }
@@ -74,7 +74,7 @@
 void
 authopaque_set (AUTH *auth, const authunix_parms *aup)
 {
-  assert (auth->ah_ops == (AUTH::auth_ops *) &auth_opaque_ops);
+  assert (auth->ah_ops == (AUTH::auth_ops *) ((void *)&auth_opaque_ops));
 
   auth->ah_cred.oa_flavor = AUTH_UNIX;
   xdrmem xdr (auth->ah_cred.oa_base, MAX_AUTH_BYTES);
