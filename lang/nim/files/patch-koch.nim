--- koch.nim.orig	2024-10-02 01:48:48 UTC
+++ koch.nim
@@ -11,9 +11,9 @@ const
 
 const
   # examples of possible values for repos: Head, ea82b54
-  NimbleStableCommit = "4fb6f8e6c33963f6f510fe82d09ad2a61b5e4265" # 0.16.1
-  AtlasStableCommit = "5faec3e9a33afe99a7d22377dd1b45a5391f5504"
-  ChecksumsStableCommit = "bd9bf4eaea124bf8d01e08f92ac1b14c6879d8d3"
+  NimbleStableCommit = "f8bd7b5fa6ea7a583b411b5959b06e6b5eb23667" # master
+  AtlasStableCommit = "7b780811a168f3f32bff4822369dda46a7f87f9a"
+  ChecksumsStableCommit = "b4c73320253f78e3a265aec6d9e8feb83f97c77b"
   SatStableCommit = "faf1617f44d7632ee9601ebc13887644925dcc01"
 
   # examples of possible values for fusion: #head, #ea82b54, 1.2.3
@@ -150,32 +150,32 @@ proc csource(args: string) =
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
-             options = "-d:release -d:nimNimbleBootstrap --noNimblePath " & args)
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
+#             options = "-d:release -d:nimNimbleBootstrap --noNimblePath " & args)
 
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
@@ -206,14 +206,14 @@ proc bundleWinTools(args: string) =
     nimCompile(r"tools\downloader.nim",
                options = r"--cc:vcc --app:gui -d:ssl --noNimblePath --path:..\ui " & args)
 
-proc bundleChecksums(latest: bool) =
-  let commit = if latest: "HEAD" else: ChecksumsStableCommit
-  cloneDependency(distDir, "https://github.com/nim-lang/checksums.git", commit, allowBundled = true)
+#proc bundleChecksums(latest: bool) =
+#  let commit = if latest: "HEAD" else: ChecksumsStableCommit
+#  cloneDependency(distDir, "https://github.com/nim-lang/checksums.git", commit, allowBundled = true)
 
 proc zip(latest: bool; args: string) =
-  bundleChecksums(latest)
-  bundleNimbleExe(latest, args)
-  bundleAtlasExe(latest, args)
+  #bundleChecksums(latest)
+  #bundleNimbleExe(latest, args)
+  #bundleAtlasExe(latest, args)
   bundleNimsuggest(args)
   bundleNimpretty(args)
   bundleWinTools(args)
@@ -222,15 +222,15 @@ proc zip(latest: bool; args: string) =
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
@@ -265,9 +265,9 @@ proc nsis(latest: bool; args: string) =
   nimCompileFold("Compile testament", "testament/testament.nim", options = "-d:release " & args)
 
 proc nsis(latest: bool; args: string) =
-  bundleChecksums(latest)
-  bundleNimbleExe(latest, args)
-  bundleAtlasExe(latest, args)
+  #bundleChecksums(latest)
+  #bundleNimbleExe(latest, args)
+  #bundleAtlasExe(latest, args)
   bundleNimsuggest(args)
   bundleWinTools(args)
   # make sure we have generated the niminst executables:
@@ -287,21 +287,21 @@ proc install(args: string) =
   geninstall()
   exec("sh ./install.sh $#" % args)
 
-proc installDeps(dep: string, commit = "") =
-  # the hashes/urls are version controlled here, so can be changed seamlessly
-  # and tied to a nim release (mimicking git submodules)
-  var commit = commit
-  case dep
-  of "tinyc":
-    if commit.len == 0: commit = "916cc2f94818a8a382dd8d4b8420978816c1dfb3"
-    cloneDependency(distDir, "https://github.com/timotheecour/nim-tinyc-archive", commit)
-  of "libffi":
-    # technically a nimble package, however to play nicely with --noNimblePath,
-    # let's just clone it wholesale:
-    if commit.len == 0: commit = "bb2bdaf1a29a4bff6fbd8ae4695877cbb3ec783e"
-    cloneDependency(distDir, "https://github.com/Araq/libffi", commit)
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
+#  of "libffi":
+#    # technically a nimble package, however to play nicely with --noNimblePath,
+#    # let's just clone it wholesale:
+#    if commit.len == 0: commit = "bb2bdaf1a29a4bff6fbd8ae4695877cbb3ec783e"
+#    cloneDependency(distDir, "https://github.com/Araq/libffi", commit)
+#  else: doAssert false, "unsupported: " & dep
+#  # xxx: also add linenoise, niminst etc, refs https://github.com/nim-lang/RFCs/issues/206
 
 # -------------- boot ---------------------------------------------------------
 
@@ -345,11 +345,11 @@ proc boot(args: string, skipIntegrityCheck: bool) =
   let smartNimcache = (if "release" in args or "danger" in args: "nimcache/r_" else: "nimcache/d_") &
                       hostOS & "_" & hostCPU
 
-  bundleChecksums(false)
+  #bundleChecksums(false)
 
   let usingLibFFI = "nimHasLibFFI" in args
-  if usingLibFFI and not dirExists("dist/libffi"):
-    installDeps("libffi")
+  #if usingLibFFI and not dirExists("dist/libffi"):
+  #  installDeps("libffi")
 
   let nimStart = findStartNim().quoteShell()
   let times = 2 - ord(skipIntegrityCheck)
@@ -508,7 +508,7 @@ proc temp(args: string) =
       result[1].add " " & quoteShell(args[i])
       inc i
 
-  bundleChecksums(false)
+  #bundleChecksums(false)
 
   let d = getAppDir()
   let output = d / "compiler" / "nim".exe
@@ -552,27 +552,27 @@ proc icTest(args: string) =
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
@@ -620,14 +620,14 @@ proc runCI(cmd: string) =
     # BUG: with initOptParser, `--batch:'' all` interprets `all` as the argument of --batch, pending bug #14343
     execFold("Run tester", "nim c -r --putenv:NIM_TESTAMENT_REMOTE_NETWORKING:1 -d:nimStrictMode testament/testament $# all -d:nimCoroutines" % batchParam)
 
-    block: # nimHasLibFFI:
-      when defined(posix): # windows can be handled in future PR's
-        installDeps("libffi")
-        const nimFFI = "bin/nim.ctffi"
-        # no need to bootstrap with koch boot (would be slower)
-        let backend = if doUseCpp(): "cpp" else: "c"
-        execFold("build with -d:nimHasLibFFI", "nim $1 -d:release --noNimblePath -d:nimHasLibFFI --path:./dist -o:$2 compiler/nim.nim" % [backend, nimFFI])
-        execFold("test with -d:nimHasLibFFI", "$1 $2 -r testament/testament --nim:$1 r tests/misc/trunner.nim -d:nimTrunnerFfi" % [nimFFI, backend])
+    #block: # nimHasLibFFI:
+    #  when defined(posix): # windows can be handled in future PR's
+    #    installDeps("libffi")
+    #    const nimFFI = "bin/nim.ctffi"
+    #    # no need to bootstrap with koch boot (would be slower)
+    #    let backend = if doUseCpp(): "cpp" else: "c"
+    #    execFold("build with -d:nimHasLibFFI", "nim $1 -d:release --noNimblePath -d:nimHasLibFFI --path:./dist -o:$2 compiler/nim.nim" % [backend, nimFFI])
+    #    execFold("test with -d:nimHasLibFFI", "$1 $2 -r testament/testament --nim:$1 r tests/misc/trunner.nim -d:nimTrunnerFfi" % [nimFFI, backend])
 
     execFold("Run nimdoc tests", "nim r nimdoc/tester")
     execFold("Run rst2html tests", "nim r nimdoc/rsttester")
@@ -699,18 +699,18 @@ proc showHelp(success: bool) =
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
@@ -746,34 +746,34 @@ when isMainModule:
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
-      of "checksums":
-        bundleChecksums(latest)
-      of "pushcsource":
-        quit "use this instead: https://github.com/nim-lang/csources_v1/blob/master/push_c_code.nim"
+        #bundleNimbleExe(latest, op.cmdLineRest)
+        #bundleAtlasExe(latest, op.cmdLineRest)
+      #of "checksums":
+      #  bundleChecksums(latest)
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
