--- ../../vcglib/vcg/space/deprecated_point.h.orig	2013-10-30 18:12:59.000000000 +0100
+++ ../../vcglib/vcg/space/deprecated_point.h	2013-10-30 18:12:33.000000000 +0100
@@ -164,14 +164,14 @@
 	}
   inline const S &X() const { return _v[0]; }
 	inline const S &Y() const { return _v[1]; }
-	inline const S &Z() const { static_assert(N>2); return _v[2]; }
+	inline const S &Z() const { static_assert(N>2, ""); return _v[2]; }
 	 /// W is in any case the last coordinate.
 	 /// (in a 2D point, W() == Y(). In a 3D point, W()==Z()
 	 ///  in a 4D point, W() is a separate component)
 	inline const S &W() const { return _v[N-1]; }
 	inline S &X() { return _v[0]; }
 	inline S &Y() { return _v[1]; }
-	inline S &Z() { static_assert(N>2); return _v[2]; }
+	inline S &Z() { static_assert(N>2, ""); return _v[2]; }
 	inline S &W() { return _v[N-1]; }
 	inline const S * V() const
 	{
