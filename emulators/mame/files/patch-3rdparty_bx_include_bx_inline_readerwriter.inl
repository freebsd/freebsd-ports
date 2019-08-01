--- 3rdparty/bx/include/bx/inline/readerwriter.inl.orig	2019-04-24 05:00:38 UTC
+++ 3rdparty/bx/include/bx/inline/readerwriter.inl
@@ -273,7 +273,7 @@ namespace bx
 	}
 
 	template<typename Ty>
-	int32_t read(ReaderI* _reader, Ty& _value, Error* _err)
+	inline int32_t read(ReaderI* _reader, Ty& _value, Error* _err)
 	{
 		BX_ERROR_SCOPE(_err);
 		BX_STATIC_ASSERT(isTriviallyCopyable<Ty>() );
@@ -281,7 +281,7 @@ namespace bx
 	}
 
 	template<typename Ty>
-	int32_t readHE(ReaderI* _reader, Ty& _value, bool _fromLittleEndian, Error* _err)
+	inline int32_t readHE(ReaderI* _reader, Ty& _value, bool _fromLittleEndian, Error* _err)
 	{
 		BX_ERROR_SCOPE(_err);
 		BX_STATIC_ASSERT(isTriviallyCopyable<Ty>() );
@@ -329,7 +329,7 @@ namespace bx
 	}
 
 	template<typename Ty>
-	int32_t write(WriterI* _writer, const Ty& _value, Error* _err)
+	inline int32_t write(WriterI* _writer, const Ty& _value, Error* _err)
 	{
 		BX_ERROR_SCOPE(_err);
 		BX_STATIC_ASSERT(isTriviallyCopyable<Ty>() );
@@ -337,7 +337,7 @@ namespace bx
 	}
 
 	template<typename Ty>
-	int32_t writeLE(WriterI* _writer, const Ty& _value, Error* _err)
+	inline int32_t writeLE(WriterI* _writer, const Ty& _value, Error* _err)
 	{
 		BX_ERROR_SCOPE(_err);
 		BX_STATIC_ASSERT(isTriviallyCopyable<Ty>() );
@@ -346,8 +346,14 @@ namespace bx
 		return result;
 	}
 
+	template<>
+	inline int32_t writeLE(WriterI* _writer, const float& _value, Error* _err)
+	{
+		return writeLE(_writer, floatToBits(_value), _err);
+	}
+
 	template<typename Ty>
-	int32_t writeBE(WriterI* _writer, const Ty& _value, Error* _err)
+	inline int32_t writeBE(WriterI* _writer, const Ty& _value, Error* _err)
 	{
 		BX_ERROR_SCOPE(_err);
 		BX_STATIC_ASSERT(isTriviallyCopyable<Ty>() );
@@ -356,6 +362,12 @@ namespace bx
 		return result;
 	}
 
+	template<>
+	inline int32_t writeBE(WriterI* _writer, const float& _value, Error* _err)
+	{
+		return writeBE(_writer, floatToBits(_value), _err);
+	}
+
 	inline int64_t skip(SeekerI* _seeker, int64_t _offset)
 	{
 		return _seeker->seek(_offset, Whence::Current);
@@ -392,7 +404,7 @@ namespace bx
 	}
 
 	template<typename Ty>
-	int32_t peek(ReaderSeekerI* _reader, Ty& _value, Error* _err)
+	inline int32_t peek(ReaderSeekerI* _reader, Ty& _value, Error* _err)
 	{
 		BX_ERROR_SCOPE(_err);
 		BX_STATIC_ASSERT(isTriviallyCopyable<Ty>() );
