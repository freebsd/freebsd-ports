--- source/gtd/GirFunction.d.orig	2022-03-23 22:26:51 UTC
+++ source/gtd/GirFunction.d
@@ -1277,6 +1277,9 @@ final class GirFunction
 			if ( type.cType == "guchar*" )
 				return "char[]";
 
+			if ( type.cType == "gunichar2*" )
+				return "wchar[]";
+
 			if ( type.size > -1 )
 				size = to!string(type.size);
 
