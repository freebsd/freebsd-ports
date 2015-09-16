--- mix.exs.orig	2015-07-01 10:24:04 UTC
+++ mix.exs
@@ -21,8 +21,7 @@ defmodule Decimal.Mixfile do
   end
 
   defp deps do
-    [{:ex_doc, only: :dev},
-     {:earmark, only: :dev}]
+    []
   end
 
   defp description do
