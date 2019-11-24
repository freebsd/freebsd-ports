--- src/eggdrop.h	2011-01-07 06:12:27.000000000 +0100
+++ src/eggdrop.h	2011-01-07 06:14:26.000000000 +0100
@@ -64,7 +64,7 @@
 
 
 /* Language stuff */
-#define LANGDIR  "./language" /* language file directory                   */
+#define LANGDIR  __PREFIX__ "/share/eggdrop/language" /* language file directory */
 #define BASELANG "english"    /* language which always gets loaded before
                                  all other languages. You do not want to
                                  change this.                              */
