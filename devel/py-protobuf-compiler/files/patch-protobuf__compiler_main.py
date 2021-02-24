--- protobuf_compiler/main.py.orig	2021-02-24 09:06:33 UTC
+++ protobuf_compiler/main.py
@@ -100,7 +100,7 @@ def main():
     for f in files:
         file_name = f.split(os.path.sep)[-1]
         folder = f.replace(file_name,"").replace(input_dir + os.path.sep, "")
-        command = "python3 -m grpc_tools.protoc -I. \
+        command = "%%PYTHON_CMD%% -m grpc_tools.protoc -I. \
                                  --proto_path=" + input_dir + " \
                                  --python_out=" + os.path.join(output_dir, package_name) + " \
                                  --grpc_python_out=" + os.path.join(output_dir, package_name) + " \
@@ -130,7 +130,7 @@ setup(
     description=''
 )
         """)
-    command = "cd " + os.path.join(output_dir, package_name) + " && python3 setup.py sdist"
+    command = "cd " + os.path.join(output_dir, package_name) + " && %%PYTHON_CMD%% setup.py sdist"
     out = os.system(command)
     # print(out)
     if args.repository != '':
