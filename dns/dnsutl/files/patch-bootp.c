--- common/srrf/bootp.c.orig	Wed Oct 22 01:53:06 2003
+++ common/srrf/bootp.c	Wed Oct 22 01:53:44 2003
@@ -81,7 +81,7 @@
 	check_list_of_one_or_more_machines(rp);
 	srrf_lex_error
 	(
-"you may not specify ``bootp ds'' explicitly,
+"you may not specify ``bootp ds'' explicitly, \
 it is generated from the ``in ns'' fields"
 	);
 }
@@ -99,7 +99,7 @@
 	check_list_of_one_or_more_machines(rp);
 	srrf_lex_error
 	(
-"you may not specify ``bootp ha'' explicitly,
+"you may not specify ``bootp ha'' explicitly, \
 it is generated from the ``ether a'' fields"
 	);
 }
@@ -397,7 +397,7 @@
 	check_list_of_one_or_more_machines(rp);
 	srrf_lex_error
 	(
-"you may not specify \"ip\" explicitly,
+"you may not specify \"ip\" explicitly, \
 it is generated from the ``in a'' fields"
 	);
 }
