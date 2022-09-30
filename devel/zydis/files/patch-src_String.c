--- src/String.c.orig	2022-09-29 22:19:15 UTC
+++ src/String.c
@@ -65,7 +65,7 @@ static const char* const DECIMAL_LOOKUP =
 /* Decimal                                                                                        */
 /* ---------------------------------------------------------------------------------------------- */
 
-#if defined(ZYAN_X86) || defined(ZYAN_ARM) || defined(ZYAN_EMSCRIPTEN)
+#if defined(ZYAN_X86) || defined(ZYAN_ARM) || defined(ZYAN_EMSCRIPTEN) || defined(ZYAN_PPC)
 ZyanStatus ZydisStringAppendDecU32(ZyanString* string, ZyanU32 value, ZyanU8 padding_length)
 {
     ZYAN_ASSERT(string);
@@ -157,7 +157,7 @@ ZyanStatus ZydisStringAppendDecU64(ZyanString* string,
 /* Hexadecimal                                                                                    */
 /* ---------------------------------------------------------------------------------------------- */
 
-#if defined(ZYAN_X86) || defined(ZYAN_ARM) || defined(ZYAN_EMSCRIPTEN)
+#if defined(ZYAN_X86) || defined(ZYAN_ARM) || defined(ZYAN_EMSCRIPTEN) || defined(ZYAN_PPC)
 ZyanStatus ZydisStringAppendHexU32(ZyanString* string, ZyanU32 value, ZyanU8 padding_length,
     ZyanBool uppercase)
 {
@@ -312,7 +312,7 @@ ZyanStatus ZydisStringAppendDecU(ZyanString* string, Z
         ZYAN_CHECK(ZydisStringAppend(string, prefix));
     }
 
-#if defined(ZYAN_X64) || defined(ZYAN_AARCH64)
+#if defined(ZYAN_X64) || defined(ZYAN_AARCH64) || defined(ZYAN_PPC64) || defined(ZYAN_RISCV64)
     ZYAN_CHECK(ZydisStringAppendDecU64(string, value, padding_length));
 #else
     if (value & 0xFFFFFFFF00000000)
@@ -337,7 +337,7 @@ ZyanStatus ZydisStringAppendHexU(ZyanString* string, Z
         ZYAN_CHECK(ZydisStringAppend(string, prefix));
     }
 
-#if defined(ZYAN_X64) || defined(ZYAN_AARCH64)
+#if defined(ZYAN_X64) || defined(ZYAN_AARCH64) || defined(ZYAN_PPC64) || defined(ZYAN_RISCV64)
     ZYAN_CHECK(ZydisStringAppendHexU64(string, value, padding_length, uppercase));
 #else
     if (value & 0xFFFFFFFF00000000)
