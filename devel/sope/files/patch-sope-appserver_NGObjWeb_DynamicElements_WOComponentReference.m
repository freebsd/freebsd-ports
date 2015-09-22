--- sope-appserver/NGObjWeb/DynamicElements/WOComponentReference.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/DynamicElements/WOComponentReference.m
@@ -172,7 +172,7 @@ _updateComponent(WOComponentReference *s
         printf("  ");
       printf("[%s %s]: %0.3fs\n",
              [[child name] cString], 
-#if APPLE_RUNTIME || NeXT_RUNTIME || (__GNU_LIBOBJC__ >= 20100911)
+#if APPLE_RUNTIME || NeXT_RUNTIME || (__GNU_LIBOBJC__ >= 20100911) || defined(__GNUSTEP_RUNTIME__)
 	     sel_getName(_cmd), 
 #else
 	     sel_get_name(_cmd), 
