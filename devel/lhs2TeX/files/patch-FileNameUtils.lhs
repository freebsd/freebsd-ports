--- ./FileNameUtils.lhs.orig	2008-10-24 10:50:41.000000000 +0200
+++ ./FileNameUtils.lhs	2009-11-08 01:19:19.000000000 +0100
@@ -13,7 +13,7 @@
 > import System.Environment
 > import Data.List
 > import Control.Monad (filterM)
-> import Control.Exception      (  try, catch )
+> import Control.Exception      (  try, catch, IOException )
 > import System.FilePath
 > import System.Info
 
@@ -86,7 +86,7 @@
 >                                             d''' <- mapM descendFrom d''
 >                                             return (s : concat d''')
 >                                        )
->                                        (const $ return [s])
+>                                        ((const $ return [s])::(IOError -> IO [String]))
 
 > expandEnvironment             :: String -> IO [String]
 > expandEnvironment s           =  case break (=='{') s of
@@ -95,7 +95,7 @@
 >                                                    (e,"") -> return [s]
 >                                                    (e,'}':r') -> findEnvironment e s' r'
 >   where findEnvironment       :: String -> String -> String -> IO [String]
->         findEnvironment e a o =  do er <- try (getEnv e)
+>         findEnvironment e a o =  do er <- (try (getEnv e))::(IO (Either IOException String))
 >                                     return $ either (const [])
 >                                                     (map (\x -> a ++ x ++ o) . splitOn isSearchPathSeparator)
 >                                                     er
@@ -116,8 +116,8 @@
 >                               =  cs
 >         | otherwise           =  addTrailingPathSeparator cs
 >   t f                         =  catch (readFile f >>= \x -> return (x,f))
->                                        (\_ -> ioError $ userError $ "File `" ++ fn ++ "' not found.\n")
+>                                        ((\_ -> ioError $ userError $ "File `" ++ fn ++ "' not found.\n")::(IOError -> IO (String,FilePath)))
 >   s []                        =  ioError 
 >                               $  userError $ "File `" ++ fn ++ "' not found in search path:\n" ++ showpath
->   s (x:xs)                    =  catch x (\_ -> s xs)
+>   s (x:xs)                    =  catch x ((\_ -> s xs)::(IOError -> IO (String,FilePath)))
 >   showpath                    =  concatMap (\x -> "   " ++ x ++ "\n") p
