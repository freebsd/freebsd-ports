--- Languages/Io/ObjcBridge/Runtime.m.orig	2007-08-03 16:46:18.000000000 +0200
+++ Languages/Io/ObjcBridge/Runtime.m	2011-04-21 06:46:53.000000000 +0200
@@ -11,11 +11,11 @@
 		while ((i < bufferLen) && (class = objc_next_class(&iterator))) buffer[i++]=class;
 		return classCount;
 	}
-#else
+#endif
+#if 1
 	IMP __objc_get_forward_imp(SEL sel)
 	{
-		extern id _objc_msgForward(id self, SEL sel, ...);
-		return _objc_msgForward;
+		return __objc_msg_forward;
 	}
 #endif
 
