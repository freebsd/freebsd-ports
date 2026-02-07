--- scripts/TestUtil.py.orig	2019-08-12 19:54:18 UTC
+++ scripts/TestUtil.py
@@ -145,6 +145,25 @@ def isSles():
 def iceUseOpenSSL():
     return any(sys.platform.startswith(p) for p in ["linux", "freebsd"])
 
+def isFreeBSD():
+    return sys.platform.startswith("freebsd")
+
+def sysctl(key):
+    p = subprocess.Popen("sysctl "+key, shell=1, stdout=subprocess.PIPE)
+    try:
+        result = p.communicate()[0].strip().split()[1]
+    except IndexError:
+        return 0    
+    if sys.version_info >= (3,):
+        result = str(result, sys.stdout.encoding)
+    try:
+        return int(result)
+    except ValueError:
+        return result
+
+def isFreeBSDJail():
+    return isFreeBSD() and sysctl("security.jail.jailed")
+
 def getCppCompiler():
     compiler = ""
     if os.environ.get("CPP_COMPILER", "") != "":
@@ -340,7 +359,7 @@ else:
         print("uname failed:\n" + p.stdout.read().strip())
         sys.exit(1)
     line = p.stdout.readline().decode('UTF-8').strip()
-    if line == "x86_64" and os.environ.get("LP64", "") != "no":
+    if line in ["x86_64", "amd64"] and os.environ.get("LP64", "") != "no":
         x64 = True
     elif line == "armv7l":
         armv7l = True
@@ -879,7 +898,7 @@ def hashPasswords(filePath, entries):
       os.remove(filePath)
     passwords = open(filePath, "a")
 
-    command = '"%s" "%s"' % (sys.executable,
+    command = '"%s" "%s" 2>/dev/null' % (sys.executable,
                            os.path.abspath(os.path.join(os.path.dirname(__file__), "icehashpassword.py")))
 
     #
@@ -2018,7 +2037,7 @@ def getTestEnv(lang, testdir):
             addLdPath(getCppLibDir(lang), env)
     elif isAIX():
         addLdPath(getCppLibDir(lang), env)
-    elif lang in ["python", "ruby", "php", "js", "objective-c"]:
+    elif lang in ["cpp", "python", "ruby", "php", "js", "objective-c"]:
         # C++ binaries use rpath $ORIGIN or similar to find the Ice libraries
         addLdPath(getCppLibDir(lang), env)
 
@@ -2369,6 +2388,14 @@ def runTests(start, expanded, num = 0, script = False)
 
             if isYocto() and "noyocto" in config:
                 print("%s*** test not supported under Yocto%s" % (prefix, suffix))
+                continue
+
+            if isFreeBSD() and "nofreebsd" in config:
+                print("%s*** test not supported under FreeBSD%s" % (prefix, suffix))
+                continue
+
+            if isFreeBSDJail() and "nofreebsdjail" in config:
+                print("%s*** test not supported within a FreeBSD Jail%s" % (prefix, suffix))
                 continue
 
             if not isWin32() and "win32only" in config:
