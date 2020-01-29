--- src/hmmc2.c.orig	2019-11-18 13:23:12 UTC
+++ src/hmmc2.c
@@ -334,7 +334,7 @@ int main(int argc, char *argv[])
       n = sizeof(sstatus);
       total += n;
       if ((size = readn(sock, &sstatus, n)) == -1) {
-        if(errno == 104 || errno == 0){
+        if(errno == ECONNRESET || errno == 0){
           // connection was reset, usually because server exited
           fprintf(stderr, "Daemon exited, shutting down\n");
           exit(0);
