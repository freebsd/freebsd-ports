--- mix.exs.orig	2015-07-08 05:55:21 UTC
+++ mix.exs
@@ -24,7 +24,6 @@ defmodule Mongo.Mixfile do
   # Returns the list of dependencies for prod
   defp deps(:prod) do
     [
-      bson: "~> 0.4.3"
     ]
   end
 
