--- tools/objdump/extract_source.cpp.orig	2026-07-08 19:46:47 UTC
+++ tools/objdump/extract_source.cpp
@@ -23,45 +23,12 @@
 #include "source/opt/log.h"
 #include "spirv-tools/libspirv.hpp"
 #include "tools/util/cli_consumer.h"
+#include "source/binary.h"
 
 namespace {
 
 constexpr auto kDefaultEnvironment = SPV_ENV_UNIVERSAL_1_6;
 
-// Extract a string literal from a given range.
-// Copies all the characters from `begin` to the first '\0' it encounters, while
-// removing escape patterns.
-// Not finding a '\0' before reaching `end` fails the extraction.
-//
-// Returns `true` if the extraction succeeded.
-// `output` value is undefined if false is returned.
-spv_result_t ExtractStringLiteral(const spv_position_t& loc, const char* begin,
-                                  const char* end, std::string* output) {
-  size_t sourceLength = std::distance(begin, end);
-  std::string escapedString;
-  escapedString.resize(sourceLength);
-
-  size_t writeIndex = 0;
-  size_t readIndex = 0;
-  for (; readIndex < sourceLength; writeIndex++, readIndex++) {
-    const char read = begin[readIndex];
-    if (read == '\0') {
-      escapedString.resize(writeIndex);
-      output->append(escapedString);
-      return SPV_SUCCESS;
-    }
-
-    if (read == '\\') {
-      ++readIndex;
-    }
-    escapedString[writeIndex] = begin[readIndex];
-  }
-
-  spvtools::Error(spvtools::utils::CLIMessageConsumer, "", loc,
-                  "Missing NULL terminator for literal string.");
-  return SPV_ERROR_INVALID_BINARY;
-}
-
 spv_result_t extractOpString(const spv_position_t& loc,
                              const spv_parsed_instruction_t& instruction,
                              std::string* output) {
@@ -73,12 +40,8 @@ spv_result_t extractOpString(const spv_position_t& loc
     return SPV_ERROR_INVALID_BINARY;
   }
 
-  const auto& operand = instruction.operands[1];
-  const char* stringBegin =
-      reinterpret_cast<const char*>(instruction.words + operand.offset);
-  const char* stringEnd = reinterpret_cast<const char*>(
-      instruction.words + operand.offset + operand.num_words);
-  return ExtractStringLiteral(loc, stringBegin, stringEnd, output);
+  *output = spvDecodeLiteralStringOperand(instruction, 1);
+  return SPV_SUCCESS;
 }
 
 spv_result_t extractOpSourceContinued(
@@ -93,12 +56,8 @@ spv_result_t extractOpSourceContinued(
     return SPV_ERROR_INVALID_BINARY;
   }
 
-  const auto& operand = instruction.operands[0];
-  const char* stringBegin =
-      reinterpret_cast<const char*>(instruction.words + operand.offset);
-  const char* stringEnd = reinterpret_cast<const char*>(
-      instruction.words + operand.offset + operand.num_words);
-  return ExtractStringLiteral(loc, stringBegin, stringEnd, output);
+  *output = *output + spvDecodeLiteralStringOperand(instruction, 0);
+  return SPV_SUCCESS;
 }
 
 spv_result_t extractOpSource(const spv_position_t& loc,
@@ -124,11 +83,8 @@ spv_result_t extractOpSource(const spv_position_t& loc
     return SPV_SUCCESS;
   }
 
-  const char* stringBegin =
-      reinterpret_cast<const char*>(instruction.words + 4);
-  const char* stringEnd =
-      reinterpret_cast<const char*>(instruction.words + instruction.num_words);
-  return ExtractStringLiteral(loc, stringBegin, stringEnd, code);
+  *code = spvDecodeLiteralStringOperand(instruction, 3);
+  return SPV_SUCCESS;
 }
 
 }  // namespace
