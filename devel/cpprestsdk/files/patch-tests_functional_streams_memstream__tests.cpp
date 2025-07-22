--- tests/functional/streams/memstream_tests.cpp.orig	2023-12-05 04:23:31 UTC
+++ tests/functional/streams/memstream_tests.cpp
@@ -8,6 +8,7 @@
  *
  * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  ****/
+#include "cpprest/details/char_traits.h"
 #include "stdafx.h"
 #if defined(__cplusplus_winrt)
 #include <wrl.h>
@@ -32,7 +33,7 @@ void streambuf_putc(StreamBufferType& wbuf)
 {
     VERIFY_IS_TRUE(wbuf.can_write());
 
-    std::basic_string<typename StreamBufferType::char_type> s;
+    std::basic_string<typename StreamBufferType::char_type,typename utility::CanUseStdCharTraits<typename StreamBufferType::char_type>::TraitsType> s;
     s.push_back((typename StreamBufferType::char_type)0);
     s.push_back((typename StreamBufferType::char_type)1);
     s.push_back((typename StreamBufferType::char_type)2);
@@ -137,7 +138,7 @@ void streambuf_putn(StreamBufferType& wbuf)
 {
     VERIFY_IS_TRUE(wbuf.can_write());
 
-    std::basic_string<typename StreamBufferType::char_type> s;
+    std::basic_string<typename StreamBufferType::char_type,typename utility::CanUseStdCharTraits<typename StreamBufferType::char_type>::TraitsType> s;
     s.push_back((typename StreamBufferType::char_type)0);
     s.push_back((typename StreamBufferType::char_type)1);
     s.push_back((typename StreamBufferType::char_type)2);
@@ -169,7 +170,7 @@ void streambuf_putn(concurrency::streams::rawptr_buffe
 
     typedef concurrency::streams::rawptr_buffer<CharType> StreamBufferType;
 
-    std::basic_string<CharType> s;
+    std::basic_string<CharType,typename CanUseStdCharTraits<CharType>::TraitsType> s;
     s.push_back((CharType)0);
     s.push_back((CharType)1);
     s.push_back((CharType)2);
@@ -198,7 +199,7 @@ void streambuf_putn(concurrency::streams::container_bu
     typedef concurrency::streams::container_buffer<CollectionType> StreamBufferType;
     typedef typename concurrency::streams::container_buffer<CollectionType>::char_type CharType;
 
-    std::basic_string<CharType> s;
+    std::basic_string<CharType, typename utility::CanUseStdCharTraits<CharType>::TraitsType> s;
     s.push_back((CharType)0);
     s.push_back((CharType)1);
     s.push_back((CharType)2);
@@ -553,7 +554,7 @@ void streambuf_putn_getn(StreamBufferType& rwbuf)
     VERIFY_IS_TRUE(rwbuf.can_read());
     VERIFY_IS_TRUE(rwbuf.can_write());
     VERIFY_IS_FALSE(rwbuf.is_eof());
-    std::basic_string<typename StreamBufferType::char_type> s;
+    std::basic_string<typename StreamBufferType::char_type, typename utility::CanUseStdCharTraits<typename StreamBufferType::char_type>::TraitsType> s;
     s.push_back((typename StreamBufferType::char_type)0);
     s.push_back((typename StreamBufferType::char_type)1);
     s.push_back((typename StreamBufferType::char_type)2);
@@ -684,7 +685,7 @@ void streambuf_close_read_with_pending_read(StreamBuff
     VERIFY_IS_TRUE(rwbuf.can_write());
 
     // Write 4 characters
-    std::basic_string<typename StreamBufferType::char_type> s;
+    std::basic_string<typename StreamBufferType::char_type, typename utility::CanUseStdCharTraits<typename StreamBufferType::char_type>::TraitsType> s;
     s.push_back((typename StreamBufferType::char_type)0);
     s.push_back((typename StreamBufferType::char_type)1);
     s.push_back((typename StreamBufferType::char_type)2);
@@ -726,7 +727,7 @@ void streambuf_close_write_with_pending_read(StreamBuf
     VERIFY_IS_TRUE(rwbuf.can_write());
 
     // Write 4 characters
-    std::basic_string<typename StreamBufferType::char_type> s;
+    std::basic_string<typename StreamBufferType::char_type, typename utility::CanUseStdCharTraits<typename StreamBufferType::char_type>::TraitsType> s;
     s.push_back((typename StreamBufferType::char_type)0);
     s.push_back((typename StreamBufferType::char_type)1);
     s.push_back((typename StreamBufferType::char_type)2);
