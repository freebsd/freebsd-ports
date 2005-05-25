--- ghc/utils/hsc2hs/Main.hs.orig	Tue May 24 21:37:37 2005
+++ ghc/utils/hsc2hs/Main.hs	Tue May 24 21:37:39 2005
@@ -562,17 +562,17 @@ output flags name toks = do
         _                 -> return ()
     
     when needsH $ writeFile outHName $
-        "#ifndef "++includeGuard++"\n\ 
-        \#define "++includeGuard++"\n\ 
-        \#if " ++
-	"__GLASGOW_HASKELL__ && __GLASGOW_HASKELL__ < 409\n\ 
-        \#include <Rts.h>\n\ 
-        \#endif\n\ 
-        \#include <HsFFI.h>\n\ 
-        \#if __NHC__\n\ 
-        \#undef HsChar\n\ 
-        \#define HsChar int\n\ 
-        \#endif\n"++
+        "#ifndef "++includeGuard++"\n"++
+        "#define "++includeGuard++"\n"++
+        "#if " ++
+	"__GLASGOW_HASKELL__ && __GLASGOW_HASKELL__ < 409\n"++
+        "#include <Rts.h>\n"++
+        "#endif\n"++
+        "#include <HsFFI.h>\n"++
+        "#if __NHC__\n"++
+        "#undef HsChar\n"++
+        "#define HsChar int\n"++
+        "#endif\n"++
         concatMap outFlagH flags++
         concatMap outTokenH specials++
         "#endif\n"
@@ -615,8 +615,8 @@ outHeaderCProg (pos, key, arg) = case ke
         (header, _:body) -> case break isSpace header of
             (name, args) ->
                 outCLine pos++
-                "#define hsc_"++name++"("++dropWhile isSpace args++") \ 
-                \printf ("++joinLines body++");\n"
+                "#define hsc_"++name++"("++dropWhile isSpace args++") "++
+                "printf ("++joinLines body++");\n"
     _ -> ""
     where
     joinLines = concat . intersperse " \\\n" . lines
@@ -624,11 +624,11 @@ outHeaderCProg (pos, key, arg) = case ke
 outHeaderHs :: [Flag] -> Maybe String -> [(SourcePos, String, String)] -> String
 outHeaderHs flags inH toks =
     "#if " ++
-    "__GLASGOW_HASKELL__ && __GLASGOW_HASKELL__ < 409\n\ 
-    \    printf (\"{-# OPTIONS -optc-D" ++
-    "__GLASGOW_HASKELL__=%d #-}\\n\", \ 
-    \__GLASGOW_HASKELL__);\n\ 
-    \#endif\n"++
+    "__GLASGOW_HASKELL__ && __GLASGOW_HASKELL__ < 409\n"++
+    "    printf (\"{-# OPTIONS -optc-D" ++
+    "__GLASGOW_HASKELL__=%d #-}\\n\", "++
+    "__GLASGOW_HASKELL__);\n"++
+    "#endif\n"++
     case inH of
         Nothing -> concatMap outFlag flags++concatMap outSpecial toks
         Just f  -> outOption ("-#include \""++f++"\"")
@@ -686,12 +686,12 @@ outEnum arg =
                     (enum, rest) -> let
                         this = case break (== '=') $ dropWhile isSpace enum of
                             (name, []) ->
-                                "    hsc_enum ("++t++", "++f++", \ 
-                                \hsc_haskellize (\""++name++"\"), "++
+                                "    hsc_enum ("++t++", "++f++", "++
+                                "hsc_haskellize (\""++name++"\"), "++
                                 name++");\n"
                             (hsName, _:cName) ->
-                                "    hsc_enum ("++t++", "++f++", \ 
-                                \printf (\"%s\", \""++hsName++"\"), "++
+                                "    hsc_enum ("++t++", "++f++", "++
+                                "printf (\"%s\", \""++hsName++"\"), "++
                                 cName++");\n"
                         in this++enums rest
                 in enums afterF
@@ -712,9 +712,9 @@ outTokenH (pos, key, arg) =
             's':'t':'r':'u':'c':'t':' ':_ -> arg++"\n"
             't':'y':'p':'e':'d':'e':'f':' ':_ -> arg++"\n"
             'i':'n':'l':'i':'n':'e':' ':_ ->
-                "#ifdef __GNUC__\n\ 
-                \extern\n\ 
-                \#endif\n"++
+                "#ifdef __GNUC__\n"++
+                "extern\n"++
+                "#endif\n"++
                 arg++"\n"
             _ -> "extern "++header++";\n"
             where header = takeWhile (\c -> c /= '{' && c /= '=') arg
@@ -731,13 +731,13 @@ outTokenC (pos, key, arg) =
 		case span (\c -> c /= '{' && c /= '=') arg' of
 		(header, body) ->
 		    outCLine pos++
-		    "#ifndef __GNUC__\n\ 
-		    \extern inline\n\ 
-		    \#endif\n"++
+		    "#ifndef __GNUC__\n"++
+		    "extern inline\n"++
+		    "#endif\n"++
 		    header++
-		    "\n#ifndef __GNUC__\n\ 
-		    \;\n\ 
-		    \#else\n"++
+		    "\n#ifndef __GNUC__\n"++
+		    ";\n"++
+		    "#else\n"++
 		    body++
 		    "\n#endif\n"
             _ -> outCLine pos++arg++"\n"
