--- mix.exs.orig	2015-07-21 03:09:23 UTC
+++ mix.exs
@@ -13,8 +13,7 @@ defmodule Coverex.Mixfile do
      homepage_url: "https://github.com/alfert/coverex",
      docs: [readme: "README.md"],
      description: description,
-     test_coverage: [tool: Coverex.Task, coveralls: true],
-     deps: deps]
+     test_coverage: [tool: Coverex.Task, coveralls: true]]
   end
 
   # Configuration for the OTP application
