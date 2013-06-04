--- ./CheckRDF.hs.orig	2007-03-02 19:13:07.000000000 +0100
+++ ./CheckRDF.hs	2013-05-01 00:09:20.000000000 +0200
@@ -18,15 +18,21 @@
 
 import RDFConfig
 
-import System (getArgs, exitWith, ExitCode(..),system,getEnv)
-import IO ( catch, openFile, IOMode(..), hIsEOF, hGetLine
+import System.Environment (getArgs, getEnv)
+import System.Process (system)
+import System.Exit (exitWith, ExitCode(..))
+import System.IO ( openFile, IOMode(..), hIsEOF, hGetLine
           , hPutStr, hClose, hFlush, stdin, Handle, hPutStrLn, hGetContents)
-import Directory ( doesFileExist, getPermissions, readable, removeFile )
-import List ( partition, intersperse, groupBy, sortBy)
-import Time (getClockTime,toCalendarTime,calendarTimeToString)
+import System.IO.Error ( catchIOError )
+import System.Directory ( doesFileExist, getPermissions, readable, removeFile )
+import Data.List ( partition, intersperse, groupBy, sortBy)
+import System.Time (getClockTime,toCalendarTime,calendarTimeToString)
+import Data.Char (toLower)
 
 import Text.XML.HaXml.Types
 import Text.XML.HaXml.Parse         (xmlParse)
+import Text.XML.HaXml.Posn          (noPos)
+import Text.XML.HaXml.Xtract.Lex    (lexXtract)
 import Text.XML.HaXml.Xtract.Parse  (parseXtract)
 import Text.PrettyPrint.HughesPJ    (render, vcat)
 import Text.XML.HaXml.Pretty        (content)
@@ -52,15 +58,15 @@
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
@@ -69,7 +75,7 @@
              ,clink  = cl
              ,citems = rdfitems
              }
- where getElem (Document _ _ e _) = CElem e
+ where getElem (Document _ _ e _) = CElem e noPos
        dfilter f = \ x -> f x x
        mkRDFItem (t,l) = RDFItem {title = substituteChar '\n' ' ' $ rmCDATA t
                                  ,link  = filter (/='\n') $ rmCDATA l
@@ -109,9 +115,9 @@
     if iseof
      then return []
      else do line <- hGetLine h
-             mrdf <- catch (do rdf <- (readIO line :: IO RDF)
-                               return $ Just rdf)
-                           (const $ return Nothing)
+             mrdf <- catchIOError (do rdf <- (readIO line :: IO RDF)
+                                      return $ Just rdf)
+                                  (const $ return Nothing)
              maybe (return [])
                    (\rdf -> do rdfs <- readRDFs h
                                return $! rdf : rdfs)
