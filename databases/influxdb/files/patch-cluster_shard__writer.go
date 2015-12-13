--- cluster/shard_writer.go.orig	2015-12-08 15:03:30 UTC
+++ cluster/shard_writer.go
@@ -7,7 +7,7 @@ import (
 
 	"github.com/influxdb/influxdb/meta"
 	"github.com/influxdb/influxdb/models"
-	"gopkg.in/fatih/pool.v2"
+	"github.com/fatih/pool"
 )
 
 const (
