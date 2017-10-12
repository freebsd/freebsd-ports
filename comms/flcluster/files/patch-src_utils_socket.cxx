--- src/utils/socket.cxx.orig	2017-08-29 18:53:34 UTC
+++ src/utils/socket.cxx
@@ -619,11 +619,7 @@ void Socket::open(const Address& addr)
 	address = addr;
 	size_t n = address.size();
 
-#ifdef __FreeBSD__
-	for (anum = n-1; anum >= 1; anum--) {
-#else
 	for (anum = n-1; anum >= 0; anum--) {
-#endif
 		ainfo = address.get(anum);
 		LOG_INFO("Trying %s", address.get_str(ainfo).c_str());
 		if ((sockfd = socket(ainfo->ai_family, ainfo->ai_socktype, ainfo->ai_protocol)) != -1)
