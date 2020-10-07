--- cmake/make_versioncpp.py.orig	2020-09-25 11:06:39 UTC
+++ cmake/make_versioncpp.py
@@ -127,18 +127,6 @@ version = "0.4.10.1"
 branch = ""
 build_no = INVALID_BUILD_NO
 
-try:
-    branch = check_output(['git', 'rev-parse', '--abbrev-ref', 'HEAD'], universal_newlines=True).strip()
-    if (branch == "master") or (branch[:7] == "release"):
-        branch = ""
-    else:
-        branch += " "
-    commit = check_output(["git", "show", "--no-show-signature", "-s", "--format=%h", "--abbrev=7", "HEAD"], universal_newlines=True).strip()
-    timestamp = float(check_output(["git", "show", "--no-show-signature", "-s", "--format=%ct", "HEAD"], universal_newlines=True).strip())
-    build_no = ".".join([datetime.utcfromtimestamp(timestamp).strftime("%Y-%m-%d"), commit])
-except (IOError, CalledProcessError):
-    print("WARNING: git not installed or not setup correctly")
-
 for generator in generators:
     generator.execute(version, branch, build_no, build_sys)
 
