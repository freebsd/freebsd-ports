--- go.mod.orig	2023-03-25 01:23:43 UTC
+++ go.mod
@@ -1,21 +1,30 @@
 module github.com/naggie/dstask
 
-go 1.16
+go 1.17
 
 require (
 	github.com/BurntSushi/toml v0.3.1
 	github.com/gofrs/uuid v3.3.0+incompatible
-	github.com/google/go-cmp v0.5.2 // indirect
 	github.com/mattn/go-isatty v0.0.12
 	github.com/mvdan/xurls v1.1.0
-	github.com/pkg/errors v0.9.1 // indirect
 	github.com/shurcooL/githubv4 v0.0.0-20200928013246-d292edc3691b
-	github.com/shurcooL/graphql v0.0.0-20200928012149-18c5c3165e3a // indirect
 	github.com/sirupsen/logrus v1.7.0
 	github.com/stretchr/testify v1.6.1
-	golang.org/x/net v0.0.0-20201021035429-f5854403a974 // indirect
 	golang.org/x/oauth2 v0.0.0-20201109201403-9fd604954f58
-	golang.org/x/sys v0.0.0-20210119212857-b64e53b001e4
+	golang.org/x/sys v0.6.0
 	gopkg.in/yaml.v2 v2.3.0
 	gotest.tools v2.2.0+incompatible
+)
+
+require (
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/golang/protobuf v1.4.2 // indirect
+	github.com/google/go-cmp v0.5.2 // indirect
+	github.com/pkg/errors v0.9.1 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/shurcooL/graphql v0.0.0-20200928012149-18c5c3165e3a // indirect
+	golang.org/x/net v0.0.0-20201021035429-f5854403a974 // indirect
+	google.golang.org/appengine v1.6.6 // indirect
+	google.golang.org/protobuf v1.25.0 // indirect
+	gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c // indirect
 )
