--- mix.exs.orig	2017-10-22 08:06:47 UTC
+++ mix.exs
@@ -8,7 +8,6 @@ defmodule Decimal.Mixfile do
       app: :decimal,
       version: @version,
       elixir: "~> 1.0",
-      deps: deps(),
       name: "Decimal",
       source_url: "https://github.com/ericmj/decimal",
       docs: [source_ref: "v#{@version}", main: "readme", extras: ["README.md"]],
