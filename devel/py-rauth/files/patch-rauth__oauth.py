commit 7fb3b7bf1a1869a52cf59ee3eb607d318e97265c
Author: John W. O'Brien <john@saltant.com>
Date:   Mon Jul 27 14:56:02 2020 -0400

    Support PyCryptodome as alternative to PyCrypto

--- rauth/oauth.py.orig	2015-11-05 16:01:31 UTC
+++ rauth/oauth.py
@@ -171,7 +171,8 @@ class RsaSha1Signature(SignatureMethod):
             from Crypto.Signature import PKCS1_v1_5 as p
             self.RSA, self.SHA, self.PKCS1_v1_5 = r, s, p
         except ImportError:  # pragma: no cover
-            raise NotImplementedError('PyCrypto is required for ' + self.NAME)
+            raise NotImplementedError('PyCrypto(dome) is required for '
+                                      + self.NAME)

     def sign(self,
              consumer_secret,
@@ -208,7 +209,9 @@ class RsaSha1Signature(SignatureMethod):
         # resolve the key
         if is_basestring(consumer_secret):
             consumer_secret = self.RSA.importKey(consumer_secret)
-        if not isinstance(consumer_secret, self.RSA._RSAobj):
+        valid_cls = (getattr(self.RSA, '_RSAobj', False)
+                     or getattr(self.RSA, 'RsaKey', False))
+        if not (valid_cls and isinstance(consumer_secret, valid_cls)):
             raise ValueError('invalid consumer_secret')

         # hash the string with RSA-SHA1
