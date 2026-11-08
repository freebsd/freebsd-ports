--- tsa2d32.cpp.orig	2026-10-15 10:19:29 UTC
+++ tsa2d32.cpp
@@ -707,8 +707,7 @@ int main(int argc, char **argv)
     int v;
 
	if (phsz==1) {
-	  v = 0;
-	  memcpy(&v, &sf[idx], phsz);
+	  v = sf[idx];
	} else if (phsz==2) {
       phokey_t kk;
       memcpy(&kk, &sf[idx], phsz);
