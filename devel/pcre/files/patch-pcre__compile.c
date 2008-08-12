
$FreeBSD$

--- pcre_compile.c.orig
+++ pcre_compile.c
@@ -4931,7 +4931,7 @@
                (lengthptr == NULL || *lengthptr == 2 + 2*LINK_SIZE))
             {
             cd->external_options = newoptions;
-            options = newoptions;
+            options = *optionsptr = newoptions;
             }
          else
             {
