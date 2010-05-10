--- libjava/gnu/java/security/jce/prng/natVMSecureRandomWin32.cc.orig	2009-09-16 17:38:46.000000000 -0400
+++ libjava/gnu/java/security/jce/prng/natVMSecureRandomWin32.cc	2010-05-09 17:19:54.000000000 -0400
@@ -26,7 +26,7 @@
 gnu::java::security::jce::prng::VMSecureRandom::natGenerateSeed(jbyteArray byte_array, jint offset, jint length)
 {
   if (length != 0)
-    throw new java::lang::UnsupportedOperationException (
+    throw new ::java::lang::UnsupportedOperationException (
       JvNewStringLatin1 ("natGenerateSeed is not available for Win32 target."));
   return 0;
 }
