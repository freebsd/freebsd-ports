From b61c51b7b6720e61497f92e115d5afccff891848 Mon Sep 17 00:00:00 2001
From: Adrian Popescu <adrian-constantin.popescu@outlook.com>
Date: Thu, 17 Aug 2017 23:26:22 +0300
Subject: [PATCH] Fixed clang 4.0 compilation under Arch Linux with icu59.1-1
 (#10361)

ICU headers prefer use of `char16_t` instead of `uint16_t` for `UChar` in C++, where it is treated as a distinct type. This fixes associated warnings and errors.
--- swift/stdlib/public/stubs/UnicodeNormalization.cpp.orig	2017-04-21 21:18:29 UTC
+++ swift/stdlib/public/stubs/UnicodeNormalization.cpp
@@ -35,6 +35,7 @@
 
 #include "../SwiftShims/UnicodeShims.h"
 
+
 static const UCollator *MakeRootCollator() {
   UErrorCode ErrorCode = U_ZERO_ERROR;
   UCollator *root = ucol_open("", &ErrorCode);
@@ -86,7 +87,7 @@ private:
     for (unsigned char c = 0; c < 128; ++c) {
       UErrorCode ErrorCode = U_ZERO_ERROR;
       intptr_t NumCollationElts = 0;
-#if defined(__CYGWIN__) || defined(_MSC_VER)
+#if defined(__CYGWIN__) || defined( _MSC_VER) || defined(__linux__) || defined(__FreeBSD__)
       UChar Buffer[1];
 #else
       uint16_t Buffer[1];
@@ -127,10 +128,11 @@ swift::_swift_stdlib_unicode_compare_utf
                                                  int32_t LeftLength,
                                                  const uint16_t *RightString,
                                                  int32_t RightLength) {
-#if defined(__CYGWIN__) || defined(_MSC_VER)
+#if defined(__CYGWIN__) || defined( _MSC_VER) || defined(__linux__) || defined(__FreeBSD__)
   // ICU UChar type is platform dependent. In Cygwin, it is defined
   // as wchar_t which size is 2. It seems that the underlying binary
   // representation is same with swift utf16 representation.
+  // On Clang 4.0 under a recent Linux, ICU uses the built-in char16_t type.
   return ucol_strcoll(GetRootCollator(),
     reinterpret_cast<const UChar *>(LeftString), LeftLength,
     reinterpret_cast<const UChar *>(RightString), RightLength);
@@ -156,7 +158,7 @@ swift::_swift_stdlib_unicode_compare_utf
   UErrorCode ErrorCode = U_ZERO_ERROR;
 
   uiter_setUTF8(&LeftIterator, reinterpret_cast<const char *>(LeftString), LeftLength);
-#if defined(__CYGWIN__) || defined(_MSC_VER)
+#if defined(__CYGWIN__) || defined( _MSC_VER) || defined(__linux__) || defined(__FreeBSD__)
   uiter_setString(&RightIterator, reinterpret_cast<const UChar *>(RightString),
                   RightLength);
 #else
@@ -199,7 +201,7 @@ swift::_swift_stdlib_unicode_compare_utf
 void *swift::_swift_stdlib_unicodeCollationIterator_create(
     const __swift_uint16_t *Str, __swift_uint32_t Length) {
   UErrorCode ErrorCode = U_ZERO_ERROR;
-#if defined(__CYGWIN__) || defined(_MSC_VER)
+#if defined(__CYGWIN__) || defined( _MSC_VER) || defined(__linux__) || defined(__FreeBSD__)
   UCollationElements *CollationIterator = ucol_openElements(
     GetRootCollator(), reinterpret_cast<const UChar *>(Str), Length,
     &ErrorCode);
@@ -244,7 +246,7 @@ swift::_swift_stdlib_unicode_strToUpper(
                                         const uint16_t *Source,
                                         int32_t SourceLength) {
   UErrorCode ErrorCode = U_ZERO_ERROR;
-#if defined(__CYGWIN__) || defined(_MSC_VER)
+#if defined(__CYGWIN__) || defined( _MSC_VER) || defined(__linux__) || defined(__FreeBSD__)
   uint32_t OutputLength = u_strToUpper(reinterpret_cast<UChar *>(Destination),
                                        DestinationCapacity,
                                        reinterpret_cast<const UChar *>(Source),
@@ -271,7 +273,7 @@ swift::_swift_stdlib_unicode_strToLower(
                                         const uint16_t *Source,
                                         int32_t SourceLength) {
   UErrorCode ErrorCode = U_ZERO_ERROR;
-#if defined(__CYGWIN__) || defined(_MSC_VER)
+#if defined(__CYGWIN__) || defined( _MSC_VER) || defined(__linux__) || defined(__FreeBSD__)
   uint32_t OutputLength = u_strToLower(reinterpret_cast<UChar *>(Destination),
                                        DestinationCapacity,
                                        reinterpret_cast<const UChar *>(Source),
