--- ../../vcglib/vcg/space/deprecated_point.h.orig	2014-04-01 17:10:03.000000000 +0200
+++ ../../vcglib/vcg/space/deprecated_point.h	2015-01-24 23:55:25.000000000 +0100
@@ -59,6 +59,10 @@
 #include <vcg/math/base.h>
 #include <vcg/space/space.h>
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 1000000
+#define static_assert(cond,msg) typedef char static_assertion_##__FILE__##__LINE__[(cond)?1:-1]
+#endif
+
 namespace vcg {
 
     namespace ndim{
@@ -164,14 +168,14 @@
 	}
   inline const S &X() const { return _v[0]; }
     inline const S &Y() const { return _v[1]; }
-    inline const S &Z() const { static_assert(N>2); return _v[2]; }
+    inline const S &Z() const { static_assert(N>2, "No Z coordinate in R² space"); return _v[2]; }
      /// W is in any case the last coordinate.
      /// (in a 2D point, W() == Y(). In a 3D point, W()==Z()
      ///  in a 4D point, W() is a separate component)
     inline const S &W() const { return _v[N-1]; }
     inline S &X() { return _v[0]; }
     inline S &Y() { return _v[1]; }
-    inline S &Z() { static_assert(N>2); return _v[2]; }
+    inline S &Z() { static_assert(N>2, "No Z coordinate in R² space"); return _v[2]; }
     inline S &W() { return _v[N-1]; }
     inline const S * V() const
     {
