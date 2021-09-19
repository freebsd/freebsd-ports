--- cmd/soju/main.go.orig	2021-09-13 12:23:33 UTC
+++ cmd/soju/main.go
@@ -253,5 +253,6 @@ func proxyProtoListener(ln net.Listener, srv *soju.Ser
 			}
 			return proxyproto.IGNORE, nil
 		},
+		ReadHeaderTimeout: 5 * time.Second,
 	}
 }
