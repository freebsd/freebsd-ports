#
# This patch is obtained from:
#
# http://www.openldap.org/lists/openldap-technical/201212/msg00055.html
#
--- servers/slapd/schema_prep.c.orig	2014-09-18 18:48:49.000000000 -0700
+++ servers/slapd/schema_prep.c	2015-03-31 17:26:23.439844478 -0700
@@ -908,6 +908,7 @@
 			"DESC 'RFC4519: common supertype of name attributes' "
 			"EQUALITY caseIgnoreMatch "
 			"SUBSTR caseIgnoreSubstringsMatch "
+			"ORDERING caseIgnoreOrderingMatch "
 			"SYNTAX 1.3.6.1.4.1.1466.115.121.1.15{32768} )",
 		NULL, SLAP_AT_ABSTRACT,
 		NULL, NULL,
