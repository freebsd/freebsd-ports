--- cabal-benchmarks/bench/CabalBenchmarks.hs.orig	2025-12-05 21:21:24 UTC
+++ cabal-benchmarks/bench/CabalBenchmarks.hs
@@ -17,9 +17,9 @@ main = defaultMain
 main :: IO ()
 main = defaultMain
     [ bgroup "parseGPD"
-        [ env (BS.readFile "Cabal/Cabal.cabal") $ \bs ->
+        [ env (BS.readFile "../Cabal/Cabal.cabal") $ \bs ->
           bench "Cabal" $ whnf parseGenericPackageDescriptionMaybe bs
-        , env (BS.readFile "cabal-benchmarks/cabal-benchmarks.cabal") $ \bs ->
+        , env (BS.readFile "../cabal-benchmarks/cabal-benchmarks.cabal") $ \bs ->
           bench "cabal-benchmarks" $ whnf parseGenericPackageDescriptionMaybe bs
         ]
 
