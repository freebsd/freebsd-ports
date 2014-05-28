Index: main/Crypt.pm
diff -u main/Crypt.pm.orig main/Crypt.pm
--- main/Crypt.pm.orig	2010-02-12 03:34:31.000000000 +0900
+++ main/Crypt.pm	2014-05-28 10:25:14.117593425 +0900
@@ -25,7 +25,7 @@
     # encryptedのsaltでrawをcrypt()してみて、一致したかどうかを真偽値で返す。
     my ($raw,$encrypted) = @_;
 
-    return crypt($raw,substr($encrypted,0,2)) eq $encrypted;
+    return crypt($raw,$encrypted) eq $encrypted;
 }
 
 sub gen_salt {
