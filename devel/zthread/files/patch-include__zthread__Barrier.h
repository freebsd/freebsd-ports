--- include/zthread/Barrier.h.orig	2005-03-13 05:23:00 UTC
+++ include/zthread/Barrier.h
@@ -150,7 +150,7 @@ namespace ZThread {
 
       } else {
 
-        int myGeneration = _generation;
+        unsigned int myGeneration = _generation;
 
         try {
 
@@ -251,7 +251,7 @@ namespace ZThread {
 
       } else {
 
-        int myGeneration = _generation;
+        unsigned int myGeneration = _generation;
 
         try {
 
