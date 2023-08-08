--- go.mod.orig	2023-03-18 16:09:32 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/CrunchyData/pg_tileserv
 
-go 1.15
+go 1.17
 
 require (
 	github.com/Masterminds/sprig/v3 v3.1.0
@@ -16,4 +16,48 @@ require (
 	github.com/spf13/viper v1.7.1
 	github.com/stretchr/testify v1.6.1
 	github.com/theckman/httpforwarded v0.4.0
+)
+
+require (
+	github.com/Masterminds/goutils v1.1.0 // indirect
+	github.com/Masterminds/semver/v3 v3.1.0 // indirect
+	github.com/beorn7/perks v1.0.1 // indirect
+	github.com/cespare/xxhash/v2 v2.1.1 // indirect
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/felixge/httpsnoop v1.0.1 // indirect
+	github.com/fsnotify/fsnotify v1.4.7 // indirect
+	github.com/golang/protobuf v1.4.3 // indirect
+	github.com/google/uuid v1.1.1 // indirect
+	github.com/hashicorp/hcl v1.0.0 // indirect
+	github.com/huandu/xstrings v1.3.1 // indirect
+	github.com/imdario/mergo v0.3.8 // indirect
+	github.com/jackc/chunkreader/v2 v2.0.1 // indirect
+	github.com/jackc/pgio v1.0.0 // indirect
+	github.com/jackc/pgpassfile v1.0.0 // indirect
+	github.com/jackc/pgproto3/v2 v2.0.6 // indirect
+	github.com/jackc/pgservicefile v0.0.0-20200714003250-2b9c44734f2b // indirect
+	github.com/jackc/puddle v1.1.2 // indirect
+	github.com/magiconair/properties v1.8.1 // indirect
+	github.com/matttproud/golang_protobuf_extensions v1.0.1 // indirect
+	github.com/mitchellh/copystructure v1.0.0 // indirect
+	github.com/mitchellh/mapstructure v1.1.2 // indirect
+	github.com/mitchellh/reflectwalk v1.0.0 // indirect
+	github.com/pelletier/go-toml v1.2.0 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/prometheus/client_model v0.2.0 // indirect
+	github.com/prometheus/common v0.18.0 // indirect
+	github.com/prometheus/procfs v0.6.0 // indirect
+	github.com/spf13/afero v1.1.2 // indirect
+	github.com/spf13/cast v1.3.1 // indirect
+	github.com/spf13/jwalterweatherman v1.0.0 // indirect
+	github.com/spf13/pflag v1.0.3 // indirect
+	github.com/subosito/gotenv v1.2.0 // indirect
+	golang.org/x/crypto v0.0.0-20200622213623-75b288015ac9 // indirect
+	golang.org/x/sys v0.6.0 // indirect
+	golang.org/x/text v0.3.3 // indirect
+	golang.org/x/xerrors v0.0.0-20191204190536-9bdfabe68543 // indirect
+	google.golang.org/protobuf v1.23.0 // indirect
+	gopkg.in/ini.v1 v1.51.0 // indirect
+	gopkg.in/yaml.v2 v2.3.0 // indirect
+	gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c // indirect
 )
