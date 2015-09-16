--- cluster/shard_writer.go.orig	2015-06-23 14:38:36 UTC
+++ cluster/shard_writer.go
@@ -7,7 +7,7 @@ import (
 
 	"github.com/influxdb/influxdb/meta"
 	"github.com/influxdb/influxdb/tsdb"
-	"gopkg.in/fatih/pool.v2"
+	"github.com/fatih/pool"
 )
 
 const (
