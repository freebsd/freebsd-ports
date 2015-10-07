--- sope-appserver/NGObjWeb/DynamicElements/WOComponentContent.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/DynamicElements/WOComponentContent.m
@@ -75,11 +75,7 @@ static Class NSDateClass = Nil;
         printf("  ");
       printf("content: [%s %s]: %0.3fs\n",
              [[component name] cString], 
-#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
-	     sel_getName(_cmd), 
-#else
 	     sel_get_name(_cmd), 
-#endif
 	     diff);
     }
     
