--- qctlib/vcs/svn.py.orig	2009-02-15 22:49:32 UTC
+++ qctlib/vcs/svn.py
@@ -84,6 +84,8 @@ class qctVcsSvn:
 
         if showIgnored:  extra = ['--no-ignore']
         else:            extra = []
+        versionOutput = runProgram([self.svn_exe, '--version', '--quiet'])
+        version = [int(s) for s in versionOutput.split(os.linesep)[0].split('.')]
         statusOutput = runProgram([self.svn_exe, '--ignore-externals'] + extra + ['status'])
         recs = statusOutput.split(os.linesep)
         recs.pop() # remove last entry (which is '')
@@ -91,11 +93,19 @@ class qctVcsSvn:
         if pb: pb.setValue(2)
 
         for line in recs:
-            if len(line) < 7:
-                continue
-            status = line[0]
-            fname = line[7:]
-            self.fileStatus[ fname ] = line[0:6]
+            # a 7th column was added in svn 1.6, see http://subversion.tigris.org/svn_1.6_releasenotes.html#svn-status
+            if version[0]>1 or version[0]==1 and version[1]>=6:
+                if len(line) < 8:
+                    continue
+                status = line[0]
+                fname = line[8:]
+                self.fileStatus[ fname ] = line[0:7]
+            else:
+                if len(line) < 7:
+                    continue
+                status = line[0]
+                fname = line[7:]
+                self.fileStatus[ fname ] = line[0:6]
             if status == 'M':  # modified
                 itemList.append('M ' + fname)
             elif status == 'A':  # added
