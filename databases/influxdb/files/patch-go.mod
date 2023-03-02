--- go.mod.orig	2023-03-02 21:16:04 UTC
+++ go.mod
@@ -1,9 +1,8 @@
 module github.com/influxdata/influxdb
 
-go 1.13
+go 1.17
 
 require (
-	cloud.google.com/go/bigtable v1.2.0 // indirect
 	collectd.org v0.3.0
 	github.com/BurntSushi/toml v0.3.1
 	github.com/apache/arrow/go/arrow v0.0.0-20191024131854-af6fa24be0db
@@ -13,8 +12,6 @@ require (
 	github.com/davecgh/go-spew v1.1.1
 	github.com/dgrijalva/jwt-go/v4 v4.0.0-preview1
 	github.com/dgryski/go-bitstream v0.0.0-20180413035011-3522498ce2c8
-	github.com/glycerine/go-unsnap-stream v0.0.0-20180323001048-9f0cb55181dd // indirect
-	github.com/glycerine/goconvey v0.0.0-20190410193231-58a59202ab31 // indirect
 	github.com/gogo/protobuf v1.3.2
 	github.com/golang/snappy v0.0.0-20180518054509-2e65f85255db
 	github.com/google/go-cmp v0.4.0
@@ -25,33 +22,89 @@ require (
 	github.com/influxdata/usage-client v0.0.0-20160829180054-6d3895376368
 	github.com/jsternberg/zap-logfmt v1.0.0
 	github.com/jwilder/encoding v0.0.0-20170811194829-b4e1701a28ef
-	github.com/klauspost/compress v1.4.0 // indirect
-	github.com/klauspost/cpuid v0.0.0-20170728055534-ae7887de9fa5 // indirect
-	github.com/klauspost/crc32 v0.0.0-20161016154125-cb6bfca970f6 // indirect
 	github.com/klauspost/pgzip v1.0.2-0.20170402124221-0bf5dcad4ada
 	github.com/mattn/go-isatty v0.0.4
-	github.com/mschoch/smat v0.0.0-20160514031455-90eadee771ae // indirect
 	github.com/opentracing/opentracing-go v1.0.3-0.20180606204148-bd9c31933947
 	github.com/paulbellamy/ratecounter v0.2.0
 	github.com/peterh/liner v1.0.1-0.20180619022028-8c1271fcf47f
-	github.com/philhofer/fwd v1.0.0 // indirect
 	github.com/pkg/errors v0.9.1
 	github.com/prometheus/client_golang v1.0.0
 	github.com/retailnext/hllpp v1.0.1-0.20180308014038-101a6d2f8b52
-	github.com/segmentio/kafka-go v0.2.0 // indirect
-	github.com/smartystreets/goconvey v1.6.4 // indirect
 	github.com/spf13/cast v1.3.0
 	github.com/stretchr/testify v1.7.0
 	github.com/tinylib/msgp v1.0.2
-	github.com/willf/bitset v1.1.3 // indirect
 	github.com/xlab/treeprint v0.0.0-20180616005107-d6fb6747feb6
 	go.uber.org/zap v1.9.1
 	golang.org/x/crypto v0.0.0-20210322153248-0c34fe9e7dc2
 	golang.org/x/sync v0.0.0-20201020160332-67f06af15bc9
-	golang.org/x/sys v0.0.0-20201119102817-f84b799fce68
+	golang.org/x/sys v0.5.0
 	golang.org/x/text v0.3.3
 	golang.org/x/time v0.0.0-20190308202827-9d24e82272b4
 	golang.org/x/tools v0.0.0-20210106214847-113979e3529a
-	gonum.org/v1/gonum v0.6.0 // indirect
 	google.golang.org/grpc v1.26.0
+)
+
+require (
+	cloud.google.com/go v0.51.0 // indirect
+	cloud.google.com/go/bigtable v1.2.0 // indirect
+	github.com/Masterminds/goutils v1.1.1 // indirect
+	github.com/Masterminds/semver v1.5.0 // indirect
+	github.com/Masterminds/sprig v2.22.0+incompatible // indirect
+	github.com/beorn7/perks v1.0.0 // indirect
+	github.com/c-bata/go-prompt v0.2.2 // indirect
+	github.com/dustin/go-humanize v1.0.0 // indirect
+	github.com/eclipse/paho.mqtt.golang v1.2.0 // indirect
+	github.com/glycerine/go-unsnap-stream v0.0.0-20180323001048-9f0cb55181dd // indirect
+	github.com/glycerine/goconvey v0.0.0-20190410193231-58a59202ab31 // indirect
+	github.com/go-sql-driver/mysql v1.4.1 // indirect
+	github.com/gofrs/uuid v3.3.0+incompatible // indirect
+	github.com/golang/geo v0.0.0-20190916061304-5b978397cfec // indirect
+	github.com/golang/groupcache v0.0.0-20191227052852-215e87163ea7 // indirect
+	github.com/golang/protobuf v1.3.2 // indirect
+	github.com/google/flatbuffers v1.11.0 // indirect
+	github.com/google/uuid v1.2.0 // indirect
+	github.com/googleapis/gax-go/v2 v2.0.5 // indirect
+	github.com/huandu/xstrings v1.3.2 // indirect
+	github.com/imdario/mergo v0.3.12 // indirect
+	github.com/influxdata/line-protocol v0.0.0-20180522152040-32c6aa80de5e // indirect
+	github.com/influxdata/tdigest v0.0.0-20181121200506-bf2b5ad3c0a9 // indirect
+	github.com/jstemmer/go-junit-report v0.9.1 // indirect
+	github.com/klauspost/compress v1.4.0 // indirect
+	github.com/klauspost/cpuid v0.0.0-20170728055534-ae7887de9fa5 // indirect
+	github.com/klauspost/crc32 v0.0.0-20161016154125-cb6bfca970f6 // indirect
+	github.com/lib/pq v1.0.0 // indirect
+	github.com/mattn/go-colorable v0.0.9 // indirect
+	github.com/mattn/go-runewidth v0.0.3 // indirect
+	github.com/mattn/go-tty v0.0.0-20180907095812-13ff1204f104 // indirect
+	github.com/matttproud/golang_protobuf_extensions v1.0.1 // indirect
+	github.com/mitchellh/copystructure v1.1.1 // indirect
+	github.com/mitchellh/reflectwalk v1.0.1 // indirect
+	github.com/mschoch/smat v0.0.0-20160514031455-90eadee771ae // indirect
+	github.com/philhofer/fwd v1.0.0 // indirect
+	github.com/pkg/term v0.0.0-20180730021639-bffc007b7fd5 // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/prometheus/client_model v0.0.0-20190812154241-14fe0d1b01d4 // indirect
+	github.com/prometheus/common v0.6.0 // indirect
+	github.com/prometheus/procfs v0.0.2 // indirect
+	github.com/segmentio/kafka-go v0.2.0 // indirect
+	github.com/smartystreets/goconvey v1.6.4 // indirect
+	github.com/spf13/pflag v1.0.3 // indirect
+	github.com/willf/bitset v1.1.3 // indirect
+	go.opencensus.io v0.22.2 // indirect
+	go.uber.org/atomic v1.5.1 // indirect
+	go.uber.org/multierr v1.4.0 // indirect
+	go.uber.org/tools v0.0.0-20190618225709-2cfd321de3ee // indirect
+	golang.org/x/exp v0.0.0-20191227195350-da58074b4299 // indirect
+	golang.org/x/lint v0.0.0-20191125180803-fdd1cda4f05f // indirect
+	golang.org/x/mod v0.3.0 // indirect
+	golang.org/x/net v0.0.0-20210226172049-e18ecbb05110 // indirect
+	golang.org/x/oauth2 v0.0.0-20200107190931-bf48bf16ab8d // indirect
+	golang.org/x/term v0.0.0-20201126162022-7de9c90e9dd1 // indirect
+	golang.org/x/xerrors v0.0.0-20200804184101-5ec99f83aff1 // indirect
+	gonum.org/v1/gonum v0.6.0 // indirect
+	google.golang.org/api v0.15.0 // indirect
+	google.golang.org/appengine v1.6.5 // indirect
+	google.golang.org/genproto v0.0.0-20200108215221-bd8f9a0ef82f // indirect
+	gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c // indirect
+	honnef.co/go/tools v0.0.1-2019.2.3 // indirect
 )
