--- as_setup.py.orig	2007-12-21 17:08:17.000000000 +0100
+++ as_setup.py	2008-01-08 22:32:14.000000000 +0100
@@ -397,6 +397,10 @@
                traceback.print_exc()
                self.exit_code=iret
                raise SetupExtractError, _('error during extracting archive %s') % archive
+            # Insert FreeBSD patches here
+            self._print('Handle gfortran C-like pre-processor directives')
+            os.rename(os.path.join(self.content, 'bibf90/utilitai/traceb.f'), os.path.join(self.content, 'bibf90/utilitai/traceb.F'))
+            # End of FreeBSD patches
 
       if iextr_as:
          iret=0
@@ -1216,7 +1220,10 @@
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
