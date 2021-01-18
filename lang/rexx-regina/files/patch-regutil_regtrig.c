--- regutil/regtrig.c.orig	2019-10-06 06:09:42 UTC
+++ regutil/regtrig.c
@@ -124,7 +124,7 @@ static void FormatResult(double res, unsigned long pre
   }
   else
                                        /* format the result          */
-    result->strlength = sprintf( result->strptr, "%.*f", precision, res );
+    result->strlength = sprintf( result->strptr, "%.*f", (int) precision, res );
                                        /* end in a period?           */
   if (result->strptr[result->strlength - 1] == '.')
     result->strlength--;               /* remove the period          */
