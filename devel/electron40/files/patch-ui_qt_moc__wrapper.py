--- ui/qt/moc_wrapper.py.orig	2025-06-30 07:04:30 UTC
+++ ui/qt/moc_wrapper.py
@@ -20,4 +20,4 @@ else:
 if args.path is None:
     subprocess.check_call(["moc", args.input, "-o", args.output])
 else:
-    subprocess.check_call([args.path + "/moc", args.input, "-o", args.output])
+    subprocess.check_call([args.path, args.input, "-o", args.output])
