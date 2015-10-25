--- sope-core/NGExtensions/FdExt.subproj/NSObject+Logs.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/NGExtensions/FdExt.subproj/NSObject+Logs.m
@@ -52,10 +52,10 @@ static inline Class NSStringClass(void) 
                                          200);
     lm = [NGLoggerManager defaultLoggerManager];
   }
-  logger = NSMapGet(loggerForClassMap, self->isa);
+  logger = NSMapGet(loggerForClassMap, object_getClass(self));
   if (!logger) {
-    logger = [lm loggerForClass:self->isa];
-    NSMapInsert(loggerForClassMap, self->isa, logger);
+    logger = [lm loggerForClass: object_getClass(self)];
+    NSMapInsert(loggerForClassMap, object_getClass(self), logger);
   }
 
   return logger;
