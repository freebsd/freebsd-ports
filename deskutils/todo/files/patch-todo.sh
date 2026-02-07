--- todo.sh.orig	2020-08-12 04:44:46 UTC
+++ todo.sh
@@ -622,7 +622,7 @@ TODOTXT_DEFAULT_ACTION=${TODOTXT_DEFAULT_ACTION:-}
 TODOTXT_SORT_COMMAND=${TODOTXT_SORT_COMMAND:-env LC_COLLATE=C sort -f -k2}
 TODOTXT_DISABLE_FILTER=${TODOTXT_DISABLE_FILTER:-}
 TODOTXT_FINAL_FILTER=${TODOTXT_FINAL_FILTER:-cat}
-TODOTXT_GLOBAL_CFG_FILE=${TODOTXT_GLOBAL_CFG_FILE:-/etc/todo/config}
+TODOTXT_GLOBAL_CFG_FILE=${TODOTXT_GLOBAL_CFG_FILE:-%%PREFIX%%/etc/todo.cfg}
 TODOTXT_SIGIL_BEFORE_PATTERN=${TODOTXT_SIGIL_BEFORE_PATTERN:-}	# Allow any other non-whitespace entity before +project and @context; should be an optional match; example: \(w:\)\{0,1\} to allow w:@context.
 TODOTXT_SIGIL_VALID_PATTERN=${TODOTXT_SIGIL_VALID_PATTERN:-.*}	# Limit the valid characters (from the default any non-whitespace sequence) for +project and @context; example: [a-zA-Z]\{3,\} to only allow alphabetic ones that are at least three characters long.
 TODOTXT_SIGIL_AFTER_PATTERN=${TODOTXT_SIGIL_AFTER_PATTERN:-}	# Allow any other non-whitespace entity after +project and @context; should be an optional match; example: )\{0,1\} to allow (with the corresponding TODOTXT_SIGIL_BEFORE_PATTERN) enclosing in parentheses.
