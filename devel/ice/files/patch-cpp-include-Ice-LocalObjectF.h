--- cpp.orig/include/Ice/LocalObjectF.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/include/Ice/LocalObjectF.h	2012-03-04 20:14:52.000000000 +0100
@@ -18,12 +18,6 @@
 {
 
 class LocalObject;
-
-}
-
-namespace IceInternal
-{
-
 ICE_API IceUtil::Shared* upCast(::Ice::LocalObject*);
 
 }
