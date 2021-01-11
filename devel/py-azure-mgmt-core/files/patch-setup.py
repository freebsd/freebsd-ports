--- setup.py.orig	2020-10-05 05:36:52 UTC
+++ setup.py
@@ -21,7 +21,7 @@ package_folder_path = PACKAGE_NAME.replace('-', '/')
 namespace_name = PACKAGE_NAME.replace('-', '.')
 
 # Version extraction inspired from 'requests'
-with open(os.path.join(package_folder_path, '_version.py'), 'r') as fd:
+with open(os.path.join(package_folder_path, '_version.py'), 'r', encoding='utf-8') as fd:
     version = re.search(r'^VERSION\s*=\s*[\'"]([^\'"]*)[\'"]',  # type: ignore
                         fd.read(), re.MULTILINE).group(1)
 
