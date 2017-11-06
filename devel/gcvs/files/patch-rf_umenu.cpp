--- rf/umenu.cpp.orig	2001-09-04 02:29:03 UTC
+++ rf/umenu.cpp
@@ -254,7 +254,7 @@ static void GetMenuTitle(const char *nam
 	// get the accelerator
 	UStr copy(name);
 	char *tmp;
-	if((tmp = strchr(copy, '\t')) != 0L)
+	if((tmp = strchr((char *)copy, '\t')) != 0L)
 	{
 		*tmp++ = '\0';
 		if(strncmp(tmp, CTRLALT_STROKE, strlen(CTRLALT_STROKE)) == 0)
@@ -277,7 +277,7 @@ static void GetMenuTitle(const char *nam
 
 	title = name;
 #ifndef WIN32
-	if((tmp = strchr(title, '&')) != 0L)
+	if((tmp = strchr((char *)title, '&')) != 0L)
 	{
 		size_t l = tmp - (const char *)title;
 		memmove(&title[l], &title[l + 1], title.length() - l);
