--- mix.exs.orig	2017-02-07 20:49:06 UTC
+++ mix.exs
@@ -4,10 +4,9 @@ defmodule LagerLogger.Mixfile do
   def project do
     [app: :lager_logger,
      version: "1.0.4",
-     elixir: ">= 1.1.0 and < 1.5.0",
+     elixir: ">= 1.1.0 and < 1.6.0",
      package: package(),
-     description: description(),
-     deps: deps()]
+     description: description()]
   end
 
   defp package do
