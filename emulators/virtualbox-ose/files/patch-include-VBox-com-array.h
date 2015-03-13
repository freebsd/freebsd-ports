--- include/VBox/com/array.h.orig	2015-03-02 10:06:38.000000000 -0500
+++ include/VBox/com/array.h	2015-03-12 17:52:37.107759000 -0400
@@ -908,12 +908,12 @@
      */
     const T operator[] (size_t aIdx) const
     {
-        AssertReturn(m.arr != NULL,  *((T *)NULL));
-        AssertReturn(aIdx < size(), *((T *)NULL));
+        Assert(m.arr != NULL);
+        Assert(aIdx < size());
 #ifdef VBOX_WITH_XPCOM
         return m.arr[aIdx];
 #else
-        AssertReturn(m.raw != NULL,  *((T *)NULL));
+        Assert(m.raw != NULL);
         return m.raw[aIdx];
 #endif
     }
@@ -1409,8 +1409,8 @@
      */
     const nsID &operator[] (size_t aIdx) const
     {
-        AssertReturn(m.arr != NULL,  **((const nsID * *)NULL));
-        AssertReturn(aIdx < size(), **((const nsID * *)NULL));
+        Assert(m.arr != NULL);
+        Assert(aIdx < size());
         return *m.arr[aIdx];
     }
 
