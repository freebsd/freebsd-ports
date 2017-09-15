--- src/dobject.h.orig	2017-06-22 13:58:35 UTC
+++ src/dobject.h
@@ -198,7 +198,7 @@ class DObject (protected)
 	enum { MetaClassNum = CLASSREG_PClass };
 
 	// Per-instance variables. There are four.
-#ifdef _DEBUG
+#ifndef NDEBUG
 public:
 	enum
 	{
