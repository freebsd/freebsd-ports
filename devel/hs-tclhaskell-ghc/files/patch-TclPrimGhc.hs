--- TclPrimGhc.hs.orig	Tue Oct 21 17:29:21 2003
+++ TclPrimGhc.hs	Tue Oct 21 17:29:43 2003
@@ -42,7 +42,7 @@
  writeElt pstr 0 str
  return pstr
   where
-   len = Word.intToWord32 (length str + 1)
+   len = fromIntegral (length str + 1)
 
    writeElt addr n [] = writeCharOffAddr addr n '\0'
    writeElt addr n (v :vs) = do
