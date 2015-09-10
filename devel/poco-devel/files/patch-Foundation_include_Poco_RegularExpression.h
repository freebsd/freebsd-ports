--- Foundation/include/Poco/RegularExpression.h.orig	2014-12-21 23:06:53 UTC
+++ Foundation/include/Poco/RegularExpression.h
@@ -34,7 +34,7 @@
 extern "C"
 {
 	struct real_pcre8_or_16;                 /* declaration; the definition is private  */
-	typedef struct real_pcre8_or_16 pcre;
+	typedef struct real_pcre pcre;
 	struct pcre_extra;
 }
 
