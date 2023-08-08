--- go.mod.orig	2023-03-08 18:42:34 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/ultralist/ultralist
 
-go 1.14
+go 1.17
 
 require (
 	github.com/cheynewallace/tabby v1.1.0
@@ -8,11 +8,37 @@ require (
 	github.com/jinzhu/copier v0.0.0-20190924061706-b57f9002281a
 	github.com/julienschmidt/httprouter v1.3.0
 	github.com/manifoldco/promptui v0.7.0
-	github.com/myesui/uuid v1.0.0 // indirect
 	github.com/skratchdot/open-golang v0.0.0-20200116055534-eef842397966
 	github.com/spf13/cobra v1.0.0
 	github.com/spf13/viper v1.7.0
 	github.com/stretchr/testify v1.6.1
 	github.com/twinj/uuid v1.0.0
+)
+
+require (
+	github.com/chzyer/readline v0.0.0-20180603132655-2972be24d48e // indirect
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/fsnotify/fsnotify v1.4.7 // indirect
+	github.com/hashicorp/hcl v1.0.0 // indirect
+	github.com/inconshreveable/mousetrap v1.0.0 // indirect
+	github.com/juju/ansiterm v0.0.0-20180109212912-720a0952cc2a // indirect
+	github.com/lunixbochs/vtclean v0.0.0-20180621232353-2d01aacdc34a // indirect
+	github.com/magiconair/properties v1.8.1 // indirect
+	github.com/mattn/go-colorable v0.1.4 // indirect
+	github.com/mattn/go-isatty v0.0.11 // indirect
+	github.com/mitchellh/mapstructure v1.1.2 // indirect
+	github.com/myesui/uuid v1.0.0 // indirect
+	github.com/pelletier/go-toml v1.2.0 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/spf13/afero v1.1.2 // indirect
+	github.com/spf13/cast v1.3.0 // indirect
+	github.com/spf13/jwalterweatherman v1.0.0 // indirect
+	github.com/spf13/pflag v1.0.3 // indirect
+	github.com/subosito/gotenv v1.2.0 // indirect
+	golang.org/x/sys v0.5.0 // indirect
+	golang.org/x/text v0.3.2 // indirect
+	gopkg.in/ini.v1 v1.51.0 // indirect
 	gopkg.in/stretchr/testify.v1 v1.2.2 // indirect
+	gopkg.in/yaml.v2 v2.2.4 // indirect
+	gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c // indirect
 )
