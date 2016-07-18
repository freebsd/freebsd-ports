--- mix.exs.orig	2016-07-16 12:12:32 UTC
+++ mix.exs
@@ -13,8 +13,7 @@ defmodule Coverex.Mixfile do
      homepage_url: "https://github.com/alfert/coverex",
      docs: [readme: "README.md"],
      description: description(),
-     test_coverage: [tool: Coverex.Task, coveralls: true, ignore_modules: []],
-     deps: deps()]
+     test_coverage: [tool: Coverex.Task, coveralls: true, ignore_modules: []]]
   end
 
   # Configuration for the OTP application
