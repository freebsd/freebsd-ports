--- lib/exprotobuf/field.ex.orig	2015-07-14 11:06:48 UTC
+++ lib/exprotobuf/field.ex
@@ -1,6 +1,6 @@
 defmodule Protobuf.Field do
-  @record Record.Extractor.extract(:"?gpb_field", from: Path.join([Mix.Project.deps_path, "gpb", "include", "gpb.hrl"]))
+  @record Record.Extractor.extract(:"field", from: Path.join([Mix.Project.deps_path, "gpb", "include", "gpb.hrl"]))
   defstruct @record
 
   def record, do: @record
-end
\ No newline at end of file
+end
