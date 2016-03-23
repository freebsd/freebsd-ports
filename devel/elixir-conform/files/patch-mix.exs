--- mix.exs.orig	2016-03-01 19:24:43 UTC
+++ mix.exs
@@ -14,8 +14,7 @@ defmodule Conform.Mixfile do
      escript: [main_module: Conform],
      compilers: compilers(@do_peg_compile?),
      description: description,
-     package: package,
-     deps: deps]
+     package: package]
   end
 
   def application do
