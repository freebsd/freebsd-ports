--- src/haskell/StdPkl.hs.orig	1999-09-13 00:27:00.000000000 +0200
+++ src/haskell/StdPkl.hs	2007-10-01 12:43:41.000000000 +0200
@@ -50,9 +50,9 @@
 write_integral :: Integral a => a -> Handle -> IO ()
 write_integral n s = loop (abs n)
 	        where 
-		loop x | x <= 63   = hPutChar s (chr (toInt(finish (n<0) x)))
+		loop x | x <= 63   = hPutChar s (chr (fromIntegral(finish (n<0) x)))
 		       | otherwise = do 
-				      hPutChar s (chr (toInt(nibble x)))
+				      hPutChar s (chr (fromIntegral(nibble x)))
 				      loop (x `shiftr` 7)
 	        nibble n = ((n `andb` 0x7f) `orb` 0x80) `andb` 0xff
 		finish False n = n `andb` 255
@@ -63,14 +63,14 @@
 read_integral s  
  = do {
      c <- hGetChar s;
-     loop (fromInt (ord c)) 0 0
+     loop (fromIntegral (ord c)) 0 0
    } 
    where
 	loop n acc shift = 
 	  if (continue_bit_set n) then
 	    do {
 	      c <- hGetChar s;
-	      loop (fromInt(ord c) `andb` 255) 
+	      loop (fromIntegral(ord c) `andb` 255) 
 		    (acc `orb` ((n `andb` 0x7f) `shiftl` shift)) 
 		    (shift+7)
 	    }
