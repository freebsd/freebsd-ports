--- setup.py.orig	2022-03-30 20:48:59 UTC
+++ setup.py
@@ -32,7 +32,6 @@ def main():
         #package_dir={'CloudFlare/examples': 'examples'},
         #package_data={'cloudflare-examples': ["examples/*"]},
         include_package_data=True,
-        data_files = [('share/man/man1', ['cli4/cli4.1'])],
         install_requires=['requests', 'pyyaml', 'jsonlines', 'beautifulsoup4'],
         keywords='cloudflare',
         entry_points={
