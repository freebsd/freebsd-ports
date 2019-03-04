--- src/nvtt/squish/simd_ve.h.orig	2010-05-15 09:12:05 UTC
+++ src/nvtt/squish/simd_ve.h
@@ -31,7 +31,8 @@
 
 namespace squish {
 
-#define VEC4_CONST( X ) Vec4( ( vector float )( X ) )
+#define VEC_INIT( X ) ( vector float ){ X, X, X, X }
+#define VEC4_CONST( X ) Vec4( VEC_INIT( X ) )
 
 class Vec4
 {
@@ -96,7 +97,7 @@ public:
 	
 	Vec4& operator*=( Arg v )
 	{
-		m_v = vec_madd( m_v, v.m_v, ( vector float )( -0.0f ) );
+		m_v = vec_madd( m_v, v.m_v, VEC_INIT( -0.0f ) );
 		return *this;
 	}
 	
@@ -112,7 +113,7 @@ public:
 	
 	friend Vec4 operator*( Vec4::Arg left, Vec4::Arg right  )
 	{
-		return Vec4( vec_madd( left.m_v, right.m_v, ( vector float )( -0.0f ) ) );
+		return Vec4( vec_madd( left.m_v, right.m_v, VEC_INIT( -0.0f ) ) );
 	}
 	
 	//! Returns a*b + c
@@ -133,7 +134,7 @@ public:
 		vector float estimate = vec_re( v.m_v );
 		
 		// one round of Newton-Rhaphson refinement
-		vector float diff = vec_nmsub( estimate, v.m_v, ( vector float )( 1.0f ) );
+		vector float diff = vec_nmsub( estimate, v.m_v, VEC_INIT( 1.0f ) );
 		return Vec4( vec_madd( diff, estimate, estimate ) );
 	}
 	
