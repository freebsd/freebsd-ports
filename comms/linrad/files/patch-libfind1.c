--- libfind1.c.orig	2014-03-20 18:05:17.000000000 -0700
+++ libfind1.c	2014-06-27 21:45:49.000000000 -0700
@@ -38,7 +38,9 @@
               "/usr/lib64/lib",
               "/usr/lib32",
               "/usr/lib64",
-              "/usr/local/lib",
+              "%%LOCALBASE%%lib",
+              "%%LOCALBASE%%lib/portaudio2",
+              "%%LOCALBASE%%lib32",
               "/usr/local/lib64",
               "/usr/local32/lib",
               "/usr/lib",
