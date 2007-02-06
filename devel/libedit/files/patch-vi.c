--- vi.c.orig	Sun Feb  4 11:49:12 2007
+++ vi.c	Sun Feb  4 11:51:31 2007
@@ -915,16 +915,15 @@
  * NB: posix implies that we should enter insert mode, however
  * this is against historical precedent...
  */
-#ifdef __weak_reference
-extern char *get_alias_text(const char *) __weak_reference(get_alias_text);
-#endif
 protected el_action_t
 /*ARGSUSED*/
 vi_alias(EditLine *el, int c)
 {
-#ifdef __weak_reference
+#ifdef __weak_extern
 	char alias_name[3];
 	char *alias_text;
+	extern char *get_alias_text(const char *);
+	__weak_extern(get_alias_text);
 
 	if (get_alias_text == 0) {
 		return CC_ERROR;
