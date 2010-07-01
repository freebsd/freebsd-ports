--- ng/onetcl.cpp.orig	2010-06-08 09:26:24.000000000 +0700
+++ ng/onetcl.cpp	2010-06-08 09:26:48.000000000 +0700
@@ -16,7 +16,7 @@
 "    set ngdir $env(NETGENDIR) \n",\
 "}\n",\
 "if { [string length $ngdir] == 0 } {\n",\
-"    set ngdir \".\" \n",\
+"    set ngdir \"/usr/local/bin\" \n",\
 "}\n",\
 "\n",\
 "\n",\
