--- src/Language/PureScript/Names.hs.orig	2020-05-23 12:43:53 UTC
+++ src/Language/PureScript/Names.hs
@@ -132,6 +132,9 @@ data OpNameType = ValueOpName | TypeOpName | AnyOpName
 eraseOpName :: OpName a -> OpName 'AnyOpName
 eraseOpName = OpName . runOpName
 
+coerceOpName :: OpName a -> OpName b
+coerceOpName = OpName . runOpName
+
 -- |
 -- Proper names, i.e. capitalized names for e.g. module names, type//data constructors.
 --
