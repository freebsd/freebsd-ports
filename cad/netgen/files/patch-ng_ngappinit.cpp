--- ng/ngappinit.cpp.orig	2014-08-29 09:54:01 UTC
+++ ng/ngappinit.cpp
@@ -149,7 +149,7 @@ int main(int argc, char ** argv)
   if (getenv ("NETGENDIR") && strlen (getenv ("NETGENDIR")))
     ngdir = getenv ("NETGENDIR");
   else
-    ngdir = ".";
+    ngdir = "/usr/local/bin";
   
   verbose = parameters.GetDefineFlag ("V");
 
