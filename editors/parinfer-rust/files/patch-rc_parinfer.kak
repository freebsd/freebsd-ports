--- rc/parinfer.kak.orig	2019-01-26 21:44:33 UTC
+++ rc/parinfer.kak
@@ -72,7 +72,5 @@ hook -group parinfer global WinSetOption filetype=(clo
     hook -group parinfer window NormalKey .* %{ parinfer -if-enabled -smart }
     hook -group parinfer window InsertChar (?!\n).* %{ parinfer -if-enabled -smart }
     hook -group parinfer window InsertDelete .* %{ parinfer -if-enabled -smart }
-}
-hook -group parinfer global WinSetOption filetype=(!clojure|lisp|scheme).* %{
-    remove-hooks window parinfer
+    hook -once -always window WinSetOption filetype=.* %{ remove-hooks window parinfer }
 }
