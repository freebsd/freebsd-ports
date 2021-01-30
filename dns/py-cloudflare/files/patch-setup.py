--- setup.py.orig	2020-08-13 01:09:48 UTC
+++ setup.py
@@ -31,7 +31,7 @@ def main():
         #package_dir={'CloudFlare/examples': 'examples'},
         #package_data={'cloudflare-examples': ["examples/*"]},
         include_package_data=True,
-        data_files = [('man/man1', ['cli4/cli4.man'])],
+        #data_files = [('man/man1', ['cli4/cli4.man'])],
         install_requires=['requests', 'pyyaml', 'jsonlines', 'beautifulsoup4'],
         keywords='cloudflare',
         entry_points={
