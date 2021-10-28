--- koch.nim.orig	2021-10-19 00:39:28 UTC
+++ koch.nim
@@ -139,18 +139,18 @@ proc csource(args: string) =
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
-  # installer.ini expects it under $nim/bin
-  nimCompile("dist/nimble/src/nimble.nim",
-             options = "-d:release --noNimblePath " & args)
+#proc bundleNimbleExe(latest: bool, args: string) =
+#  let commit = if latest: "HEAD" else: NimbleStableCommit
+#  cloneDependency(distDir, "https://github.com/nim-lang/nimble.git",
+#                  commit = commit, allowBundled = true)
+#  # installer.ini expects it under $nim/bin
+#  nimCompile("dist/nimble/src/nimble.nim",
+#             options = "-d:release --noNimblePath " & args)
 
 proc bundleNimsuggest(args: string) =
   nimCompileFold("Compile nimsuggest", "nimsuggest/nimsuggest.nim",
@@ -182,7 +182,7 @@ proc bundleWinTools(args: string) =
                options = r"--cc:vcc --app:gui -d:ssl --noNimblePath --path:..\ui " & args)
 
 proc zip(latest: bool; args: string) =
-  bundleNimbleExe(latest, args)
+  #bundleNimbleExe(latest, args)
   bundleNimsuggest(args)
   bundleNimpretty(args)
   bundleWinTools(args)
@@ -191,15 +191,15 @@ proc zip(latest: bool; args: string) =
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
@@ -231,7 +231,7 @@ proc buildTools(args: string = "") =
 
 
 proc nsis(latest: bool; args: string) =
-  bundleNimbleExe(latest, args)
+  #bundleNimbleExe(latest, args)
   bundleNimsuggest(args)
   bundleWinTools(args)
   # make sure we have generated the niminst executables:
@@ -503,27 +503,27 @@ proc icTest(args: string) =
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
@@ -535,9 +535,9 @@ proc installDeps(dep: string, commit = "") =
   # and tied to a nim release (mimicking git submodules)
   var commit = commit
   case dep
-  of "tinyc":
-    if commit.len == 0: commit = "916cc2f94818a8a382dd8d4b8420978816c1dfb3"
-    cloneDependency(distDir, "https://github.com/timotheecour/nim-tinyc-archive", commit)
+  #of "tinyc":
+  #  if commit.len == 0: commit = "916cc2f94818a8a382dd8d4b8420978816c1dfb3"
+  #  cloneDependency(distDir, "https://github.com/timotheecour/nim-tinyc-archive", commit)
   else: doAssert false, "unsupported: " & dep
   # xxx: also add linenoise, niminst etc, refs https://github.com/nim-lang/RFCs/issues/206
 
@@ -599,7 +599,7 @@ proc runCI(cmd: string) =
       execFold("build nimsuggest_testing", "nim c -o:bin/nimsuggest_testing -d:release nimsuggest/nimsuggest")
       execFold("Run nimsuggest tests", "nim r nimsuggest/tester")
 
-    execFold("Run atlas tests", "nim c -r -d:atlasTests tools/atlas/atlas.nim clone https://github.com/disruptek/balls")
+    #execFold("Run atlas tests", "nim c -r -d:atlasTests tools/atlas/atlas.nim clone https://github.com/disruptek/balls")
 
   when not defined(bsd):
     if not doUseCpp:
@@ -662,12 +662,12 @@ proc showHelp(success: bool) =
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
@@ -712,24 +712,24 @@ when isMainModule:
       of "temp": temp(op.cmdLineRest)
       of "xtemp": xtemp(op.cmdLineRest)
       of "wintools": bundleWinTools(op.cmdLineRest)
-      of "nimble": bundleNimbleExe(latest, op.cmdLineRest)
+      #of "nimble": bundleNimbleExe(latest, op.cmdLineRest)
       of "nimsuggest": bundleNimsuggest(op.cmdLineRest)
       # toolsNoNimble is kept for backward compatibility with build scripts
       of "toolsnonimble", "toolsnoexternal":
         buildTools(op.cmdLineRest)
       of "tools":
         buildTools(op.cmdLineRest)
-        bundleNimbleExe(latest, op.cmdLineRest)
-      of "pushcsource":
-        quit "use this instead: https://github.com/nim-lang/csources_v1/blob/master/push_c_code.nim"
+        #bundleNimbleExe(latest, op.cmdLineRest)
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
