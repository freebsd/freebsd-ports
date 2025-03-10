--- beetsplug/ipfs.py.orig	2025-01-13 12:04:44 UTC
+++ beetsplug/ipfs.py
@@ -134,9 +134,9 @@ class IPFSPlugin(BeetsPlugin):
         self._log.info("Adding {0} to ipfs", album_dir)
 
         if self.config["nocopy"]:
-            cmd = "ipfs add --nocopy -q -r".split()
+            cmd = "kubo-go add --nocopy -q -r".split()
         else:
-            cmd = "ipfs add -q -r".split()
+            cmd = "kubo-go add -q -r".split()
         cmd.append(album_dir)
         try:
             output = util.command_output(cmd).stdout.split()
@@ -178,7 +178,7 @@ class IPFSPlugin(BeetsPlugin):
 
     def ipfs_get_from_hash(self, lib, _hash):
         try:
-            cmd = "ipfs get".split()
+            cmd = "kubo-go get".split()
             cmd.append(_hash)
             util.command_output(cmd)
         except (OSError, subprocess.CalledProcessError) as err:
@@ -202,9 +202,9 @@ class IPFSPlugin(BeetsPlugin):
             self.ipfs_added_albums(lib, tmp.name)
             try:
                 if self.config["nocopy"]:
-                    cmd = "ipfs add --nocopy -q ".split()
+                    cmd = "kubo-go add --nocopy -q ".split()
                 else:
-                    cmd = "ipfs add -q ".split()
+                    cmd = "kubo-go add -q ".split()
                 cmd.append(tmp.name)
                 output = util.command_output(cmd).stdout
             except (OSError, subprocess.CalledProcessError) as err:
@@ -230,7 +230,7 @@ class IPFSPlugin(BeetsPlugin):
                 return False
         path = os.path.join(remote_libs, lib_name.encode() + b".db")
         if not os.path.exists(path):
-            cmd = f"ipfs get {_hash} -o".split()
+            cmd = f"kubo-go get {_hash} -o".split()
             cmd.append(path)
             try:
                 util.command_output(cmd)
