--- as_setup.py.orig	Wed Jun 28 18:04:25 2006
+++ as_setup.py	Sun Sep 24 12:23:18 2006
@@ -1170,7 +1170,10 @@
       from socket import gethostname, gethostbyaddr
       if host==None:
          host = gethostname()
-      fqn, alias, ip = gethostbyaddr(host)
+      try:
+         fqn, alias, ip = gethostbyaddr(host)
+      except:
+         fqn='put-your-host-name.here'
       if fqn.find('localhost')>-1:
          alias=[a for a in alias if a.find('localhost')<0]
          if len(alias)>0:
