--- src/kazuhiki/kazuhiki.cc.orig	2010-01-18 06:06:16.000000000 +0900
+++ src/kazuhiki/kazuhiki.cc	2010-01-19 11:56:44.907400335 +0900
@@ -330,12 +330,16 @@
 		memset(&hints, 0, sizeof(hints));
 		hints.ai_family = UseIPv6 ? AF_UNSPEC : AF_INET;
 		hints.ai_socktype = SOCK_STREAM;  // FIXME
+#ifdef __FreeBSD__
+		hints.ai_flags = AI_ADDRCONFIG;
+#else
 		hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
+#endif
 
 		addrinfo *res = NULL;
 		int err;
 		if( (err=getaddrinfo(host, NULL, &hints, &res)) != 0 ) {
-			parser::raise("can't resolve host name: %s", host);
+			parser::raise("can't resolve host name (%s): %s", gai_strerror(err), host);
 		}
 
 		for(addrinfo* rp=res; rp; rp = rp->ai_next) {
@@ -349,7 +353,7 @@
 			}
 		}
 
-		parser::raise("can't resolve host name: %s", host);
+		parser::raise("can't resolve host name (no suitable family): %s", host);
 	}
 
 	void addr_any(unsigned short port, bool dummy)
