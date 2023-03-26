--- go.mod.orig	2023-03-26 22:32:34 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/muesli/gitty
 
-go 1.15
+go 1.17
 
 require (
 	code.gitea.io/sdk/gitea v0.15.1
@@ -12,8 +12,41 @@ require (
 	github.com/muesli/reflow v0.3.0
 	github.com/muesli/termenv v0.11.0
 	github.com/shurcooL/githubv4 v0.0.0-20211117020012-5800b9de5b8b
-	github.com/shurcooL/graphql v0.0.0-20200928012149-18c5c3165e3a // indirect
 	github.com/skratchdot/open-golang v0.0.0-20200116055534-eef842397966
 	github.com/xanzy/go-gitlab v0.54.3
 	golang.org/x/oauth2 v0.0.0-20211104180415-d3ed0bb246c8
+)
+
+require (
+	github.com/Microsoft/go-winio v0.5.0 // indirect
+	github.com/ProtonMail/go-crypto v0.0.0-20210428141323-04723f9f07d7 // indirect
+	github.com/acomagu/bufpipe v1.0.3 // indirect
+	github.com/emirpasic/gods v1.12.0 // indirect
+	github.com/go-git/gcfg v1.5.0 // indirect
+	github.com/go-git/go-billy/v5 v5.3.1 // indirect
+	github.com/golang/protobuf v1.4.2 // indirect
+	github.com/google/go-querystring v1.1.0 // indirect
+	github.com/hashicorp/go-cleanhttp v0.5.1 // indirect
+	github.com/hashicorp/go-retryablehttp v0.6.8 // indirect
+	github.com/hashicorp/go-version v1.2.1 // indirect
+	github.com/imdario/mergo v0.3.12 // indirect
+	github.com/jbenet/go-context v0.0.0-20150711004518-d14ea06fba99 // indirect
+	github.com/lucasb-eyer/go-colorful v1.2.0 // indirect
+	github.com/mattn/go-isatty v0.0.14 // indirect
+	github.com/mattn/go-runewidth v0.0.13 // indirect
+	github.com/mitchellh/go-homedir v1.1.0 // indirect
+	github.com/muesli/clusters v0.0.0-20200529215643-2700303c1762 // indirect
+	github.com/muesli/kmeans v0.3.0 // indirect
+	github.com/rivo/uniseg v0.2.0 // indirect
+	github.com/sergi/go-diff v1.1.0 // indirect
+	github.com/shurcooL/graphql v0.0.0-20200928012149-18c5c3165e3a // indirect
+	github.com/xanzy/ssh-agent v0.3.1 // indirect
+	github.com/xrash/smetrics v0.0.0-20201216005158-039620a65673 // indirect
+	golang.org/x/crypto v0.0.0-20210711020723-a769d52b0f97 // indirect
+	golang.org/x/net v0.0.0-20210326060303-6b1517762897 // indirect
+	golang.org/x/sys v0.6.0 // indirect
+	golang.org/x/time v0.0.0-20191024005414-555d28b269f0 // indirect
+	google.golang.org/appengine v1.6.6 // indirect
+	google.golang.org/protobuf v1.25.0 // indirect
+	gopkg.in/warnings.v0 v0.1.2 // indirect
 )
