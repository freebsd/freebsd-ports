--- libfind1.c.orig	2014-11-04 10:25:00 UTC
+++ libfind1.c
@@ -38,7 +38,8 @@ char *dirs[]={"/lib/i386-linux-gnu",
               "/usr/lib64/lib",
               "/usr/lib32",
               "/usr/lib64",
-              "/usr/local/lib",
+              "%%LOCALBASE%%lib",
+              "%%LOCALBASE%%lib32",
               "/usr/local/lib64",
               "/usr/local32/lib",
               "/usr/lib",
