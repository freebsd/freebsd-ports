--- tools/protoc_wrapper/protoc_wrapper.py.orig	2022-05-11 07:02:09 UTC
+++ tools/protoc_wrapper/protoc_wrapper.py
@@ -190,7 +190,11 @@ def main(argv):
     with open(options.descriptor_set_dependency_file, 'rb') as f:
       dependency_file_data = f.read().decode('utf-8')
 
-  ret = subprocess.call(protoc_cmd)
+  nenv = os.environ.copy()
+  nenv["PATH"] = "${WRKOBJDIR}/bin:" + nenv["PATH"]
+  nenv["LD_LIBRARY_PATH"] = "${WRKSRC}/out/Release"
+
+  ret = subprocess.call(protoc_cmd, env=nenv)
   if ret != 0:
     if ret <= -100:
       # Windows error codes such as 0xC0000005 and 0xC0000409 are much easier to
