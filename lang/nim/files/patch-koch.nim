--- koch.nim.orig	2019-06-06 19:33:01 UTC
+++ koch.nim
@@ -9,9 +9,6 @@
 #    See doc/koch.txt for documentation.
 #
 
-const
-  NimbleStableCommit = "d15c8530cb7480ce39ffa85a2dd9819d2d4fc645" # 0.10.2
-
 when defined(gcc) and defined(windows):
   when defined(x86):
     {.link: "icons/koch.res".}
@@ -43,15 +40,11 @@ Usage:
   koch [options] command [options for command]
 Options:
   --help, -h               shows this help and quits
-  --latest                 bundle the installers with a bleeding edge Nimble
-  --stable                 bundle the installers with a stable Nimble (default)
 Possible Commands:
   boot [options]           bootstraps with given command line options
   distrohelper [bindir]    helper for distro packagers
-  tools                    builds Nim related tools
-  toolsNoNimble            builds Nim related tools (except nimble)
+  tools                    builds Nim related tools (except nimble)
                            doesn't require network connectivity
-  nimble                   builds the Nimble tool
 Boot options:
   -d:release               produce a release version of the compiler
   -d:useLinenoise          use the linenoise library for interactive mode
@@ -126,39 +119,6 @@ proc bundleC2nim() =
     exec("git clone https://github.com/nim-lang/c2nim.git dist/c2nim")
   nimCompile("dist/c2nim/c2nim", options = "--noNimblePath --path:.")
 
-proc bundleNimbleExe(latest: bool) =
-  if not dirExists("dist/nimble/.git"):
-    exec("git clone https://github.com/nim-lang/nimble.git dist/nimble")
-  if not latest:
-    withDir("dist/nimble"):
-      exec("git fetch")
-      exec("git checkout " & NimbleStableCommit)
-  # installer.ini expects it under $nim/bin
-  nimCompile("dist/nimble/src/nimble.nim", options = "-d:release --nilseqs:on")
-
-proc buildNimble(latest: bool) =
-  # if koch is used for a tar.xz, build the dist/nimble we shipped
-  # with the tarball:
-  var installDir = "dist/nimble"
-  if not latest and dirExists(installDir) and not dirExists("dist/nimble/.git"):
-    discard "don't do the git dance"
-  else:
-    if not dirExists("dist/nimble/.git"):
-      if dirExists(installDir):
-        var id = 0
-        while dirExists("dist/nimble" & $id):
-          inc id
-        installDir = "dist/nimble" & $id
-      exec("git clone https://github.com/nim-lang/nimble.git " & installDir)
-    withDir(installDir):
-      if latest:
-        exec("git checkout -f master")
-        exec("git pull")
-      else:
-        exec("git fetch")
-        exec("git checkout " & NimbleStableCommit)
-  nimCompile(installDir / "src/nimble.nim", options = "--noNimblePath --nilseqs:on -d:release")
-
 proc bundleNimsuggest() =
   nimCompileFold("Compile nimsuggest", "nimsuggest/nimsuggest.nim", options = "-d:release -d:danger")
 
@@ -177,7 +137,6 @@ proc bundleWinTools() =
     nimCompile(r"tools\downloader.nim", options = r"--cc:vcc --app:gui -d:ssl --noNimblePath --path:..\ui")
 
 proc zip(latest: bool; args: string) =
-  bundleNimbleExe(latest)
   bundleNimsuggest()
   bundleWinTools()
   nimexec("cc -r $2 --var:version=$1 --var:mingw=none --main:compiler/nim.nim scripts compiler/installer.ini" %
@@ -211,7 +170,6 @@ proc buildTools() =
   nimCompileFold("Compile nimfind", "tools/nimfind.nim", options = "-d:release")
 
 proc nsis(latest: bool; args: string) =
-  bundleNimbleExe(latest)
   bundleNimsuggest()
   bundleWinTools()
   # make sure we have generated the niminst executables:
@@ -457,17 +415,14 @@ proc runCI(cmd: string) =
   # boot without -d:nimHasLibFFI to make sure this still works
   kochExecFold("Boot in release mode", "boot -d:release -d:danger")
 
-  ## build nimble early on to enable remainder to depend on it if needed
-  kochExecFold("Build Nimble", "nimble")
 
   when false:
-    execFold("nimble install -y libffi", "nimble install -y libffi")
     kochExecFold("boot -d:release -d:nimHasLibFFI", "boot -d:release -d:nimHasLibFFI")
 
   if getEnv("NIM_TEST_PACKAGES", "false") == "true":
     execFold("Test selected Nimble packages", "nim c -r testament/tester cat nimble-packages")
   else:
-    buildTools() # altenatively, kochExec "tools --toolsNoNimble"
+    buildTools()
 
     ## run tests
     execFold("Test nimscript", "nim e tests/test_nimscript.nims")
@@ -579,8 +534,6 @@ when isMainModule:
     case op.kind
     of cmdLongOption, cmdShortOption:
       case normalize(op.key)
-      of "latest": latest = true
-      of "stable": latest = false
       else: showHelp()
     of cmdArgument:
       case normalize(op.key)
@@ -604,13 +557,9 @@ when isMainModule:
       of "temp": temp(op.cmdLineRest)
       of "xtemp": xtemp(op.cmdLineRest)
       of "wintools": bundleWinTools()
-      of "nimble": buildNimble(latest)
       of "nimsuggest": bundleNimsuggest()
-      of "toolsnonimble":
-        buildTools()
       of "tools":
         buildTools()
-        buildNimble(latest)
       of "pushcsource", "pushcsources": pushCsources()
       of "valgrind": valgrind(op.cmdLineRest)
       of "c2nim": bundleC2nim()
