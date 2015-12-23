--- cmd-line-utils/libedit/vi.c.orig	2015-11-29 19:16:24 UTC
+++ cmd-line-utils/libedit/vi.c
@@ -919,7 +919,7 @@ vi_comment_out(EditLine *el, Int c __att
  * NB: posix implies that we should enter insert mode, however
  * this is against historical precedent...
  */
-#if defined(__weak_reference) && !defined(__FreeBSD__)
+#if defined(__weak_reference) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 __weakref_visible char *my_get_alias_text(const char *)
     __weak_reference(get_alias_text);
 #endif
@@ -928,7 +928,7 @@ protected el_action_t
 vi_alias(EditLine *el __attribute__((__unused__)),
 	 Int c __attribute__((__unused__)))
 {
-#if defined(__weak_reference) && !defined(__FreeBSD__)
+#if defined(__weak_reference) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 	char alias_name[3];
 	char *alias_text;
 
