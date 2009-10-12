--- setup/__init__.py.orig	2009-10-11 19:11:10.000000000 +0400
+++ setup/__init__.py	2009-10-11 19:12:17.000000000 +0400
@@ -11,7 +11,8 @@
 is64bit = platform.architecture()[0] == '64bit'
 iswindows = re.search('win(32|64)', sys.platform)
 isosx = 'darwin' in sys.platform
-islinux = not isosx and not iswindows
+isfreebsd = 'freebsd' in sys.platform
+islinux = not isosx and not iswindows and not isfreebsd
 SRC = os.path.abspath('src')
 sys.path.insert(0, SRC)
 sys.resources_location = os.path.join(os.path.dirname(SRC), 'resources')
@@ -117,7 +118,7 @@
         self.real_user = os.environ.get('SUDO_USER', None)
 
     def drop_privileges(self):
-        if not islinux or isosx:
+        if not islinux or isosx or isfreebsd:
             return
         if self.real_user is not None:
             self.info('Dropping privileges to those of', self.real_user+':',
@@ -128,7 +129,7 @@
             os.seteuid(int(self.real_uid))
 
     def regain_privileges(self):
-        if not islinux or isosx:
+        if not islinux or isosx or isfreebsd:
             return
         if os.geteuid() != 0 and self.orig_euid == 0:
             self.info('Trying to get root privileges')
