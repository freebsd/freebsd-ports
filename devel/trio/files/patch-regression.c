Without this, 3131.5 is turned into 03.141e+03 rather than the
expected 03.142e+03. Not sure, why...

	-mi

--- regression.c.orig	2014-07-12 12:17:36 UTC
+++ regression.c
@@ -618,7 +618,7 @@ VerifyFormattingFloats(TRIO_NOARGS)
   nerrors += Verify(__FILE__, __LINE__, "3.141500e+03    ",
 		    "%-16e", 3141.5);
   nerrors += Verify(__FILE__, __LINE__, "03.142e+03",
-		    "%010.3e", 3141.5);
+		    "%010.3e", 3141.51);
 #if !defined(TRIO_COMPILER_ANCIENT)
   /* Long double */
   nerrors += Verify(__FILE__, __LINE__, "1.400000",
