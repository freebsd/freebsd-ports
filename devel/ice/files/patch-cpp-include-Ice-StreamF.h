--- cpp.orig/include/Ice/StreamF.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/include/Ice/StreamF.h	2012-03-04 20:14:52.000000000 +0100
@@ -19,12 +19,6 @@
 
 class InputStream;
 class OutputStream;
-
-}
-
-namespace IceInternal
-{
-
 ICE_API IceUtil::Shared* upCast(::Ice::InputStream*);
 ICE_API IceUtil::Shared* upCast(::Ice::OutputStream*);
 
