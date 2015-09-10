--- cluster/client_pool.go.orig	2015-06-23 14:38:16 UTC
+++ cluster/client_pool.go
@@ -4,7 +4,7 @@ import (
 	"net"
 	"sync"
 
-	"gopkg.in/fatih/pool.v2"
+	"github.com/fatih/pool"
 )
 
 type clientPool struct {
