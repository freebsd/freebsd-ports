--- _support/makegen.go.orig	2020-04-20 15:09:52 UTC
+++ _support/makegen.go
@@ -318,7 +318,7 @@ func (gm *gitalyMake) BundleFlags() string {
 		return "--no-deployment"
 	}
 
-	return "--deployment"
+	return "--local"
 }
 
 func (gm *gitalyMake) IsGDK() bool {
