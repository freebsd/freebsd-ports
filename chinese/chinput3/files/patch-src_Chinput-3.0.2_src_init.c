--- src/Chinput-3.0.2/src/init.c.orig	2008-03-25 11:18:01.000000000 -0700
+++ src/Chinput-3.0.2/src/init.c	2008-03-25 12:23:41.000000000 -0700
@@ -94,6 +94,13 @@
         load_font(&font_info, font_latin);
 }
 
+static int is_locale_supported(char *locale) {
+  char *setlocale_string = setlocale(LC_ALL, locale);
+  int success = (setlocale_string != NULL && strcmp(setlocale_string, locale)==0 && XSupportsLocale());
+  if (!success && locale[0] != 0 && setlocale_string != NULL && setlocale_string[0] != 0) {
+    fprintf(stderr, "Error : requested locale '%s' not supported\n");
+  }
+}
 
 void HZinitServerGC(void)
 {
@@ -103,12 +110,9 @@
 	char fontname[256];
 
 	//create font set
-	if(strcmp(setlocale(LC_ALL, gb18030locale), gb18030locale) || 	
-		!XSupportsLocale()){
-		if(strcmp(setlocale(LC_ALL, gbklocale), gbklocale) ||
-			!XSupportsLocale()){
-			if(strcmp(setlocale(LC_ALL, gblocale), gblocale) ||
-				!XSupportsLocale()){
+	if(!is_locale_supported(gb18030locale)){
+		if(!is_locale_supported(gbklocale)){
+			if(!is_locale_supported(gblocale)){
 				fprintf(stderr, "Error : Chinese Locale not supported!\n");
 				exit(1);
 			}
