--- source/binary.cpp.orig	2026-07-08 19:46:47 UTC
+++ source/binary.cpp
@@ -181,7 +181,7 @@ class Parser {
   // Returns the endian-corrected word at the given position.
   uint32_t peekAt(size_t index) const {
     assert(index < _.num_words);
-    return spvFixWord(_.words[index], _.endian);
+    return _.native_words[index];
   }
 
   // Data members
@@ -230,6 +230,7 @@ class Parser {
     // Is the SPIR-V binary in a different endianness from the host native
     // endianness?
     bool requires_endian_conversion;
+    std::unique_ptr<uint32_t[]> native_words;
     // Set by parseOperand when LookupOperand fails for an enum operand and
     // handle_unknown_opcodes_ is set.  Signals parseInstruction to discard
     // the partially-decoded instruction and re-emit it as raw OpUnknown data.
@@ -279,6 +280,9 @@ spv_result_t Parser::parseModule() {
                         << _.words[0] << "'.";
   }
   _.requires_endian_conversion = !spvIsHostEndian(_.endian);
+  _.native_words = std::make_unique<uint32_t[]>(_.num_words);
+  for (size_t i = 0; i < _.num_words; i++)
+    _.native_words[i] = _.requires_endian_conversion ? spvFixWord(_.words[i], _.endian) : _.words[i];
 
   // Process the header.
   spv_header_t header;
@@ -495,10 +499,6 @@ spv_result_t Parser::parseOperand(size_t inst_offset,
 
   const uint32_t word = peek();
 
-  // Do the words in this operand have to be converted to native endianness?
-  // True for all but literal strings.
-  bool convert_operand_endianness = true;
-
   switch (type) {
     case SPV_OPERAND_TYPE_TYPE_ID:
       if (!word)
@@ -664,7 +664,7 @@ spv_result_t Parser::parseOperand(size_t inst_offset,
     case SPV_OPERAND_TYPE_OPTIONAL_LITERAL_STRING: {
       const size_t max_words = _.num_words - _.word_index;
       std::string string =
-          spvtools::utils::MakeString(_.words + _.word_index, max_words, false);
+          spvtools::utils::MakeString(_.native_words.get() + _.word_index, max_words, false);
 
       if (string.length() == max_words * 4)
         return exhaustedInputDiagnostic(inst_offset, opcode, type);
@@ -870,17 +870,8 @@ spv_result_t Parser::parseOperand(size_t inst_offset,
 
   if (_.requires_endian_conversion) {
     // Copy instruction words.  Translate to native endianness as needed.
-    if (convert_operand_endianness) {
-      const spv_endianness_t endianness = _.endian;
-      std::transform(_.words + _.word_index, _.words + index_after_operand,
-                     std::back_inserter(*words),
-                     [endianness](const uint32_t raw_word) {
-                       return spvFixWord(raw_word, endianness);
-                     });
-    } else {
-      words->insert(words->end(), _.words + _.word_index,
-                    _.words + index_after_operand);
-    }
+      words->insert(words->end(), _.native_words.get() + _.word_index,
+                    _.native_words.get() + index_after_operand);
   }
 
   // Advance past the operand.
