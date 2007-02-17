--- lib/as_system.py.orig	Tue Dec 19 16:55:44 2006
+++ lib/as_system.py	Sat Feb 17 23:15:15 2007
@@ -672,7 +672,12 @@
       from socket import gethostname, gethostbyaddr
       if host == None:
          host = gethostname()
-      fqn, alias, ip = gethostbyaddr(host)
+      """ Fix for package building on the FreeBSD cluster which has no hostname
+      """
+      try:
+         fqn, alias, ip = gethostbyaddr(host)
+      except:
+         fqn='put-your-host-name.here'
       if fqn.find('localhost')>-1:
          alias = [a for a in alias if a.find('localhost')<0]
          if len(alias)>0:
