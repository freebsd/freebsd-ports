--- _support/makegen.go.orig	2020-03-27 21:35:27 UTC
+++ _support/makegen.go
@@ -339,7 +339,7 @@ func (gm *gitalyMake) BundleFlags() string {
 		return "--no-deployment"
 	}
 
-	return "--deployment"
+	return "--local"
 }
 
 func (gm *gitalyMake) IsGDK() bool {
