--- setup.py.orig	Mon Apr 25 15:50:35 2005
+++ setup.py	Mon Apr 25 15:50:42 2005
@@ -78,7 +78,6 @@ fairly infrequent."""
           author_email          = "pychecker@metaslash.com",
           url                   = "http://pychecker.sourceforge.net/",
           packages              = [ 'pychecker' ],
-          data_files            = [ (install_dir, DOC_FILES) ],
           scripts               = [ LOCAL_SCRIPT, ],
           # classifiers was added in Python 2.3, but needed for PyPI
           #classifiers           = CLASSIFIERS,
