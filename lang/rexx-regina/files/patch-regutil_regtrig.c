--- regutil/regtrig.c.orig	2014-06-22 03:53:33 UTC
+++ regutil/regtrig.c
@@ -124,7 +124,7 @@ static void FormatResult(double res, uns
   }
   else
                                        /* format the result          */
-    result->strlength = sprintf( result->strptr, "%.*f", precision, res );
+    result->strlength = sprintf( result->strptr, "%.*f", (int) precision, res );
                                        /* end in a period?           */
   if (result->strptr[result->strlength - 1] == '.')
     result->strlength--;               /* remove the period          */
