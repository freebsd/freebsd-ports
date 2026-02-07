--- x.c.orig	2014-11-18 19:58:49 UTC
+++ x.c
@@ -445,7 +445,8 @@ int i;
 	i=0;
 	while(*p)
 	{
-		fmap[tolower(*p)]=fmap[*p++]=i++;
+		fmap[tolower(*p)]=fmap[*p]=i++;
+		p++;
 	}
 }
 
