--- scripts/genie.lua.orig	2023-05-24 01:14:32 UTC
+++ scripts/genie.lua
@@ -1238,6 +1238,11 @@ configuration { "netbsd" }
 			"LinkSupportCircularDependencies",
 		}
 
+configuration { "freebsd" }
+		flags {
+			"LinkSupportCircularDependencies",
+		}
+
 configuration { "osx*" }
 		links {
 			"pthread",
