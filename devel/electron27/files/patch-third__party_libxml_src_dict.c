--- third_party/libxml/src/dict.c.orig	2023-03-30 00:34:13 UTC
+++ third_party/libxml/src/dict.c
@@ -133,7 +133,7 @@ struct _xmlDict {
 static xmlMutex xmlDictMutex;
 
 #ifdef DICT_RANDOMIZATION
-#ifdef HAVE_RAND_R
+#if defined(HAVE_RAND_R) && !defined(HAVE_ARC4RANDOM)
 /*
  * Internal data for random function, protected by xmlDictMutex
  */
@@ -160,7 +160,7 @@ int xmlInitializeDict(void) {
 int __xmlInitializeDict(void) {
     xmlInitMutex(&xmlDictMutex);
 
-#ifdef DICT_RANDOMIZATION
+#if defined(DICT_RANDOMIZATION) && !defined(HAVE_ARC4RANDOM)
 #ifdef HAVE_RAND_R
     rand_seed = time(NULL);
     rand_r(& rand_seed);
@@ -175,13 +175,17 @@ int __xmlInitializeDict(void) {
 int __xmlRandom(void) {
     int ret;
 
+#ifdef HAVE_ARC4RANDOM
+    ret = arc4random();
+#else
     xmlMutexLock(&xmlDictMutex);
-#ifdef HAVE_RAND_R
+#  ifdef HAVE_RAND_R
     ret = rand_r(& rand_seed);
-#else
+#  else
     ret = rand();
-#endif
+#  endif
     xmlMutexUnlock(&xmlDictMutex);
+#endif
     return(ret);
 }
 #endif
