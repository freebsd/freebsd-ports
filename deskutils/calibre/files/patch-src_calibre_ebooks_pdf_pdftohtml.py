--- src/calibre/ebooks/pdf/pdftohtml.py.orig	2009-10-11 19:20:09.000000000 +0400
+++ src/calibre/ebooks/pdf/pdftohtml.py	2009-10-11 19:20:25.000000000 +0400
@@ -12,7 +12,7 @@
 from functools import partial
 
 from calibre.ebooks import ConversionError, DRMError
-from calibre import isosx, iswindows, islinux
+from calibre import isosx, iswindows, islinux, isfreebsd
 from calibre import CurrentDir
 
 PDFTOHTML = 'pdftohtml'
@@ -22,7 +22,7 @@
 if iswindows and hasattr(sys, 'frozen'):
     PDFTOHTML = os.path.join(os.path.dirname(sys.executable), 'pdftohtml.exe')
     popen = partial(subprocess.Popen, creationflags=0x08) # CREATE_NO_WINDOW=0x08 so that no ugly console is popped up
-if islinux and getattr(sys, 'frozen_path', False):
+if (islinux or isfreebsd) and getattr(sys, 'frozen_path', False):
     PDFTOHTML = os.path.join(getattr(sys, 'frozen_path'), 'pdftohtml')
 
 def pdftohtml(output_dir, pdf_path, no_images):
