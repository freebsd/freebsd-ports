--- mix.exs.orig	2017-02-08 09:05:33 UTC
+++ mix.exs
@@ -8,7 +8,6 @@ defmodule EXJSX.Mixfile do
       consolidate_protocols: Mix.env != :test,
       description: description(),
       package: package(),
-      deps: deps()
     ]
   end
 
