--- go.mod.orig	2024-11-06 12:16:45 UTC
+++ go.mod
@@ -1,17 +1,20 @@ module github.com/omniscale/imposm3
 module github.com/omniscale/imposm3
 
-go 1.12
+go 1.17
 
 require (
-	github.com/fsnotify/fsnotify v1.4.7 // indirect
 	github.com/gogo/protobuf v0.0.0-20171007142547-342cbe0a0415
 	github.com/jmhodges/levigo v0.0.0-20161115193449-c42d9e0ca023
-	github.com/kr/pretty v0.1.0 // indirect
 	github.com/lib/pq v1.8.0
 	github.com/omniscale/go-osm v0.2.1
 	github.com/pkg/errors v0.8.0
-	golang.org/x/sys v0.0.0-20171114162044-bf42f188b9bc // indirect
+	gopkg.in/yaml.v2 v2.0.0-20170812160011-eb3733d160e7
+)
+
+require (
+	github.com/fsnotify/fsnotify v1.4.7 // indirect
+	github.com/kr/pretty v0.1.0 // indirect
+	golang.org/x/sys v0.26.0 // indirect
 	gopkg.in/check.v1 v1.0.0-20190902080502-41f04d3bba15 // indirect
 	gopkg.in/fsnotify.v1 v1.4.2 // indirect
-	gopkg.in/yaml.v2 v2.0.0-20170812160011-eb3733d160e7
 )
