--- TclPrimGhc.hs.orig	Fri Feb 23 13:23:23 2001
+++ TclPrimGhc.hs	Thu Oct 23 09:11:54 2003
@@ -42,7 +42,7 @@
  writeElt pstr 0 str
  return pstr
   where
-   len = Word.intToWord32 (length str + 1)
+   len = fromIntegral (length str + 1)
 
    writeElt addr n [] = writeCharOffAddr addr n '\0'
    writeElt addr n (v :vs) = do
