--- 3rdparty/bx/include/bx/inline/endian.inl.orig	2019-04-24 05:00:38 UTC
+++ 3rdparty/bx/include/bx/inline/endian.inl
@@ -46,7 +46,7 @@ namespace bx
 	}
 
 	template <typename Ty>
-	inline Ty toLittleEndian(const Ty _in)
+	inline Ty toLittleEndian(Ty _in)
 	{
 #if BX_CPU_ENDIAN_BIG
 		return endianSwap(_in);
@@ -56,7 +56,7 @@ namespace bx
 	}
 
 	template <typename Ty>
-	inline Ty toBigEndian(const Ty _in)
+	inline Ty toBigEndian(Ty _in)
 	{
 #if BX_CPU_ENDIAN_LITTLE
 		return endianSwap(_in);
@@ -66,7 +66,7 @@ namespace bx
 	}
 
 	template <typename Ty>
-	inline Ty toHostEndian(const Ty _in, bool _fromLittleEndian)
+	inline Ty toHostEndian(Ty _in, bool _fromLittleEndian)
 	{
 #if BX_CPU_ENDIAN_LITTLE
 		return _fromLittleEndian ? _in : endianSwap(_in);
