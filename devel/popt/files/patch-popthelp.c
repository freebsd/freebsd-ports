--- ./popthelp.c.orig	Wed Apr  4 12:25:01 2007
+++ ./popthelp.c	Wed Apr  4 12:25:14 2007
@@ -67,7 +67,7 @@
 /**
  * @param table		option(s)
  */
-/*@observer@*/ /*@null@*/ static const char *const
+/*@observer@*/ /*@null@*/ static const char *
 getTableTranslationDomain(/*@null@*/ const struct poptOption *table)
 	/*@*/
 {
@@ -85,7 +85,7 @@
  * @param opt		option(s)
  * @param translation_domain	translation domain
  */
-/*@observer@*/ /*@null@*/ static const char *const
+/*@observer@*/ /*@null@*/ static const char *
 getArgDescrip(const struct poptOption * opt,
 		/*@-paramuse@*/ /* FIX: i18n macros disabled with lclint */
 		/*@null@*/ const char * translation_domain)
