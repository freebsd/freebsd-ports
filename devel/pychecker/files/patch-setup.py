
$FreeBSD$

--- setup.py
+++ setup.py
@@ -187,7 +187,6 @@
         'url'              : "http://pychecker.sourceforge.net/",
         'packages'         : [ 'pychecker', ],
         'scripts'          : [ "pychecker" ],   # note: will be replaced by customized action
-        'data_files'       : [ ( "pychecker", DATA_FILES, ) ], 
         'long_description' : LONG_DESCRIPTION,
         'cmdclass'         : CUSTOMIZED_ACTIONS, 
       }
