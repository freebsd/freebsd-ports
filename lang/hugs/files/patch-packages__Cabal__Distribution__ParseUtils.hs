--- ./packages/Cabal/Distribution/ParseUtils.hs.orig	2006-09-21 00:29:42.000000000 +0200
+++ ./packages/Cabal/Distribution/ParseUtils.hs	2014-07-01 04:38:40.000000000 +0200
@@ -48,11 +48,11 @@
         locatedErrorMsg, showError, syntaxError, warning,
 	runP, ParseResult(..),
 	StanzaField(..), splitStanzas, Stanza, singleStanza,
-	parseFilePathQ, parseTokenQ,
+	parseFilePathQ, parseTokenQ, parseTokenQ',
 	parseModuleNameQ, parseDependency, parseOptVersion,
 	parsePackageNameQ, parseVersionRangeQ,
 	parseTestedWithQ, parseLicenseQ, parseExtensionQ, parseCommaList, parseOptCommaList,
-	showFilePath, showToken, showTestedWith, showDependency, showFreeText,
+	showFilePath, showToken, showToken', showTestedWith, showDependency, showFreeText,
 	simpleField, listField, commaListField, optsField, 
 	parseReadS, parseQuoted,
   ) where
@@ -274,6 +274,9 @@
 parseTokenQ :: ReadP r String
 parseTokenQ = parseReadS <++ munch1 (\x -> not (isSpace x) && x /= ',')
 
+parseTokenQ' :: ReadP r String
+parseTokenQ' = parseReadS <++ munch1 (not . isSpace)
+
 parseCommaList :: ReadP r a -- ^The parser for the stuff between commas
                -> ReadP r [a]
 parseCommaList p = sepBy p separator
@@ -300,6 +303,12 @@
  | otherwise            = text (show str)
   where dodgy c = isSpace c || c == ','
 
+showToken' :: String -> Doc
+showToken' str
+ | not (any isSpace str) &&
+   not (null str)       = text str
+ | otherwise            = text (show str)
+
 showTestedWith :: (CompilerFlavor,VersionRange) -> Doc
 showTestedWith (compiler,version) = text (show compiler ++ " " ++ showVersionRange version)
 
