
$FreeBSD$

--- src/header_stuff.c	2001/04/09 09:21:33	1.1
+++ src/header_stuff.c	2001/04/09 09:30:32
@@ -168,13 +168,15 @@
 const gchar * language_in_english(const gchar *lang)
 {
 	gint c;
-	for(c=0;languages[c].name!=NULL;c++)
-	{
-		if(!strcmp(_(languages[c].name), lang))
+
+	if (lang != NULL)
+		for(c=0;languages[c].name!=NULL;c++)
 		{
-			return languages[c].name;
+			if(!strcmp(_(languages[c].name), lang))
+			{
+				return languages[c].name;
+			}
 		}
-	}
 	return lang;
 }		
 /*
