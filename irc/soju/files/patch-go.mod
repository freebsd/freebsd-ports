--- go.mod.orig	2023-03-25 01:47:31 UTC
+++ go.mod
@@ -1,23 +1,34 @@
 module git.sr.ht/~emersion/soju
 
-go 1.15
+go 1.17
 
 require (
 	git.sr.ht/~emersion/go-scfg v0.0.0-20211215104734-c2c7a15d6c99
 	git.sr.ht/~sircmpwn/go-bare v0.0.0-20210406120253-ab86bc2846d9
 	github.com/SherClockHolmes/webpush-go v1.2.0
 	github.com/emersion/go-sasl v0.0.0-20211008083017-0b9dcfb154ac
-	github.com/klauspost/compress v1.15.6 // indirect
 	github.com/lib/pq v1.10.6
 	github.com/mattn/go-sqlite3 v1.14.13
 	github.com/pires/go-proxyproto v0.6.2
 	github.com/prometheus/client_golang v1.12.2
-	github.com/prometheus/common v0.34.0 // indirect
 	golang.org/x/crypto v0.0.0-20220525230936-793ad666bf5e
-	golang.org/x/sys v0.0.0-20220610221304-9f5ed59c137d // indirect
-	golang.org/x/term v0.0.0-20220526004731-065cf7ba2467 // indirect
 	golang.org/x/time v0.0.0-20220609170525-579cf78fd858
-	google.golang.org/protobuf v1.28.0 // indirect
 	gopkg.in/irc.v3 v3.1.4
 	nhooyr.io/websocket v1.8.7
+)
+
+require (
+	github.com/beorn7/perks v1.0.1 // indirect
+	github.com/cespare/xxhash/v2 v2.1.2 // indirect
+	github.com/golang-jwt/jwt v3.2.2+incompatible // indirect
+	github.com/golang/protobuf v1.5.2 // indirect
+	github.com/google/shlex v0.0.0-20191202100458-e7afc7fbc510 // indirect
+	github.com/klauspost/compress v1.15.6 // indirect
+	github.com/matttproud/golang_protobuf_extensions v1.0.1 // indirect
+	github.com/prometheus/client_model v0.2.0 // indirect
+	github.com/prometheus/common v0.34.0 // indirect
+	github.com/prometheus/procfs v0.7.3 // indirect
+	golang.org/x/sys v0.6.0 // indirect
+	golang.org/x/term v0.0.0-20220526004731-065cf7ba2467 // indirect
+	google.golang.org/protobuf v1.28.0 // indirect
 )
