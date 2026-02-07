--- src/strip.c.orig	2020-03-30 12:17:45 UTC
+++ src/strip.c
@@ -87,8 +87,8 @@ static const struct argp_option options[] =
     N_("Similar to --reloc-debug-sections, but resolve all trivial relocations between debug sections in place.  No other stripping is performed (operation is not reversable, incompatible with -f, -g, --remove-comment and --remove-section)"), 0 },
   { "remove-comment", OPT_REMOVE_COMMENT, NULL, 0,
     N_("Remove .comment section"), 0 },
-  { "remove-section", 'R', "SECTION", 0, N_("Remove the named section.  SECTION is an extended wildcard pattern.  May be given more than once.  Only non-allocated sections can be removed."), 0 },
-  { "keep-section", OPT_KEEP_SECTION, "SECTION", 0, N_("Keep the named section.  SECTION is an extended wildcard pattern.  May be given more than once."), 0 },
+  { "remove-section", 'R', "SECTION", 0, N_("Remove the named section.  SECTION is an wildcard pattern.  May be given more than once.  Only non-allocated sections can be removed."), 0 },
+  { "keep-section", OPT_KEEP_SECTION, "SECTION", 0, N_("Keep the named section.  SECTION is an wildcard pattern.  May be given more than once."), 0 },
   { "permissive", OPT_PERMISSIVE, NULL, 0,
     N_("Relax a few rules to handle slightly broken ELF files"), 0 },
   { NULL, 0, NULL, 0, NULL, 0 }
@@ -210,7 +210,7 @@ section_name_matches (struct section_pattern *patterns
   struct section_pattern *pattern = patterns;
   while (pattern != NULL)
     {
-      if (fnmatch (pattern->pattern, name, FNM_EXTMATCH) == 0)
+      if (fnmatch (pattern->pattern, name, 0) == 0)
 	return true;
       pattern = pattern->next;
     }
@@ -328,7 +328,7 @@ parse_opt (int key, char *arg, struct argp_state *stat
       break;
 
     case 'R':
-      if (fnmatch (arg, ".comment", FNM_EXTMATCH) == 0)
+      if (fnmatch (arg, ".comment", 0) == 0)
 	remove_comment = true;
       add_pattern (&remove_secs, arg);
       break;
