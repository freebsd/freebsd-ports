--- setup.py.orig	2026-04-30 02:39:54 UTC
+++ setup.py
@@ -944,7 +944,6 @@ if __name__ == "__main__":
         if sys.argv[1] not in ['clean'] and (not os.path.exists('src/docstrings.c') or not os.path.exists('src/docstrings.h')):
             convert_docstrings()
 
-        setup_args['data_files'] = get_data_files()
         if 'PYCURL_RELEASE' in os.environ and os.environ['PYCURL_RELEASE'].lower() in ['1', 'yes', 'true']:
             split_extension_source = False
         else:
