--- checksetup.pl~	Mon Dec 23 14:54:23 2002
+++ checksetup.pl	Mon Feb  3 20:34:14 2003
@@ -395,7 +395,7 @@
 # and you cannot set this up any other way. YOU HAVE BEEN WARNED.
 # If you set this to anything besides "", you will need to run checksetup.pl
 # as root, or as a user who is a member of the specified group.
-$webservergroup = "nobody";
+$webservergroup = "nogroup";
 ');
 
 
