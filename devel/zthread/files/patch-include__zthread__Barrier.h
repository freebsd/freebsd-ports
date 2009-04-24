--- ./include/zthread/Barrier.h.orig	2005-03-13 00:23:00.000000000 -0500
+++ ./include/zthread/Barrier.h	2009-04-23 15:03:09.000000000 -0400
@@ -150,7 +150,7 @@
 
       } else {
 
-        int myGeneration = _generation;
+        unsigned int myGeneration = _generation;
 
         try {
 
@@ -251,7 +251,7 @@
 
       } else {
 
-        int myGeneration = _generation;
+        unsigned int myGeneration = _generation;
 
         try {
 
