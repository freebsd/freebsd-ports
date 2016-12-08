--- test/posix-mock-test.cc.orig	2016-12-01 18:09:30 UTC
+++ test/posix-mock-test.cc
@@ -502,7 +502,7 @@ LocaleType newlocale(int category_mask, 
   return LocaleMock::instance->newlocale(category_mask, locale, base);
 }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 typedef int FreeLocaleResult;
 #else
 typedef void FreeLocaleResult;
