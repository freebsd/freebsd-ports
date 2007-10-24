--- glib/gregex.c.orig	2007-09-09 18:35:32.000000000 -0400
+++ glib/gregex.c	2007-09-09 18:36:05.000000000 -0400
@@ -164,8 +164,10 @@ match_error (gint errcode)
     case PCRE_ERROR_DFA_RECURSE:
     case PCRE_ERROR_RECURSIONLIMIT:
       return _("recursion limit reached");
+#ifdef PCRE_ERROR_NULLWSLIMIT
     case PCRE_ERROR_NULLWSLIMIT:
       return _("workspace limit for empty substrings reached");
+#endif
     case PCRE_ERROR_BADNEWLINE:
       return _("invalid combination of newline flags");
     default:
