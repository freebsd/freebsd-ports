--- mix.exs.orig	2018-01-21 13:38:06 UTC
+++ mix.exs
@@ -7,7 +7,6 @@ defmodule Distillery.Mixfile do
      elixir: "~> 1.3",
      build_embedded: Mix.env == :prod,
      start_permanent: Mix.env == :prod,
-     deps: deps(),
      description: description(),
      package: package(),
      docs: docs(),
