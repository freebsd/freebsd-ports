--- cpp.orig/include/IceUtil/Shared.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/include/IceUtil/Shared.h	2012-09-10 11:43:58.000000000 +0200
@@ -50,6 +50,11 @@
 //
 // A non thread-safe base class for reference-counted types.
 //
+// IceUtil::SimpleSharedUnsafeDestructor
+// =====================
+//
+// A non thread-safe base class for reference-counted types - destructor might throw.
+//
 // IceUtil::Shared
 // ===============
 //
@@ -109,6 +114,57 @@ private:
     bool _noDelete;
 };
 
+class ICE_UTIL_API SimpleSharedUnsafeDestructor
+{
+public:
+
+    SimpleSharedUnsafeDestructor();
+    SimpleSharedUnsafeDestructor(const SimpleSharedUnsafeDestructor&);
+
+    virtual ~SimpleSharedUnsafeDestructor() ICE_NOEXCEPT_FALSE
+    {
+    }
+
+    SimpleSharedUnsafeDestructor& operator=(const SimpleSharedUnsafeDestructor&)
+    {
+        return *this;
+    }
+
+    void __incRef()
+    {
+        assert(_ref >= 0);
+        ++_ref;
+    }
+
+    void __decRef()
+    {
+        assert(_ref > 0);
+        if(--_ref == 0)
+        {
+            if(!_noDelete)
+            {
+                _noDelete = true;
+                delete this;
+            }
+        }
+    }
+
+    int __getRef() const
+    {
+        return _ref;
+    }
+
+    void __setNoDelete(bool b)
+    {
+        _noDelete = b;
+    }
+
+private:
+
+    int _ref;
+    bool _noDelete;
+};
+
 class ICE_UTIL_API Shared
 {
 public:
