--- ./sal/osl/unx/interlck.c.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./sal/osl/unx/interlck.c	2012-08-17 19:37:35.000000000 -0400
@@ -60,7 +60,7 @@
         :   "memory");
         return ++nCount;
     }
-#if ( __GNUC__ > 4 ) || (( __GNUC__ == 4)  && ( __GNUC_MINOR__ >= 4 ))
+#if ( __GNUC__ > 4 ) || (( __GNUC__ == 4)  && ( __GNUC_MINOR__ >= 2 ))
     else
         return __sync_add_and_fetch (pCount, 1);
 #else
@@ -89,7 +89,7 @@
         :   "memory");
         return --nCount;
     }
-#if ( __GNUC__ > 4 ) || (( __GNUC__ == 4)  && ( __GNUC_MINOR__ >= 4 ))
+#if ( __GNUC__ > 4 ) || (( __GNUC__ == 4)  && ( __GNUC_MINOR__ >= 2 ))
     else
         return __sync_sub_and_fetch (pCount, 1);
 #else
