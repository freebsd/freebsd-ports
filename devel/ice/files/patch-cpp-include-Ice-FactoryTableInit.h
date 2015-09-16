--- cpp/include/Ice/FactoryTableInit.h.orig	2015-06-23 15:30:20.000000000 +0000
+++ cpp/include/Ice/FactoryTableInit.h	2015-06-27 14:51:48.188288621 +0000
@@ -48,6 +55,9 @@
     
     DefaultUserExceptionFactoryInit(const char* typeId) :
         _typeId(typeId)
+#if defined(ICE_BROKEN_ATEXIT)
+        , _ftableInit(new IceInternal::FactoryTableInit)
+#endif
     {
         factoryTable->addExceptionFactory(_typeId, new DefaultUserExceptionFactory<E>(_typeId));
     }
@@ -55,10 +65,16 @@
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
@@ -67,7 +83,10 @@
 public:
     
     DefaultObjectFactoryInit(const char* typeId) :
-        _typeId(typeId)
+        _typeId(typeId)
+#if defined(ICE_BROKEN_ATEXIT)
+        , _ftableInit(new IceInternal::FactoryTableInit)
+#endif
     {
         factoryTable->addObjectFactory(_typeId, new DefaultObjectFactory<O>(_typeId));
     }
@@ -75,11 +94,16 @@
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
