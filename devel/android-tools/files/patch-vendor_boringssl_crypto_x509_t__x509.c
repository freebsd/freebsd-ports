https://github.com/google/boringssl/commit/af34f6460f0bf99dc267818f02b2936f60a30de7

From af34f6460f0bf99dc267818f02b2936f60a30de7 Mon Sep 17 00:00:00 2001
From: Kent Ross <root.main@gmail.com>
Date: Wed, 30 Mar 2022 14:11:02 -0700
Subject: [PATCH] Remove unused variable

This is causing -Werror failures with recent Clang builds.

Change-Id: I0f82d99ae51d02037f5f614a8fadfb3efc0da2da
Reviewed-on: https://boringssl-review.googlesource.com/c/boringssl/+/52145
Reviewed-by: Adam Langley <agl@google.com>
Commit-Queue: Adam Langley <agl@google.com>
---
 crypto/x509/t_x509.c | 6 +-----
 1 file changed, 1 insertion(+), 5 deletions(-)

diff --git a/crypto/x509/t_x509.c b/crypto/x509/t_x509.c
index 4f9d40979a..5e633a9d87 100644
--- vendor/boringssl/crypto/x509/t_x509.c
+++ vendor/boringssl/crypto/x509/t_x509.c
@@ -322,9 +322,7 @@ int X509_signature_print(BIO *bp, const X509_ALGOR *sigalg,
 int X509_NAME_print(BIO *bp, const X509_NAME *name, int obase)
 {
     char *s, *c, *b;
-    int ret = 0, l, i;
-
-    l = 80 - 2 - obase;
+    int ret = 0, i;
 
     b = X509_NAME_oneline(name, NULL, 0);
     if (!b)
@@ -351,12 +349,10 @@ int X509_NAME_print(BIO *bp, const X509_NAME *name, int obase)
                 if (BIO_write(bp, ", ", 2) != 2)
                     goto err;
             }
-            l--;
         }
         if (*s == '\0')
             break;
         s++;
-        l--;
     }
 
     ret = 1;
