import Data.List
import System.Environment

main = do
  [pkgplist] <- getArgs
  plistLines <- lines <$> readFile pkgplist
  mapM (putStrLn . processLine2 . processLine1) plistLines

processLine1 l
  | "%%DYNAMIC%%" `isPrefixOf` l ||
    "%%PROFILE%%" `isPrefixOf` l ||
    "%%GMP%%" `isPrefixOf` l ||
    "%%SIMPLE%%" `isPrefixOf` l = l

  | ".dyn_hi" `isSuffixOf` l ||
    "/ghc-iserv-dyn" `isSuffixOf` l ||
    ".so" `isSuffixOf` l = "%%DYNAMIC%%" ++ l

  | ".p_hi" `isSuffixOf` l ||
    "/ghc-iserv-prof" `isSuffixOf` l ||
    ".p_o" `isSuffixOf` l  ||
    "_p.a" `isSuffixOf` l = "%%PROFILE%%" ++ l

  | otherwise = l

processLine2 l
  | "%%GMP%%" `isPrefixOf` l ||
    "%%SIMPLE%%" `isPrefixOf` l = l
  | "/integer-gmp-" `isInfixOf` l = "%%GMP%%" ++ l
  | "/integer-simple-" `isInfixOf` l = "%%SIMPLE%%" ++ l
  | "/libCffi" `isInfixOf` l = "%%NODYNAMIC%%" ++ l
  | otherwise = l
