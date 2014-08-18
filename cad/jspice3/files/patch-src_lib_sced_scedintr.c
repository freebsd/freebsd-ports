--- src/lib/sced/scedintr.c.orig	2001-05-01 20:54:05.000000000 +0000
+++ src/lib/sced/scedintr.c
@@ -1009,7 +1009,7 @@ char *string;
             strcat(TypeOut,string);
         else
             strcat(TypeOut,"\n");
-        if (strchr(TypeOut,'\n') == NULL) return;
+        if (strchr(TypeOut,'\n') == NULL) return (False);
         if (MoreLine(TypeOut))
             EnableMore(False);
         *TypeOut = '\0';
