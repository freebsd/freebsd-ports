Fix value errors for some tests:

>           psnr = float(psnr.strip(b"0"))
E           ValueError: could not convert string to float: b'61.5441 (0.615441)'
src/img2pdf_test.py:347: ValueError

Obtained from:

https://gitlab.mister-muffin.de/josch/img2pdf/issues/152

--- src/img2pdf_test.py.orig	2023-03-30 18:01:47 UTC
+++ src/img2pdf_test.py
@@ -345,7 +345,7 @@ def compare(im1, im2, exact, icc, cmyk):
             stderr=subprocess.PIPE,
         ).stderr
         assert psnr != b"0"
-        psnr = float(psnr.strip(b"0"))
+        psnr = float(psnr.split()[0])
         assert psnr != 0  # or otherwise we would use the exact variant
         assert psnr > 50
 
@@ -501,7 +501,7 @@ def compare_pdfimages_png(tmpdir, img, pdf, exact=True
                 stderr=subprocess.PIPE,
             ).stderr
         assert psnr != b"0"
-        psnr = float(psnr.strip(b"0"))
+        psnr = float(psnr.split()[0])
         assert psnr != 0  # or otherwise we would use the exact variant
         assert psnr > 50
     (tmpdir / "images-000.png").unlink()
