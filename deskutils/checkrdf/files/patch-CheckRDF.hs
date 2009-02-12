--- CheckRDF.hs.orig	2007-03-02 19:13:07.000000000 +0100
+++ CheckRDF.hs	2009-01-26 18:28:22.000000000 +0100
@@ -24,9 +24,12 @@
 import Directory ( doesFileExist, getPermissions, readable, removeFile )
 import List ( partition, intersperse, groupBy, sortBy)
 import Time (getClockTime,toCalendarTime,calendarTimeToString)
+import Char (toLower)
 
 import Text.XML.HaXml.Types
 import Text.XML.HaXml.Parse         (xmlParse)
+import Text.XML.HaXml.Posn          (noPos)
+import Text.XML.HaXml.Xtract.Lex    (lexXtract)
 import Text.XML.HaXml.Xtract.Parse  (parseXtract)
 import Text.PrettyPrint.HughesPJ    (render, vcat)
 import Text.XML.HaXml.Pretty        (content)
@@ -52,15 +55,15 @@
 mkNewRDF :: RDFConfig -> FilePath -> String -> RDF
 mkNewRDF config filename contents =
      let elem = getElem $ xmlParse filename contents
-         ct = render $ vcat $ map content $ dfilter (parseXtract "channel/title/-") elem
-         cl = render $ vcat $ map content $ dfilter (parseXtract "channel/link/-")  elem
-         len1 = length $ dfilter (parseXtract "//item/title") elem
-         len2 = length $ dfilter (parseXtract "//item/link") elem
+         ct = render $ vcat $ map content $ dfilter (parseXtract (lexXtract (map toLower) "channel/title/-")) elem
+         cl = render $ vcat $ map content $ dfilter (parseXtract (lexXtract (map toLower) "channel/link/-"))  elem
+         len1 = length $ dfilter (parseXtract (lexXtract (map toLower) "//item/title")) elem
+         len2 = length $ dfilter (parseXtract (lexXtract (map toLower) "//item/link")) elem
          items = if len1 == len2
            then (map (\ i -> (render $ vcat $ map content $
-                                dfilter (parseXtract ("//item/title["++i++"]/-")) elem
+                                dfilter (parseXtract (lexXtract (map toLower) ("//item/title["++i++"]/-"))) elem
                              ,render $ vcat $ map content $
-                                dfilter (parseXtract ("//item/link["++i++"]/-" )) elem)
+                                dfilter (parseXtract (lexXtract (map toLower) ("//item/link["++i++"]/-" ))) elem)
                      )
                      $ map show [0..len1-1])
            else []
@@ -69,7 +72,7 @@
              ,clink  = cl
              ,citems = rdfitems
              }
- where getElem (Document _ _ e _) = CElem e
+ where getElem (Document _ _ e _) = CElem e noPos
        dfilter f = \ x -> f x x
        mkRDFItem (t,l) = RDFItem {title = substituteChar '\n' ' ' $ rmCDATA t
                                  ,link  = filter (/='\n') $ rmCDATA l
