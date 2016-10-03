--- mix.exs.orig	2016-10-03 08:27:45 UTC
+++ mix.exs
@@ -7,7 +7,6 @@ defmodule Decimal.Mixfile do
     [app: :decimal,
      version: @version,
      elixir: "~> 1.0",
-     deps: deps(),
      name: "Decimal",
      source_url: "https://github.com/ericmj/decimal",
      docs: [source_ref: "v#{@version}", main: "readme", extras: ["README.md"]],
