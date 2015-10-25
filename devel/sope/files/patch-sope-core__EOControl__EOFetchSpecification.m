--- sope-core/EOControl/EOFetchSpecification.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOFetchSpecification.m
@@ -291,7 +291,7 @@
       [ma release];
     }
     else
-      lHints = [self->hints retain];
+      lHints = (id)[self->hints retain];
   }
   else 
     lHints = nil;
