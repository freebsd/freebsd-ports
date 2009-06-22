
$FreeBSD$

--- mcs/tools/security/certmgr.cs.orig
+++ mcs/tools/security/certmgr.cs
@@ -492,8 +492,11 @@
 			ObjectType type = ObjectType.None;
 
 			int n = 1;
-			if (action != Action.Ssl)
-				type = GetObjectType (args [n++]);
+			if (action != Action.Ssl) {
+				type = GetObjectType (args [n]);
+				if (type != ObjectType.None)
+					n++;
+			}
 			
 			bool verbose = (GetCommand (args [n]) == "V");
 			if (verbose)
