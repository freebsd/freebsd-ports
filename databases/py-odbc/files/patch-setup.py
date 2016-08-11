--- setup.py.orig	2015-04-29 16:10:15 UTC
+++ setup.py
@@ -187,6 +187,15 @@ def get_compiler_settings(version_str):
         # What is the proper way to detect iODBC, MyODBC, unixODBC, etc.?
         settings['libraries'].append('odbc')
 
+	if sys.platform.startswith('freebsd'):
+	    settings['library_dirs'] = ['/usr/local/lib/']
+	    settings['include_dirs'] = ['/usr/local/include/']
+	    freebsd_prefix = '/usr/local'
+	    if 'PREFIX' in os.environ:
+		freebsd_prefix = os.environ['PREFIX']
+	    if 'PYTHONPREFIX_SITELIBDIR' in os.environ:
+		sys.path.append('/'.join(freebsd_prefix, os.environ['PYTHONPREFIX_SITELIBDIR']))
+
     return settings
 
 
