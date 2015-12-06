--- mix.exs.orig	2015-12-02 23:57:26 UTC
+++ mix.exs
@@ -14,8 +14,7 @@ defmodule Conform.Mixfile do
      escript: [main_module: Conform],
      compilers: compilers(@do_peg_compile?),
      description: description,
-     package: package,
-     deps: deps(@do_peg_compile?)]
+     package: package]
   end
 
   def application do
