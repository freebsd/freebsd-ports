--- setup.py.orig	2023-03-26 20:08:04 UTC
+++ setup.py
@@ -227,40 +227,7 @@ class fetch(Command):
         if self.sqlite:
             write("  Getting the SQLite amalgamation")
 
-            AURL = "https://sqlite.org/sqlite-autoconf-%s.tar.gz" % (self.webversion, )
-
-            AURL = fixup_download_url(AURL)
-
-            data = self.download(AURL, checksum=True)
-
-            # we need to run configure to get various -DHAVE_foo flags on non-windows platforms
-            # delete existing sqlite3 directory if it exists, but save sqlite3config.h if it exists
-            sqlite3config_h = None
-            if os.path.exists("sqlite3/sqlite3config.h"):
-                sqlite3config_h = read_whole_file("sqlite3/sqlite3config.h", "rt")
-            if os.path.exists('sqlite3'):
-                for dirpath, dirnames, filenames in os.walk('sqlite3', topdown=False):
-                    for file in filenames:
-                        os.remove(os.path.join(dirpath, file))
-                    for dir in dirnames:
-                        os.rmdir(os.path.join(dirpath, dir))
-                os.rmdir('sqlite3')
-            # if you get an exception here it is likely that you don't have the python zlib module
-            import zlib
-            tar = tarfile.open("nonexistentname to keep old python happy", 'r', data)
-            configmember = None
-            for member in tar.getmembers():
-                tar.extract(member)
-                # find first file named configure
-                if not configmember and member.name.endswith("/configure"):
-                    configmember = member
-            tar.close()
-            # the directory name has changed a bit with each release so try to work out what it is
-            if not configmember:
-                write("Unable to determine directory it extracted to.", dest=sys.stderr)
-                sys.exit(19)
-            dirname = configmember.name.split('/')[0]
-            os.rename(dirname, 'sqlite3')
+            dirname = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'sqlite3')
             if sys.platform != "win32":
                 os.chdir('sqlite3')
                 write("    Running configure to work out SQLite compilation flags")
