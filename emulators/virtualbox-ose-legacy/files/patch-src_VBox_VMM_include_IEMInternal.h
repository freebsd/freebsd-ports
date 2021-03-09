--- src/VBox/VMM/include/IEMInternal.h.orig	2020-04-14 19:58:48 UTC
+++ src/VBox/VMM/include/IEMInternal.h
@@ -1082,7 +1082,7 @@ typedef enum IEMACCESSCRX
 
 #if defined(__GNUC__) && defined(RT_ARCH_X86)
 # define IEM_DECL_IMPL_TYPE(a_RetType, a_Name, a_ArgList) \
-    __attribute__((__fastcall__)) a_RetType (a_Name) a_ArgList
+    __attribute__((__fastcall__, __nothrow__)) a_RetType (a_Name) a_ArgList
 # define IEM_DECL_IMPL_DEF(a_RetType, a_Name, a_ArgList) \
     __attribute__((__fastcall__, __nothrow__)) a_RetType a_Name a_ArgList
 
