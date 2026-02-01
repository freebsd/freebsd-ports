--- build2/libbuild2/script/regex.hxx.orig	2022-12-16 05:41:50 UTC
+++ build2/libbuild2/script/regex.hxx
@@ -616,11 +616,16 @@ namespace std
   // to use as an index in some internal cache regardless if the cache is used
   // for this specialization (and the cache is used only if CharT is char).
   //
+  // Note that starting with libc++ 20 we get -Winvalid-specialization for
+  // this specialization. But luckily it doesn't seem to be necessary.
+  //
+#if !defined(_LIBCPP_VERSION) || _LIBCPP_VERSION < 20000
   template <>
   struct make_unsigned<build2::script::regex::line_char>
   {
     using type = build2::script::regex::line_char;
   };
+#endif
 
   // When used with libc++ the linker complains that it can't find
   // __match_any_but_newline<line_char>::__exec() function. The problem is
