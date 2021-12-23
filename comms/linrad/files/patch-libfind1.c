--- libfind1.c.orig	2014-11-04 10:25:00 UTC
+++ libfind1.c
@@ -30,7 +30,8 @@
 char *dirs[]={"/lib/i386-linux-gnu",
               "/lib/x86_64-linux-gnu",
               "/lib",
-              "/lib32",
+              "%%PREFIX%%/lib",
+	      "/lib32",
               "/lib64",
               "/usr/lib/i386-linux-gnu",
               "/usr/lib/x86_64-linux-gnu",
