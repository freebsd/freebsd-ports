--- mix.exs.orig	2015-07-02 22:58:50 UTC
+++ mix.exs
@@ -23,9 +23,7 @@ defmodule Timex.Mixfile do
   end
 
   def deps do
-    [{:tzdata, "~> 0.1.6"},
-     {:earmark, "~> 0.1", only: :dev},
-     {:ex_doc, "~> 0.5", only: :dev}]
+    []
   end
 
 end
