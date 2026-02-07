--- setup.py.orig	2021-08-15 19:30:48 UTC
+++ setup.py
@@ -990,7 +990,6 @@ if __name__ == "__main__":
     else:
         convert_docstrings()
 
-        setup_args['data_files'] = get_data_files()
         if 'PYCURL_RELEASE' in os.environ and os.environ['PYCURL_RELEASE'].lower() in ['1', 'yes', 'true']:
             split_extension_source = False
         else:
