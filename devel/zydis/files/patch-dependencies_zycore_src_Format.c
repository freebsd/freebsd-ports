--- dependencies/zycore/src/Format.c.orig	2022-10-03 17:57:52 UTC
+++ dependencies/zycore/src/Format.c
@@ -83,7 +83,7 @@ static const ZyanStringView STR_SUB = ZYAN_DEFINE_STRI
 /* Decimal                                                                                        */
 /* ---------------------------------------------------------------------------------------------- */
 
-#if defined(ZYAN_X86) || defined(ZYAN_ARM) || defined(ZYAN_EMSCRIPTEN) || defined(ZYAN_WASM)
+#if defined(ZYAN_X86) || defined(ZYAN_ARM) || defined(ZYAN_EMSCRIPTEN) || defined(ZYAN_WASM) || defined(ZYAN_PPC)
 ZyanStatus ZyanStringAppendDecU32(ZyanString* string, ZyanU32 value, ZyanU8 padding_length)
 {
     if (!string)
@@ -179,7 +179,7 @@ ZyanStatus ZyanStringAppendDecU64(ZyanString* string, 
 /* Hexadecimal                                                                                    */
 /* ---------------------------------------------------------------------------------------------- */
 
-#if defined(ZYAN_X86) || defined(ZYAN_ARM) || defined(ZYAN_EMSCRIPTEN) || defined(ZYAN_WASM)
+#if defined(ZYAN_X86) || defined(ZYAN_ARM) || defined(ZYAN_EMSCRIPTEN) || defined(ZYAN_WASM) || defined(ZYAN_PPC)
 ZyanStatus ZyanStringAppendHexU32(ZyanString* string, ZyanU32 value, ZyanU8 padding_length,
     ZyanBool uppercase)
 {
@@ -423,7 +423,7 @@ ZyanStatus ZyanStringAppendFormat(ZyanString* string, 
 
 ZyanStatus ZyanStringAppendDecU(ZyanString* string, ZyanU64 value, ZyanU8 padding_length)
 {
-#if defined(ZYAN_X64) || defined(ZYAN_AARCH64)
+#if defined(ZYAN_X64) || defined(ZYAN_AARCH64) || defined(ZYAN_PPC64) || defined(ZYAN_RISCV64)
     return ZyanStringAppendDecU64(string, value, padding_length);
 #else
     // Working with 64-bit values is slow on non 64-bit systems
@@ -464,7 +464,7 @@ ZyanStatus ZyanStringAppendDecS(ZyanString* string, Zy
 ZyanStatus ZyanStringAppendHexU(ZyanString* string, ZyanU64 value, ZyanU8 padding_length,
     ZyanBool uppercase)
 {
-#if defined(ZYAN_X64) || defined(ZYAN_AARCH64)
+#if defined(ZYAN_X64) || defined(ZYAN_AARCH64) || defined(ZYAN_PPC64) || defined(ZYAN_RISCV64)
     return ZyanStringAppendHexU64(string, value, padding_length, uppercase);
 #else
     // Working with 64-bit values is slow on non 64-bit systems
