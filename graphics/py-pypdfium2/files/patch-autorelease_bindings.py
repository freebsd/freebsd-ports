-- Add the graphics/pdfium shared library path to the reference bindings'
-- runtime library search list, so pypdfium2 can load libpdfium.so from
-- /usr/local/lib on FreeBSD.
--- autorelease/bindings.py.orig	2026-09-24 10:09:51 UTC
+++ autorelease/bindings.py
@@ -67,7 +67,7 @@ _libs['pdfium'] = _get_library(
 _libs['pdfium'] = _get_library(
     name = 'pdfium',
     dllclass = ctypes.CDLL,
-    libpaths = ('./{prefix}{name}.{suffix}', '/usr/lib64/libreoffice/program/libpdfiumlo.so', '/usr/lib/libreoffice/program/libpdfiumlo.so', '/usr/local/lib64/libreoffice/program/libpdfiumlo.so', '/usr/local/lib/libreoffice/program/libpdfiumlo.so'),
+    libpaths = ('./{prefix}{name}.{suffix}', '/usr/local/lib/libpdfium.so', '/usr/lib64/libreoffice/program/libpdfiumlo.so', '/usr/lib/libreoffice/program/libpdfiumlo.so', '/usr/local/lib64/libreoffice/program/libpdfiumlo.so', '/usr/local/lib/libreoffice/program/libpdfiumlo.so'),
     search_sys = True,
 )
 
