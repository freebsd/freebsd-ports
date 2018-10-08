PR: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225372
Upstream: http://bugs.hylafax.org/show_bug.cgi?id=971
Obtained from: https://sourceforge.net/p/hylafax/HylaFAX+/2417/
See Also: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=853448

--- libhylafax/FaxRecvInfo.c++.orig	2018-10-07 07:40:23 UTC
+++ libhylafax/FaxRecvInfo.c++
@@ -112,7 +112,7 @@ FaxRecvInfo::decode(const char* cp)
     if (cp == NULL || cp[1] != ',' || cp[2] != '"')
 	return (false);
     u_int i = 0;
-    while (cp+2 != '\0') {
+    while (*(cp+2) != '\0') {
 	callid[i] = cp+3;		// +1 for "/+1 for ,/+1 for "
 	if (*cp == '\"') break;
 	callid[i].resize(callid[i].next(0,'"'));
