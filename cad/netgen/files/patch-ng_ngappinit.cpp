--- ng/ngappinit.cpp.orig	2010-06-08 09:13:06.000000000 +0700
+++ ng/ngappinit.cpp	2010-06-08 09:13:20.000000000 +0700
@@ -151,7 +151,7 @@
   if (getenv ("NETGENDIR") && strlen (getenv ("NETGENDIR")))
     ngdir = getenv ("NETGENDIR");
   else
-    ngdir = ".";
+    ngdir = "/usr/local/bin";
   
   verbose = parameters.GetDefineFlag ("V");
 
