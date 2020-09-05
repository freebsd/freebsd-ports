--- setup.py.orig	2020-09-02 05:16:18 UTC
+++ setup.py
@@ -923,7 +923,6 @@ in COPYING-LGPL_ and COPYING-MIT_ files in the source 
     ],
     packages=[PY_PACKAGE],
     package_dir={ PY_PACKAGE: os.path.join('python', 'curl') },
-    python_requires='>=3.5',
 )
 
 if sys.platform == "win32":
@@ -980,7 +979,6 @@ if __name__ == "__main__":
     elif len(sys.argv) > 1 and sys.argv[1] == 'docstrings-sources':
         gen_docstrings_sources()
     else:
-        setup_args['data_files'] = get_data_files()
         if 'PYCURL_RELEASE' in os.environ and os.environ['PYCURL_RELEASE'].lower() in ['1', 'yes', 'true']:
             split_extension_source = False
         else:
