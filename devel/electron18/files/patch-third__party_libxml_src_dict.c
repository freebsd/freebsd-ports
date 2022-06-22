--- third_party/libxml/src/dict.c.orig	2022-05-19 05:18:00 UTC
+++ third_party/libxml/src/dict.c
@@ -135,7 +135,7 @@ static xmlRMutexPtr xmlDictMutex = NULL;
 static int xmlDictInitialized = 0;
 
 #ifdef DICT_RANDOMIZATION
-#ifdef HAVE_RAND_R
+#if defined(HAVE_RAND_R) && !defined(HAVE_ARC4RANDOM)
 /*
  * Internal data for random function, protected by xmlDictMutex
  */
@@ -176,7 +176,7 @@ int __xmlInitializeDict(void) {
         return(0);
     xmlRMutexLock(xmlDictMutex);
 
-#ifdef DICT_RANDOMIZATION
+#if defined(DICT_RANDOMIZATION) && !defined(HAVE_ARC4RANDOM)
 #ifdef HAVE_RAND_R
     rand_seed = time(NULL);
     rand_r(& rand_seed);
@@ -196,13 +196,17 @@ int __xmlRandom(void) {
     if (xmlDictInitialized == 0)
         __xmlInitializeDict();
 
+#ifdef HAVE_ARC4RANDOM
+    ret = arc4random();
+#else
     xmlRMutexLock(xmlDictMutex);
-#ifdef HAVE_RAND_R
+#  ifdef HAVE_RAND_R
     ret = rand_r(& rand_seed);
-#else
+#  else
     ret = rand();
-#endif
+#  endif
     xmlRMutexUnlock(xmlDictMutex);
+#endif
     return(ret);
 }
 #endif
