--- tools/deps.nim.orig	2025-02-06 01:49:40 UTC
+++ tools/deps.nim
@@ -20,28 +20,29 @@ proc cloneDependency*(destDirBase: string, url: string
 
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
-      execRetry "git fetch -q"
-      exec fmt"git checkout -q {commit}"
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
+  #    execRetry "git fetch -q"
+  #    exec fmt"git checkout -q {commit}"
+  #  finally:
+  #    setCurrentDir(oldDir)
+  #elif allowBundled:
+  #  discard "this dependency was bundled with Nim, don't do anything"
+  #else:
+  #  quit "FAILURE: " & destdir & " already exists but is not a git repo"
+  quit "FAILURE: git operations now allowed!: " & destDirBase
 
 proc updateSubmodules*(dir: string, allowBundled = false) =
   if isGitRepo(dir):
