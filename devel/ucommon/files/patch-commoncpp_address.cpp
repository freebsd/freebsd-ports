--- commoncpp/address.cpp.orig	2013-09-16 17:58:54.000000000 +0200
+++ commoncpp/address.cpp	2013-09-16 17:59:55.000000000 +0200
@@ -1062,7 +1062,7 @@
 #endif
 
     memset(&netmask, 0, sizeof(netmask));
-    bitset((bit_t *)&netmask, getMask(cp));
+    ::bitset((bit_t *)&netmask, getMask(cp));
     setString(cbuf, sizeof(cbuf), cp);
 
     ep = (char *)strchr(cp, '/');
@@ -1192,7 +1192,7 @@
     char *ep;
 
     memset(&netmask, 0, sizeof(netmask));
-    bitset((bit_t *)&netmask, getMask(cp));
+    ::bitset((bit_t *)&netmask, getMask(cp));
     setString(cbuf, sizeof(cbuf), cp);
     ep = (char *)strchr(cp, '/');
     if(ep)
