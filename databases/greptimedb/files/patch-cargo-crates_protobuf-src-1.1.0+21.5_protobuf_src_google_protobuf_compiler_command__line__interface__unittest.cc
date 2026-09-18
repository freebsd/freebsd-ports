--- cargo-crates/protobuf-src-1.1.0+21.5/protobuf/src/google/protobuf/compiler/command_line_interface_unittest.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/protobuf-src-1.1.0+21.5/protobuf/src/google/protobuf/compiler/command_line_interface_unittest.cc
@@ -2386,6 +2386,36 @@ TEST_F(CommandLineInterfaceTest, ParserWarnings) {
       "See https://developers.google.com/protocol-buffers/docs/style");
 }
 
+TEST_F(CommandLineInterfaceTest, ParserWarnings) {
+  // Test that parser warnings are propagated. See #9343.
+
+  CreateTempFile("foo.proto",
+                 "syntax = \"proto2\";\n"
+                 "message bad_to_the_bone {};\n");
+
+  Run("protocol_compiler --test_out=$tmpdir "
+      "--proto_path=$tmpdir foo.proto");
+  ExpectCapturedStderrSubstringWithZeroReturnCode(
+      "foo.proto:2:25: warning: Message name should be in UpperCamelCase. "
+      "Found: bad_to_the_bone. "
+      "See https://developers.google.com/protocol-buffers/docs/style");
+}
+
+TEST_F(CommandLineInterfaceTest, ParserWarnings) {
+  // Test that parser warnings are propagated. See #9343.
+
+  CreateTempFile("foo.proto",
+                 "syntax = \"proto2\";\n"
+                 "message bad_to_the_bone {};\n");
+
+  Run("protocol_compiler --test_out=$tmpdir "
+      "--proto_path=$tmpdir foo.proto");
+  ExpectCapturedStderrSubstringWithZeroReturnCode(
+      "foo.proto:2:25: warning: Message name should be in UpperCamelCase. "
+      "Found: bad_to_the_bone. "
+      "See https://developers.google.com/protocol-buffers/docs/style");
+}
+
 // -------------------------------------------------------------------
 // Flag parsing tests
 
