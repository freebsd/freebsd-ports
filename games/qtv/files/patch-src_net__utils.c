--- src/net_utils.c.orig	2025-02-16 14:10:58 UTC
+++ src/net_utils.c
@@ -60,11 +60,13 @@ char *Net_BaseAdrToString (struct sockaddr_in *a, char
 	// Windows have inet_ntop only starting from Vista. Sigh.
 #ifdef _WIN32
 	const char *result = inet_ntoa(a->sin_addr);
+	strlcpy(buf, result ? result : "", bufsize);
 #else
 	const char *result = inet_ntop(a->sin_family, &a->sin_addr, buf, bufsize);
+	if (!result) {
+		strlcpy(buf, "", bufsize);
+	}
 #endif
-
-	strlcpy(buf, result ? result : "", bufsize);
 
 	return buf;
 }
