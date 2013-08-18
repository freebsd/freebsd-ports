--- gui/qt_libraries.gypi.orig	2013-07-17 11:38:03.000000000 +0900
+++ gui/qt_libraries.gypi	2013-08-18 15:57:44.000000000 +0900
@@ -105,6 +105,7 @@
         }, {
           'libraries': [
             '<!@(<(pkg_config_command) --libs QtGui QtCore)',
+	    '-liconv -L<(localbase)/lib',
           ],
         }],
       ],
