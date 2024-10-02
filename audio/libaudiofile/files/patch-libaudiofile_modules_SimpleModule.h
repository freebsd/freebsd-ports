--- libaudiofile/modules/SimpleModule.h.orig	2013-03-06 05:30:03 UTC
+++ libaudiofile/modules/SimpleModule.h
@@ -123,7 +123,7 @@ struct signConverter
 	typedef typename IntTypes<Format>::UnsignedType UnsignedType;
 
 	static const int kScaleBits = (Format + 1) * CHAR_BIT - 1;
-	static const int kMinSignedValue = -1 << kScaleBits;
+	static const int kMinSignedValue = ~0u << kScaleBits;
 
 	struct signedToUnsigned : public std::unary_function<SignedType, UnsignedType>
 	{
