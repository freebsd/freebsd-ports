--- RPC/RPC.xs.orig	2000-06-13 17:17:19 UTC
+++ RPC/RPC.xs
@@ -153,7 +153,7 @@ int arg;
 	break;
     case '_':
 	if (strEQ(name, "_ACECLIENT_"))
-#ifdef _ACECLIENT_
+#if 0
 	    return _ACECLIENT_;
 #else
 	    goto not_there;
