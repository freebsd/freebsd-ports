--- scripts/TestUtil.py.orig	2015-06-23 15:30:20.000000000 +0000
+++ scripts/TestUtil.py	2015-06-27 10:59:56.354249500 +0000
@@ -120,6 +120,25 @@
 def isSles():
     return isLinux() and linuxDistribution and linuxDistribution == "SUSE LINUX"
 
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
@@ -324,7 +324,7 @@
         print("uname failed:\n" + p.stdout.read().strip())
         sys.exit(1)
     line = p.stdout.readline().decode('UTF-8').strip()
-    if line == "x86_64" and os.environ.get("LP64", "") != "no":
+    if line in ["x86_64", "amd64"] and os.environ.get("LP64", "") != "no":
         x64 = True
     elif line == "armv7l":
         armv7l = True
@@ -1887,7 +1906,7 @@
         if lang == "java":
             addLdPath(os.path.join(getIceDir("cpp"), "bin", "x64" if x64 else ""), env) # Add bin for db53_vc100.dll
         addLdPath(getCppLibDir(lang), env)
-    elif lang in ["python", "ruby", "php", "js", "objective-c"]:
+    elif lang in ["cpp", "python", "ruby", "php", "js", "objective-c"]:
         addLdPath(getCppLibDir(lang), env)
 
     if lang == "java":
@@ -2233,6 +2252,14 @@
                 print("%s*** test not supported under Darwin%s" % (prefix, suffix))
                 continue
 
+            if isFreeBSD() and "nofreebsd" in config:
+                print("%s*** test not supported under FreeBSD%s" % (prefix, suffix))
+                continue
+
+            if isFreeBSDJail() and "nofreebsdjail" in config:
+                print("%s*** test not supported within a FreeBSD Jail%s" % (prefix, suffix))
+                continue
+
             if not isWin32() and "win32only" in config:
                 print("%s*** test only supported under Win32%s" % (prefix, suffix))
                 continue
