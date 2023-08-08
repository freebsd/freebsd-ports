--- cmake/make_versioncpp.py.orig	2023-03-21 15:16:58 UTC
+++ cmake/make_versioncpp.py
@@ -136,26 +136,6 @@ branch = ""
 build_no = INVALID_BUILD_NO
 version_file_name = version
 
-try:
-    branch = check_output(["git", "rev-parse", "--abbrev-ref", "HEAD"], text=True).strip()
-    if (branch == "master") or (branch == "weekly-test-builds") or (branch[:7] == "release"):
-        branch = ""
-    else:
-        branch += " "
-    commit = check_output(
-        ["git", "show", "--no-show-signature", "-s", "--format=%h", "--abbrev=7", "HEAD"], text=True
-    ).strip()
-    timestamp = float(
-        check_output(["git", "show", "--no-show-signature", "-s", "--format=%ct", "HEAD"], text=True).strip()
-    )
-    build_no = ".".join([datetime.utcfromtimestamp(timestamp).strftime("%Y-%m-%d"), commit])
-    if branch[:7] == "release":
-        version_file_name = "v" + version
-    else:
-        version_file_name = build_no + "_Test"
-except (OSError, CalledProcessError):
-    print("WARNING: git not installed or not setup correctly")
-
 for generator in generators:
     generator.execute(version, branch, build_no, build_sys, version_file_name)
 
