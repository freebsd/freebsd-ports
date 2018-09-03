--- capstone/__init__.py.orig	2018-07-18 16:17:10 UTC
+++ capstone/__init__.py
@@ -236,6 +236,7 @@ _cs = None
 # - last-gasp attempt at some hardcoded paths on darwin and linux
 
 _path_list = [os.getenv('LIBCAPSTONE_PATH', None),
+              '%%LOCALBASE%%/lib',
               pkg_resources.resource_filename(__name__, 'lib'),
               join(split(__file__)[0], 'lib'),
               '',
