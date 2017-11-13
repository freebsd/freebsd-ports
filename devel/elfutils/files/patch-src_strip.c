--- src/strip.c.orig	2017-08-02 12:06:25 UTC
+++ src/strip.c
@@ -85,8 +85,8 @@ static const struct argp_option options[
     N_("Resolve all trivial relocations between debug sections if the removed sections are placed in a debug file (only relevant for ET_REL files, operation is not reversable, needs -f)"), 0 },
   { "remove-comment", OPT_REMOVE_COMMENT, NULL, 0,
     N_("Remove .comment section"), 0 },
-  { "remove-section", 'R', "SECTION", 0, N_("Remove the named section.  SECTION is an extended wildcard pattern.  May be given more than once.  Only non-allocated sections can be removed."), 0 },
-  { "keep-section", OPT_KEEP_SECTION, "SECTION", 0, N_("Keep the named section.  SECTION is an extended wildcard pattern.  May be given more than once."), 0 },
+  { "remove-section", 'R', "SECTION", 0, N_("Remove the named section.  SECTION is an wildcard pattern.  May be given more than once.  Only non-allocated sections can be removed."), 0 },
+  { "keep-section", OPT_KEEP_SECTION, "SECTION", 0, N_("Keep the named section.  SECTION is an wildcard pattern.  May be given more than once."), 0 },
   { "permissive", OPT_PERMISSIVE, NULL, 0,
     N_("Relax a few rules to handle slightly broken ELF files"), 0 },
   { NULL, 0, NULL, 0, NULL, 0 }
@@ -205,7 +205,7 @@ section_name_matches (struct section_pat
   struct section_pattern *pattern = patterns;
   while (pattern != NULL)
     {
-      if (fnmatch (pattern->pattern, name, FNM_EXTMATCH) == 0)
+      if (fnmatch (pattern->pattern, name, 0) == 0)
 	return true;
       pattern = pattern->next;
     }
@@ -313,7 +313,7 @@ parse_opt (int key, char *arg, struct ar
       break;
 
     case 'R':
-      if (fnmatch (arg, ".comment", FNM_EXTMATCH) == 0)
+      if (fnmatch (arg, ".comment", 0) == 0)
 	remove_comment = true;
       add_pattern (&remove_secs, arg);
       break;
