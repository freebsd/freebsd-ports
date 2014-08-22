--- ./RPC/RPC.xs.orig	2014-08-21 20:31:10.000000000 -0400
+++ ./RPC/RPC.xs	2014-08-21 20:31:34.000000000 -0400
@@ -153,7 +153,7 @@
 	break;
     case '_':
 	if (strEQ(name, "_ACECLIENT_"))
-#ifdef _ACECLIENT_
+#if 0
 	    return _ACECLIENT_;
 #else
 	    goto not_there;
