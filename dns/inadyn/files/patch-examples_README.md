--- examples/README.md.orig	2019-10-21 13:57:28 UTC
+++ examples/README.md
@@ -1,4 +1,4 @@
-Example /etc/inadyn.conf files
+Example %%PREFIX%%/etc/inadyn.conf files
 ==============================
 
 This directory holds a few example configuration files for common
@@ -11,16 +11,16 @@ https://gitub.com/troglobit/inadyn
 Usage
 -----
 
-Simply copy the desired example to /etc/inadyn.conf, edit it with
+Simply copy the desired example to %%PREFIX%%/etc/inadyn.conf, edit it with
 your hostname, username, and password and then start Inadyn.
 
 
 Example
 -------
 
-    user@example:~$ sudo cp freedns.conf /etc/inadyn.conf
-    user@example:~$ sudo chmod 600 /etc/inadyn.conf
-    user@example:~$ sudo vim /etc/inadyn.conf
+    user@example:~$ sudo cp freedns.conf %%PREFIX%%/etc/inadyn.conf
+    user@example:~$ sudo chmod 600 %%PREFIX%%/etc/inadyn.conf
+    user@example:~$ sudo vim %%PREFIX%%/etc/inadyn.conf
     [Change username, password and hostname]
     user@example:~$ sudo inadyn
     user@example:~$
