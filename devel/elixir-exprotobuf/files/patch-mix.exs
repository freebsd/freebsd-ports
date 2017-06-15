--- mix.exs.orig	2017-02-08 16:14:01 UTC
+++ mix.exs
@@ -10,7 +10,7 @@ defmodule Protobuf.Mixfile do
      build_embedded: Mix.env == :prod,
      start_permanent: Mix.env == :prod,
      consolidate_protocols: Mix.env == :prod,
-     deps: deps()]
+     ]
   end
 
   def application do
