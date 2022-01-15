--- cpp/include/Ice/FactoryTableInit.h.orig	2019-08-12 19:54:18 UTC
+++ cpp/include/Ice/FactoryTableInit.h
@@ -48,6 +48,9 @@ class DefaultUserExceptionFactoryInit (public)
     
     DefaultUserExceptionFactoryInit(const char* typeId) :
         _typeId(typeId)
+#if defined(ICE_BROKEN_ATEXIT)
+        , _ftableInit(new IceInternal::FactoryTableInit)
+#endif
     {
         factoryTable->addExceptionFactory(_typeId, new DefaultUserExceptionFactory<E>(_typeId));
     }
@@ -55,10 +58,16 @@ class DefaultUserExceptionFactoryInit (public)
     ~DefaultUserExceptionFactoryInit()
     {
         factoryTable->removeExceptionFactory(_typeId);
+#if defined(ICE_BROKEN_ATEXIT)
+        delete _ftableInit;
+#endif
     }
     
 private:
     const ::std::string _typeId;
+#if defined(ICE_BROKEN_ATEXIT)
+    IceInternal::FactoryTableInit* _ftableInit;
+#endif
 };
 
 template<class O>
@@ -68,6 +77,9 @@ class DefaultObjectFactoryInit (public)
     
     DefaultObjectFactoryInit(const char* typeId) :
         _typeId(typeId)
+#if defined(ICE_BROKEN_ATEXIT)
+        , _ftableInit(new IceInternal::FactoryTableInit)
+#endif
     {
         factoryTable->addObjectFactory(_typeId, new DefaultObjectFactory<O>(_typeId));
     }
@@ -75,11 +87,16 @@ class DefaultObjectFactoryInit (public)
     ~DefaultObjectFactoryInit()
     {
         factoryTable->removeObjectFactory(_typeId);
+#if defined(ICE_BROKEN_ATEXIT)
+        delete _ftableInit;
+#endif
     }
     
 private:
     const ::std::string _typeId;
- 
+#if defined(ICE_BROKEN_ATEXIT)
+    IceInternal::FactoryTableInit* _ftableInit;
+#endif
 };
 
 }
