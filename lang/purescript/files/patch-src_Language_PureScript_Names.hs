--- src/Language/PureScript/Names.hs.orig	2019-11-02 17:39:14 UTC
+++ src/Language/PureScript/Names.hs
@@ -126,6 +126,9 @@ data OpNameType = ValueOpName | TypeOpName | AnyOpName
 eraseOpName :: OpName a -> OpName 'AnyOpName
 eraseOpName = OpName . runOpName
 
+coerceOpName :: OpName a -> OpName b
+coerceOpName = OpName . runOpName
+
 -- |
 -- Proper names, i.e. capitalized names for e.g. module names, type//data constructors.
 --
