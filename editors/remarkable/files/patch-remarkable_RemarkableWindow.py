--- remarkable/RemarkableWindow.py.orig	2024-09-22 10:47:53 UTC
+++ remarkable/RemarkableWindow.py
@@ -36,10 +36,10 @@ import pdfkit
 import re, subprocess, datetime, os, webbrowser, _thread, sys, locale
 import tempfile
 import traceback
-import styles
+from remarkable import styles
 import unicodedata
 import warnings
-from findBar import FindBar
+from remarkable.findBar import FindBar
 
 # Check if gtkspellcheck is installed
 try:
