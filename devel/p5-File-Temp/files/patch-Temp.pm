--- Temp.pm.orig	Fri Feb 23 02:00:56 2001
+++ Temp.pm	Mon Mar 25 16:09:59 2002
@@ -116,6 +116,9 @@
 
 =cut
 
+use Config;
+use lib $Config{'installsitelib'};
+
 # 5.6.0 gives us S_IWOTH, S_IWGRP, our and auto-vivifying filehandls
 # People would like a version on 5.005 so give them what they want :-)
 use 5.005;
