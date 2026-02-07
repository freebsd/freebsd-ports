--- tools/deps.nim.orig	2025-05-07 14:22:20 UTC
+++ tools/deps.nim
@@ -22,30 +22,31 @@ proc cloneDependency*(destDirBase: string, url: string
 
 proc cloneDependency*(destDirBase: string, url: string, commit = commitHead,
                       appendRepoName = true, allowBundled = false) =
-  let destDirBase = destDirBase.absolutePath
-  let p = url.parseUri.path
-  let name = p.splitFile.name
-  var destDir = destDirBase
-  if appendRepoName: destDir = destDir / name
-  let quotedDestDir = destDir.quoteShell
-  if not dirExists(destDir):
+  #let destDirBase = destDirBase.absolutePath
+  #let p = url.parseUri.path
+  #let name = p.splitFile.name
+  #var destDir = destDirBase
+  #if appendRepoName: destDir = destDir / name
+  #let quotedDestDir = destDir.quoteShell
+  #if not dirExists(destDir):
     # note: old code used `destDir / .git` but that wouldn't prevent git clone
     # from failing
-    execRetry fmt"git clone -q {url} {quotedDestDir}"
-  if isGitRepo(destDir):
-    let oldDir = getCurrentDir()
-    setCurrentDir(destDir)
-    try:
-      let checkoutCmd = fmt"git checkout -q {commit}"
-      if tryexec(checkoutCmd) != 0:
-        execRetry "git fetch -q"
-        exec checkoutCmd
-    finally:
-      setCurrentDir(oldDir)
-  elif allowBundled:
-    discard "this dependency was bundled with Nim, don't do anything"
-  else:
-    quit "FAILURE: " & destdir & " already exists but is not a git repo"
+  #  execRetry fmt"git clone -q {url} {quotedDestDir}"
+  #if isGitRepo(destDir):
+  #  let oldDir = getCurrentDir()
+  #  setCurrentDir(destDir)
+  #  try:
+  #    let checkoutCmd = fmt"git checkout -q {commit}"
+  #    if tryexec(checkoutCmd) != 0:
+  #      execRetry "git fetch -q"
+  #      exec checkoutCmd
+  #  finally:
+  #    setCurrentDir(oldDir)
+  #elif allowBundled:
+  #  discard "this dependency was bundled with Nim, don't do anything"
+  #else:
+  #  quit "FAILURE: " & destdir & " already exists but is not a git repo"
+  quit "FAILURE: git operations not allowed in ports!: " & destDirBase
 
 proc updateSubmodules*(dir: string, allowBundled = false) =
   if isGitRepo(dir):
