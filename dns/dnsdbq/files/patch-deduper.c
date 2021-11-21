commit cbe42ddcb4f4e2b55365cd1d9c13c589957ccb6e
Author: Sascha Steinbiss <satta@users.noreply.github.com>
Date:   Tue Nov 2 19:18:31 2021 +0100

    use 'zu' format string in deduper_dump() (#196)
    
    The use of 'lu' to format a size_t leads to build failures (via -Werror)
    on many architectures.

diff --git deduper.c.orig deduper.c
index 5300aea..a06b13e 100644
--- deduper.c.orig
+++ deduper.c
@@ -87,7 +87,7 @@ void
 deduper_dump(deduper_t me, FILE *out) {
 	for (size_t bucket = 0; bucket < me->buckets; bucket++)
 		if (me->chains[bucket] != NULL) {
-			fprintf(out, "[%lu]", bucket);
+			fprintf(out, "[%zu]", bucket);
 			for (chainlink_t chainlink = me->chains[bucket];
 			     chainlink != NULL;
 			     chainlink = chainlink->next)
