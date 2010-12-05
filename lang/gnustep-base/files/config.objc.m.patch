--- config/config.objc.m.orig	2006-02-11 19:22:57.000000000 +0100
+++ config/config.objc.m	2010-11-12 15:10:59.000000000 +0100
@@ -6,13 +6,41 @@
   are permitted in any medium without royalty provided the copyright
   notice and this notice are preserved.
 */
-#ifndef NeXT_RUNTIME
-#include <objc/NXConstStr.h>
+
+#include <objc/objc.h>
+#include <objc/objc-api.h>
+
+#include <objc/Object.h>
+
+#if !defined(NeXT_RUNTIME) && !defined(__GNUSTEP_RUNTIME__)
 @implementation NXConstantString
+- (const char*) cString
+{
+  return 0;
+}
+- (unsigned int) length
+{
+  return 0;
+}
 @end
 #endif
 
-#include <objc/Object.h>
+/* Provide dummy implementations for NSObject and NSConstantString
+ * for runtime implementations which won't link without them.
+ */
+
+@interface NSObject
+{ 
+ id isa;
+}
+@end
+@implementation NSObject
+@end
+
+@interface NSConstantString : NSObject
+@end
+@implementation NSConstantString
+@end
 
 @interface Test : Object
 +(int) testResult;
