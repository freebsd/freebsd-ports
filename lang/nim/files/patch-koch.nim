--- koch.nim.orig	2024-07-05 12:55:45 UTC
+++ koch.nim
@@ -11,9 +11,9 @@ const
 
 const
   # examples of possible values for repos: Head, ea82b54
-  NimbleStableCommit = "be2f1309b35a6189ff5eb34a007793e6d3f94157" # master
-  AtlasStableCommit = "5faec3e9a33afe99a7d22377dd1b45a5391f5504"
-  ChecksumsStableCommit = "025bcca3915a1b9f19878cea12ad68f9884648fc"
+  NimbleStableCommit = "f8bd7b5fa6ea7a583b411b5959b06e6b5eb23667" # master
+  AtlasStableCommit = "7b780811a168f3f32bff4822369dda46a7f87f9a"
+  ChecksumsStableCommit = "b4c73320253f78e3a265aec6d9e8feb83f97c77b"
   SatStableCommit = "faf1617f44d7632ee9601ebc13887644925dcc01"
 
   # examples of possible values for fusion: #head, #ea82b54, 1.2.3
@@ -146,32 +146,32 @@ proc csource(args: string) =
            "--main:compiler/nim.nim compiler/installer.ini $1") %
        [args, VersionAsString, compileNimInst])
 
-proc bundleC2nim(args: string) =
-  cloneDependency(distDir, "https://github.com/nim-lang/c2nim.git")
-  nimCompile("dist/c2nim/c2nim",
-             options = "--noNimblePath --path:. " & args)
+#proc bundleC2nim(args: string) =
+#  cloneDependency(distDir, "https://github.com/nim-lang/c2nim.git")
+#  nimCompile("dist/c2nim/c2nim",
+#             options = "--noNimblePath --path:. " & args)
 
-proc bundleNimbleExe(latest: bool, args: string) =
-  let commit = if latest: "HEAD" else: NimbleStableCommit
-  cloneDependency(distDir, "https://github.com/nim-lang/nimble.git",
-                  commit = commit, allowBundled = true)
-  cloneDependency(distDir / "nimble" / distDir, "https://github.com/nim-lang/checksums.git",
-                commit = ChecksumsStableCommit, allowBundled = true) # or copy it from dist?
-  cloneDependency(distDir / "nimble" / distDir, "https://github.com/nim-lang/sat.git",
-                commit = SatStableCommit, allowBundled = true)
-  # installer.ini expects it under $nim/bin
-  nimCompile("dist/nimble/src/nimble.nim",
-             options = "-d:release -d:nimNimbleBootstrap --mm:refc --noNimblePath " & args)
+#proc bundleNimbleExe(latest: bool, args: string) =
+#  let commit = if latest: "HEAD" else: NimbleStableCommit
+#  cloneDependency(distDir, "https://github.com/nim-lang/nimble.git",
+#                  commit = commit, allowBundled = true)
+#  cloneDependency(distDir / "nimble" / distDir, "https://github.com/nim-lang/checksums.git",
+#                commit = ChecksumsStableCommit, allowBundled = true) # or copy it from dist?
+#  cloneDependency(distDir / "nimble" / distDir, "https://github.com/nim-lang/sat.git",
+#                commit = SatStableCommit, allowBundled = true)
+#  # installer.ini expects it under $nim/bin
+#  nimCompile("dist/nimble/src/nimble.nim",
+#             options = "-d:release -d:nimNimbleBootstrap --mm:refc --noNimblePath " & args)
 
-proc bundleAtlasExe(latest: bool, args: string) =
-  let commit = if latest: "HEAD" else: AtlasStableCommit
-  cloneDependency(distDir, "https://github.com/nim-lang/atlas.git",
-                  commit = commit, allowBundled = true)
-  cloneDependency(distDir / "atlas" / distDir, "https://github.com/nim-lang/sat.git",
-                commit = SatStableCommit, allowBundled = true)
-  # installer.ini expects it under $nim/bin
-  nimCompile("dist/atlas/src/atlas.nim",
-             options = "-d:release --noNimblePath -d:nimAtlasBootstrap " & args)
+#proc bundleAtlasExe(latest: bool, args: string) =
+#  let commit = if latest: "HEAD" else: AtlasStableCommit
+#  cloneDependency(distDir, "https://github.com/nim-lang/atlas.git",
+#                  commit = commit, allowBundled = true)
+#  cloneDependency(distDir / "atlas" / distDir, "https://github.com/nim-lang/sat.git",
+#                commit = SatStableCommit, allowBundled = true)
+#  # installer.ini expects it under $nim/bin
+#  nimCompile("dist/atlas/src/atlas.nim",
+#             options = "-d:release --noNimblePath -d:nimAtlasBootstrap " & args)
 
 proc bundleNimsuggest(args: string) =
   nimCompileFold("Compile nimsuggest", "nimsuggest/nimsuggest.nim",
@@ -208,8 +208,8 @@ proc zip(latest: bool; args: string) =
 
 proc zip(latest: bool; args: string) =
   bundleChecksums(latest)
-  bundleNimbleExe(latest, args)
-  bundleAtlasExe(latest, args)
+  #bundleNimbleExe(latest, args)
+  #bundleAtlasExe(latest, args)
   bundleNimsuggest(args)
   bundleNimpretty(args)
   bundleWinTools(args)
@@ -218,15 +218,15 @@ proc zip(latest: bool; args: string) =
   exec("$# --var:version=$# --var:mingw=none --main:compiler/nim.nim zip compiler/installer.ini" %
        ["tools/niminst/niminst".exe, VersionAsString])
 
-proc ensureCleanGit() =
-  let (outp, status) = osproc.execCmdEx("git diff")
-  if outp.len != 0:
-    quit "Not a clean git repository; 'git diff' not empty!"
-  if status != 0:
-    quit "Not a clean git repository; 'git diff' returned non-zero!"
+#proc ensureCleanGit() =
+#  let (outp, status) = osproc.execCmdEx("git diff")
+#  if outp.len != 0:
+#    quit "Not a clean git repository; 'git diff' not empty!"
+#  if status != 0:
+#    quit "Not a clean git repository; 'git diff' returned non-zero!"
 
 proc xz(latest: bool; args: string) =
-  ensureCleanGit()
+  #ensureCleanGit()
   nimexec("cc -r $2 --var:version=$1 --var:mingw=none --main:compiler/nim.nim scripts compiler/installer.ini" %
        [VersionAsString, compileNimInst])
   exec("$# --var:version=$# --var:mingw=none --main:compiler/nim.nim xz compiler/installer.ini" %
@@ -262,8 +262,8 @@ proc nsis(latest: bool; args: string) =
 
 proc nsis(latest: bool; args: string) =
   bundleChecksums(latest)
-  bundleNimbleExe(latest, args)
-  bundleAtlasExe(latest, args)
+  #bundleNimbleExe(latest, args)
+  #bundleAtlasExe(latest, args)
   bundleNimsuggest(args)
   bundleWinTools(args)
   # make sure we have generated the niminst executables:
@@ -526,43 +526,43 @@ proc icTest(args: string) =
     exec(cmd)
     inc i
 
-proc buildDrNim(args: string) =
-  if not dirExists("dist/nimz3"):
-    exec("git clone https://github.com/zevv/nimz3.git dist/nimz3")
-  when defined(windows):
-    if not dirExists("dist/dlls"):
-      exec("git clone -q https://github.com/nim-lang/dlls.git dist/dlls")
-    copyExe("dist/dlls/libz3.dll", "bin/libz3.dll")
-    execFold("build drnim", "nim c -o:$1 $2 drnim/drnim" % ["bin/drnim".exe, args])
-  else:
-    if not dirExists("dist/z3"):
-      exec("git clone -q https://github.com/Z3Prover/z3.git dist/z3")
-      withDir("dist/z3"):
-        exec("git fetch")
-        exec("git checkout " & Z3StableCommit)
-        createDir("build")
-        withDir("build"):
-          exec("""cmake -DZ3_BUILD_LIBZ3_SHARED=FALSE -G "Unix Makefiles" ../""")
-          exec("make -j4")
-    execFold("build drnim", "nim cpp --dynlibOverride=libz3 -o:$1 $2 drnim/drnim" % ["bin/drnim".exe, args])
-  # always run the tests for now:
-  exec("testament/testament".exe & " --nim:" & "drnim".exe & " pat drnim/tests")
+#proc buildDrNim(args: string) =
+#  if not dirExists("dist/nimz3"):
+#    exec("git clone https://github.com/zevv/nimz3.git dist/nimz3")
+#  when defined(windows):
+#    if not dirExists("dist/dlls"):
+#      exec("git clone -q https://github.com/nim-lang/dlls.git dist/dlls")
+#    copyExe("dist/dlls/libz3.dll", "bin/libz3.dll")
+#    execFold("build drnim", "nim c -o:$1 $2 drnim/drnim" % ["bin/drnim".exe, args])
+#  else:
+#    if not dirExists("dist/z3"):
+#      exec("git clone -q https://github.com/Z3Prover/z3.git dist/z3")
+#      withDir("dist/z3"):
+#        exec("git fetch")
+#        exec("git checkout " & Z3StableCommit)
+#        createDir("build")
+#        withDir("build"):
+#          exec("""cmake -DZ3_BUILD_LIBZ3_SHARED=FALSE -G "Unix Makefiles" ../""")
+#          exec("make -j4")
+#    execFold("build drnim", "nim cpp --dynlibOverride=libz3 -o:$1 $2 drnim/drnim" % ["bin/drnim".exe, args])
+#  # always run the tests for now:
+#  exec("testament/testament".exe & " --nim:" & "drnim".exe & " pat drnim/tests")
 
 
 proc hostInfo(): string =
   "hostOS: $1, hostCPU: $2, int: $3, float: $4, cpuEndian: $5, cwd: $6" %
     [hostOS, hostCPU, $int.sizeof, $float.sizeof, $cpuEndian, getCurrentDir()]
 
-proc installDeps(dep: string, commit = "") =
-  # the hashes/urls are version controlled here, so can be changed seamlessly
-  # and tied to a nim release (mimicking git submodules)
-  var commit = commit
-  case dep
-  of "tinyc":
-    if commit.len == 0: commit = "916cc2f94818a8a382dd8d4b8420978816c1dfb3"
-    cloneDependency(distDir, "https://github.com/timotheecour/nim-tinyc-archive", commit)
-  else: doAssert false, "unsupported: " & dep
-  # xxx: also add linenoise, niminst etc, refs https://github.com/nim-lang/RFCs/issues/206
+#proc installDeps(dep: string, commit = "") =
+#  # the hashes/urls are version controlled here, so can be changed seamlessly
+#  # and tied to a nim release (mimicking git submodules)
+#  var commit = commit
+#  case dep
+#  of "tinyc":
+#    if commit.len == 0: commit = "916cc2f94818a8a382dd8d4b8420978816c1dfb3"
+#    cloneDependency(distDir, "https://github.com/timotheecour/nim-tinyc-archive", commit)
+#  else: doAssert false, "unsupported: " & dep
+#  # xxx: also add linenoise, niminst etc, refs https://github.com/nim-lang/RFCs/issues/206
 
 proc runCI(cmd: string) =
   doAssert cmd.len == 0, cmd # avoid silently ignoring
@@ -684,18 +684,18 @@ proc showHelp(success: bool) =
   quit(HelpText % [VersionAsString & spaces(44-len(VersionAsString)),
                    CompileDate, CompileTime], if success: QuitSuccess else: QuitFailure)
 
-proc branchDone() =
-  let thisBranch = execProcess("git symbolic-ref --short HEAD").strip()
-  if thisBranch != "devel" and thisBranch != "":
-    exec("git checkout devel")
-    exec("git branch -D " & thisBranch)
-    exec("git pull --rebase")
+#proc branchDone() =
+#  let thisBranch = execProcess("git symbolic-ref --short HEAD").strip()
+#  if thisBranch != "devel" and thisBranch != "":
+#    exec("git checkout devel")
+#    exec("git branch -D " & thisBranch)
+#    exec("git pull --rebase")
 
 when isMainModule:
   var op = initOptParser()
   var
     latest = false
-    localDocsOnly = false
+    localDocsOnly = true
     localDocsOut = ""
     skipIntegrityCheck = false
   while true:
@@ -731,34 +731,34 @@ when isMainModule:
       of "distrohelper": geninstall()
       of "install": install(op.cmdLineRest)
       of "testinstall": testUnixInstall(op.cmdLineRest)
-      of "installdeps": installDeps(op.cmdLineRest)
+      #of "installdeps": installDeps(op.cmdLineRest)
       of "runci": runCI(op.cmdLineRest)
       of "test", "tests": tests(op.cmdLineRest)
       of "temp": temp(op.cmdLineRest)
       of "xtemp": xtemp(op.cmdLineRest)
       of "wintools": bundleWinTools(op.cmdLineRest)
-      of "nimble": bundleNimbleExe(latest, op.cmdLineRest)
-      of "atlas": bundleAtlasExe(latest, op.cmdLineRest)
+      #of "nimble": bundleNimbleExe(latest, op.cmdLineRest)
+      #of "atlas": bundleAtlasExe(latest, op.cmdLineRest)
       of "nimsuggest": bundleNimsuggest(op.cmdLineRest)
       # toolsNoNimble is kept for backward compatibility with build scripts
       of "toolsnonimble", "toolsnoexternal":
         buildTools(op.cmdLineRest)
       of "tools":
         buildTools(op.cmdLineRest)
-        bundleNimbleExe(latest, op.cmdLineRest)
-        bundleAtlasExe(latest, op.cmdLineRest)
+        #bundleNimbleExe(latest, op.cmdLineRest)
+        #bundleAtlasExe(latest, op.cmdLineRest)
       of "checksums":
         bundleChecksums(latest)
-      of "pushcsource":
-        quit "use this instead: https://github.com/nim-lang/csources_v1/blob/master/push_c_code.nim"
+      #of "pushcsource":
+      #  quit "use this instead: https://github.com/nim-lang/csources_v1/blob/master/push_c_code.nim"
       of "valgrind": valgrind(op.cmdLineRest)
-      of "c2nim": bundleC2nim(op.cmdLineRest)
-      of "drnim": buildDrNim(op.cmdLineRest)
+      #of "c2nim": bundleC2nim(op.cmdLineRest)
+      #of "drnim": buildDrNim(op.cmdLineRest)
       of "fusion":
         let suffix = if latest: HeadHash else: FusionStableHash
         exec("nimble install -y fusion@$#" % suffix)
       of "ic": icTest(op.cmdLineRest)
-      of "branchdone": branchDone()
+      #of "branchdone": branchDone()
       else: showHelp(success = false)
       break
     of cmdEnd:
