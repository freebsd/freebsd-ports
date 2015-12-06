--- mix.exs.orig	2015-12-06 21:51:08 UTC
+++ mix.exs
@@ -8,8 +8,7 @@ defmodule ConformExrm.Mixfile do
      build_embedded: Mix.env == :prod,
      start_permanent: Mix.env == :prod,
      package: package,
-     description: "Conform plugin for ExRM",
-     deps: deps]
+     description: "Conform plugin for ExRM"]
   end
 
   # Configuration for the OTP application
