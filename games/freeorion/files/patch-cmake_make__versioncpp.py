--- cmake/make_versioncpp.py.orig	2017-09-03 13:21:52 UTC
+++ cmake/make_versioncpp.py
@@ -115,19 +115,7 @@ if system() == 'Darwin':
 
 version = "0.4.7.1"
 branch = ""
-build_no = INVALID_BUILD_NO
-
-try:
-    branch = check_output(['git', 'rev-parse', '--abbrev-ref', 'HEAD']).strip()
-    if (branch == "master") or (branch[:7] == "release"):
-        branch = ""
-    else:
-        branch += " "
-    commit = check_output(["git", "show", "-s", "--format=%h", "--abbrev=7", "HEAD"]).strip()
-    timestamp = float(check_output(["git", "show", "-s", "--format=%ct", "HEAD"]).strip())
-    build_no = ".".join([datetime.utcfromtimestamp(timestamp).strftime("%Y-%m-%d"), commit])
-except:
-    print "WARNING: git not installed or not setup correctly"
+build_no = "portbld"
 
 for generator in generators:
     generator.execute(version, branch, build_no, build_sys)
