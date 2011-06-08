--- lib/nodekits/src/nodekits/SoNkCatalog.c++.orig	2011-06-08 14:36:19.000000000 +0200
+++ lib/nodekits/src/nodekits/SoNkCatalog.c++	2011-06-08 14:36:30.000000000 +0200
@@ -336,7 +336,7 @@
     void *castPNum;
 
     if ( partNameDict.find( (unsigned long) theName.getString(), castPNum ) )
-#if (_MIPS_SZPTR == 64 || __ia64)
+#if (_MIPS_SZPTR == 64 || __ia64 || __amd64__)
 	return ( (int) ((long) castPNum) );  // System long
 #else
 	return ( (int) castPNum );
