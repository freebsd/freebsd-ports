--- ./arc.m.orig	2013-03-12 08:51:59.000000000 +0000
+++ ./arc.m	2014-01-13 15:04:54.000000000 +0000
@@ -219,15 +219,18 @@
 		}
 		else
 		{
-			[AutoreleasePool class];
-			useARCAutoreleasePool = class_respondsToSelector(AutoreleasePool,
-			                                                 SELECTOR(_ARCCompatibleAutoreleasePool));
-			NewAutoreleasePool = class_getMethodImplementation(object_getClass(AutoreleasePool),
-			                                                   SELECTOR(new));
-			DeleteAutoreleasePool = class_getMethodImplementation(AutoreleasePool,
-			                                                      SELECTOR(release));
-			AutoreleaseAdd = class_getMethodImplementation(object_getClass(AutoreleasePool),
-			                                               SELECTOR(addObject:));
+			useARCAutoreleasePool = (0 != class_getInstanceMethod(AutoreleasePool,
+			                                                      SELECTOR(_ARCCompatibleAutoreleasePool)));
+			if (!useARCAutoreleasePool)
+			{
+			        [AutoreleasePool class];
+			        NewAutoreleasePool = class_getMethodImplementation(object_getClass(AutoreleasePool),
+			                                                           SELECTOR(new));
+			        DeleteAutoreleasePool = class_getMethodImplementation(AutoreleasePool,
+			                                                              SELECTOR(release));
+			        AutoreleaseAdd = class_getMethodImplementation(object_getClass(AutoreleasePool),
+			                                                       SELECTOR(addObject:));
+			}
 		}
 	}
 }
