--- swift/docs/proposals/InitializerInheritance.rst.orig	2017-04-21 21:18:29.000000000 +0000
+++ swift/docs/proposals/InitializerInheritance.rst	2018-01-22 11:07:00.559384000 +0000
@@ -135,7 +135,7 @@
 Complete object initializers
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Introduce the notion of a complete object initializer, which is
-written as an initializer with ``Self`` as its return type [#], e.g.::
+written as an initializer with ``Self`` as its return type [#]_, e.g.::
 
   init() -> Self {
     // ...
