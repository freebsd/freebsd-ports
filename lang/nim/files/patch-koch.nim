--- koch.nim.orig	2019-07-22 09:56:30 UTC
+++ koch.nim
@@ -43,15 +43,11 @@ Usage:
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
@@ -127,41 +123,6 @@ proc bundleC2nim(args: string) =
   nimCompile("dist/c2nim/c2nim",
              options = "--noNimblePath --path:. " & args)
 
-proc bundleNimbleExe(latest: bool, args: string) =
-  if not dirExists("dist/nimble/.git"):
-    exec("git clone https://github.com/nim-lang/nimble.git dist/nimble")
-  if not latest:
-    withDir("dist/nimble"):
-      exec("git fetch")
-      exec("git checkout " & NimbleStableCommit)
-  # installer.ini expects it under $nim/bin
-  nimCompile("dist/nimble/src/nimble.nim",
-             options = "-d:release --nilseqs:on " & args)
-
-proc buildNimble(latest: bool, args: string) =
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
-  nimCompile(installDir / "src/nimble.nim",
-             options = "--noNimblePath --nilseqs:on -d:release " & args)
-
 proc bundleNimsuggest(args: string) =
   nimCompileFold("Compile nimsuggest", "nimsuggest/nimsuggest.nim",
                  options = "-d:release -d:danger " & args)
@@ -182,7 +143,6 @@ proc bundleWinTools(args: string) =
                options = r"--cc:vcc --app:gui -d:ssl --noNimblePath --path:..\ui " & args)
 
 proc zip(latest: bool; args: string) =
-  bundleNimbleExe(latest, args)
   bundleNimsuggest(args)
   bundleWinTools(args)
   nimexec("cc -r $2 --var:version=$1 --var:mingw=none --main:compiler/nim.nim scripts compiler/installer.ini" %
@@ -219,7 +179,6 @@ proc buildTools(args: string = "") =
                  options = "-d:release " & args)
 
 proc nsis(latest: bool; args: string) =
-  bundleNimbleExe(latest, args)
   bundleNimsuggest(args)
   bundleWinTools(args)
   # make sure we have generated the niminst executables:
@@ -466,8 +425,6 @@ proc runCI(cmd: string) =
   # boot without -d:nimHasLibFFI to make sure this still works
   kochExecFold("Boot in release mode", "boot -d:release -d:danger")
 
-  ## build nimble early on to enable remainder to depend on it if needed
-  kochExecFold("Build Nimble", "nimble")
 
   when false:
     execFold("nimble install -y libffi", "nimble install -y libffi")
@@ -588,8 +545,6 @@ when isMainModule:
     case op.kind
     of cmdLongOption, cmdShortOption:
       case normalize(op.key)
-      of "latest": latest = true
-      of "stable": latest = false
       else: showHelp()
     of cmdArgument:
       case normalize(op.key)
@@ -613,13 +568,9 @@ when isMainModule:
       of "temp": temp(op.cmdLineRest)
       of "xtemp": xtemp(op.cmdLineRest)
       of "wintools": bundleWinTools(op.cmdLineRest)
-      of "nimble": buildNimble(latest, op.cmdLineRest)
       of "nimsuggest": bundleNimsuggest(op.cmdLineRest)
-      of "toolsnonimble":
-        buildTools(op.cmdLineRest)
       of "tools":
         buildTools(op.cmdLineRest)
-        buildNimble(latest, op.cmdLineRest)
       of "pushcsource", "pushcsources": pushCsources()
       of "valgrind": valgrind(op.cmdLineRest)
       of "c2nim": bundleC2nim(op.cmdLineRest)
