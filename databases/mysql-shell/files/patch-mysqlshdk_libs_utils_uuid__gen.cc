--- mysqlshdk/libs/utils/uuid_gen.cc.orig	2026-01-26 17:13:17 UTC
+++ mysqlshdk/libs/utils/uuid_gen.cc
@@ -168,7 +168,7 @@ my_bool my_gethwaddr(unsigned char *to) {
   char zero_array[ETHER_ADDR_LEN] = {0};
 
   if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) goto err;
-  if (!(buf = alloca(len))) goto err;
+  if (!(buf = (char *)alloca(len))) goto err;
   if (sysctl(mib, 6, buf, &len, NULL, 0) < 0) goto err;
 
   end = buf + len;
