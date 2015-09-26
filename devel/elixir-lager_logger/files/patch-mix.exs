--- mix.exs.orig	2015-09-26 08:36:49 UTC
+++ mix.exs
@@ -4,10 +4,8 @@ defmodule LagerLogger.Mixfile do
   def project do
     [app: :lager_logger,
      version: "1.0.0",
-     elixir: "~> 1.0.0",
      package: package,
-     description: description,
-     deps: deps]
+     description: description]
   end
 
   defp package do
