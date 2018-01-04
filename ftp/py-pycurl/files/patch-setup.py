--- setup.py.orig	2016-02-04 04:39:06 UTC
+++ setup.py
@@ -815,7 +815,6 @@ if __name__ == "__main__":
     elif len(sys.argv) > 1 and sys.argv[1] == 'docstrings-sources':
         gen_docstrings_sources()
     else:
-        setup_args['data_files'] = get_data_files()
         if 'PYCURL_RELEASE' in os.environ and os.environ['PYCURL_RELEASE'].lower() in ['1', 'yes', 'true']:
             split_extension_source = False
         else:
