--- mix.exs.orig	2016-06-28 18:41:37 UTC
+++ mix.exs
@@ -4,10 +4,9 @@ defmodule LagerLogger.Mixfile do
   def project do
     [app: :lager_logger,
      version: "1.0.3",
-     elixir: ">= 1.1.0 and <= 1.4.0",
+     elixir: ">= 1.1.0 and < 1.5.0",
      package: package,
-     description: description,
-     deps: deps]
+     description: description]
   end
 
   defp package do
