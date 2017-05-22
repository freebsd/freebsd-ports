--- zim/newfs/__init__.py.orig	2017-05-08 19:57:42 UTC
+++ zim/newfs/__init__.py
@@ -6,12 +6,14 @@
 
 import sys
 import os
+import logging
 
 FS_CASE_SENSITIVE = (os.name != 'nt') #: file system case-sensitive yes or no
 
 FS_SUPPORT_NON_LOCAL_FILE_SHARES = (os.name == 'nt') #: Support \\host\share paths yes or no
 
 FS_ENCODING = sys.getfilesystemencoding() #: file system encoding for paths
+logger = logging.getLogger('zim.newfs')
 if FS_ENCODING.upper() in (
 	'ASCII', 'US-ASCII', 'ANSI_X3.4-1968', 'ISO646-US', # some aliases for ascii
 	'LATIN1', 'ISO-8859-1', 'ISO_8859-1', 'ISO_8859-1:1987', # aliases for latin1
