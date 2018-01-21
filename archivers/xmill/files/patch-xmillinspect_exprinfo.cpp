./xmillinspect/exprinfo.cpp:64:10: error: cannot initialize return object of type 'int' with an rvalue of type 'nullptr_t'
                return NULL;
                       ^~~~
/usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
#define NULL    nullptr
                ^~~~~~~

--- xmillinspect/exprinfo.cpp.orig	2003-03-23 15:06:16 UTC
+++ xmillinspect/exprinfo.cpp
@@ -61,7 +61,7 @@ int ExprInfo::getSubContainerType(int sub)
 	if (expr) {
 		return expr->getContainerType();
 	} else {
-		return NULL;
+		return 0;
 	}
 }
 
